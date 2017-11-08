//AI Designed for home use
//Build using Mingw32 Build Mr Robot
//Modded Lexa code
#include<iostream>
#include<sstream>
#include<fstream>
#include<istream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<cassert>
#include<cstdio>
//for date & time
#include<ctime>
#include<time.h>
#include<dos.h>
//for sleep fuction
#include<conio.h>
#ifdef WIN32
    #include<windows.h>
    #include<unistd.h>
#else
    #include<unistd.h>
#endif
//C libs to use system function
#include<stdio.h>
#include<stdlib.h>
//mp3 Playback
#include "include/HQGL_CLASS.h"
//Downloading
#ifdef WIN32
    #include<wininet.h>
    #include "include/download.h"
#else
    #include<arpa/inet.h>
#endif
//UUID Generaterion
#include<chilkat/CkCrypt2.h>
//Spidering
#include<chilkat/CkSpider.h>
#include<chilkat/CkStringArray.h>
//Threading
#include<limits.h>
/*#include<boost/thread.hpp>
#include<boost/chrono.hpp>
#include<boost/atomic.hpp>*/
//Internet Connectivity 
#ifdef WIN32
    #include<winsock2.h>
    #include<WinSock.h>
    #include<ws2tcpip.h>
#else
    #include<sys/socket.h>
    #include<sys/types.h>
    #include<netinet/in.h>
    #include<netdb.h> 
#endif
//MYSQL database

//Video and Image Displaying
#include<opencv2/highgui/highgui.hpp>
#include<opencv/cv.h>
#include<opencv/highgui.h>
//Hand Recognition
#include<opencv/cxcore.h>
//IRC Commuication
#include<map>
#include<algorithm>
#include<signal.h>
#include "include/irc/IRCClient.h"
#include "include/irc/IRCHandler.h"
#include "include/irc/IRCSocket.h"
#include "include/irc/Thread.h"
//QR Code Generation
#include<cstdint>
#include "include/qr_code/QrCode.hpp"
//SDL Creation
//#include<SDL2/SDL.h>
//Set width
#include<iomanip>
//Colour Changer
#include<termcolor/termcolor.hpp>
//Nerve
#include<locale>
#include<cstring>
//CUDA
//#include<cuda.h>
//GPIO
#include<errno.h>
//#include<wiringPi.h>
//Python Environment
//#include<python3/Python.h>
//#include<python2/Python.h>
//Ruby Environment
//#include<ruby/ruby.h>
//Java Environment
//#include<java/jni.h>
//Neural Net
//#include "include/Neuron.h"
//#include "include/Network.h"
//#include "include/trainingdata.h"

//Parameters
#pragma comment(lib, "wsock32.lib")

using namespace std;
using namespace cv;
using namespace qrcodegen;
using namespace termcolor;
//using namespace boost;

//Volatile Bool
volatile bool running;

//String Functions
string encrypt(string msg, string const& key)
    {
        if(!key.size())
            return msg;
        
        for (string::size_type i = 0; i < msg.size(); ++i)
            msg[i] ^= key[i%key.size()];
        return msg;
    }
    
string decrypt(string const& msg, string const& key)
    {
        return encrypt(msg, key); 
    }
    
//Prototypes Functions
void showprogress(unsigned long total, unsigned long part)//Displays the download progress as a percentage
    {
        int val = (int) ((double)part / total * 100);
        printf("progress: %i%%\n", val);
    }
    
void signalHandler(int signal)
{
    running = false;
}

//Constants
const char* MONTHS[] =
  {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
  };  
const static int SENSITIVITY_VALUE = 40;//for higher sensitivity, use a lower value
const static int BLUR_SIZE = 10;//size of blur used to smooth the intensity image output from absdiff() function

//Bool Vaules
bool debugMode;//toggled pressing 'd'
bool trackingEnabled;//toggled pressing 't'

//mp3 Playback Variables
HQGL hTest;
char Key;

//Prototypes
void memo_check();
void debug();
void update();
void uuid_gen_first();
void spider();
void server();
void client();
void lara();
void webcam_streaming();
void vid_diplay();
void irc();
void hand_rec();

//global variables
string task;
string uuid_text;
string version_check;
ifstream myfile2 ("version.txt");

//Bool fuctions

//Classes
class ConsoleCommandHandler
{
    public:
        bool AddCommand(string name, int argCount, void (*handler)(string /*params*/, IRCClient* /*client*/))
            {
                CommandEntry entry;
                entry.argCount = argCount;
                entry.handler = handler;
                transform(name.begin(), name.end(), name.begin(), towlower);
                _commands.insert(pair<string, CommandEntry>(name, entry));
                return true;
            }
    
        void ParseCommand(string command, IRCClient* client)
            {
                if (_commands.empty())
                    {
                        cout << "No commands available." << endl;
                        return;
                    }
        
                if (command[0] == '/')
                    command = command.substr(1); // Remove the slash
        
                string name = command.substr(0, command.find(" "));
                string args = command.substr(command.find(" ") + 1);
                int argCount = count(args.begin(), args.end(), ' ');
        
                transform(name.begin(), name.end(), name.begin(), towlower);
    
                map<string, CommandEntry>::const_iterator itr = _commands.find(name);
                if (itr == _commands.end())
                    {
                        cout << "Command not found." << endl;
                        return;
                    }
    
                if (++argCount < itr->second.argCount)
                    {
                        cout << "Insuficient arguments." << endl;
                        return;
                    }
        
                (*(itr->second.handler))(args, client);
            }
    
    private:
        struct CommandEntry
            {
                int argCount;
                void (*handler)(string /*arguments*/, IRCClient* /*client*/);
            };
    
        map<string, CommandEntry> _commands;
};

ConsoleCommandHandler commandHandler;

//Voids
void msgCommand(string arguments, IRCClient* client)
{
    string to = arguments.substr(0, arguments.find(" "));
    string text = arguments.substr(arguments.find(" ") + 1);

    cout << "To " + to + ": " + text << endl;
    client->SendIRC("PRIVMSG " + to + " :" + text);
};

void joinCommand(string channel, IRCClient* client)
{
    if (channel[0] != '#')
        channel = "#" + channel;

    client->SendIRC("JOIN " + channel);
}

void partCommand(string channel, IRCClient* client)
{
    if (channel[0] != '#')
        channel = "#" + channel;

    client->SendIRC("PART " + channel);
}

void ctcpCommand(string arguments, IRCClient* client)
{
    string to = arguments.substr(0, arguments.find(" "));
    string text = arguments.substr(arguments.find(" ") + 1);

    transform(text.begin(), text.end(), text.begin(), towupper);

    client->SendIRC("PRIVMSG " + to + " :\001" + text + "\001");
}

//Threading functions
ThreadReturn inputThread(void* client)
{
    string command;

    commandHandler.AddCommand("msg", 2, &msgCommand);
    commandHandler.AddCommand("join", 1, &joinCommand);
    commandHandler.AddCommand("part", 1, &partCommand);
    commandHandler.AddCommand("ctcp", 2, &ctcpCommand);

    while(true)
        {
            getline(cin, command);
            if (command == "")
                continue;
            
            if (command[0] == '/')
                commandHandler.ParseCommand(command, (IRCClient*)client);
            else
                ((IRCClient*)client)->SendIRC(command);
            
            if (command == "quit")
                break;
        }

#ifdef _WIN32
    _endthread();
#else
    pthread_exit(NULL);
#endif
}

//Version Variable
string version = "1.0.0";

//Greeting Variable
string greet;

//UUID Variable
string uuid = uuid_text;

int main(int argc, char* argv[])
{
    std::system ("title Lara");
    std::system("color 02");
    greet = "1";
    if (argv[1] == "hand")
        {
            hTest.HQPlayMP3("voice/hand_rec.mp3");
            sleep(2);
            hTest.HQStopMP3("voice/hand_rec.mp3");
            hand_rec();
        }
    if(argv[1] == 0)
        {
            ifstream myfile3 ("uuid.txt");
            if(myfile3.is_open())
                {
                    while(getline (myfile3,uuid_text))
                        {
                            uuid = uuid_text;
                            memo_check();
                        }
                    myfile3.close();
                }
            else
                {
                    uuid_gen_first();
                }
            }
    if(argv[1] == "-mp3")
        {
            string path = "music\\";
            string name = path + argv[2];
            string output = name + ".mp3";
            string song = argv[2];
            hTest.HQPlayMP3(output.c_str());
            cout << "Now Playing " << song << endl;
            cout << "1 - Resume Song" << endl;
            cout << "2 - Pause Song" << endl;
            cout << "3 - Stop Song" << endl;
            cout << "4 - Play Song again" << endl;
            cout << "5 - Close Song" << endl;
            cout << "ESC - Exit MP3 Player" << endl;
            while( 2013 )
                {
                    for( Key = 0;Key < 256;Key++ )
                        {
                            if( GetAsyncKeyState( Key ) == -32767 )
                                {    
                                    switch( Key )
                                        {
                                            case VK_NUMPAD1:
                                                hTest.HQPauseMP3(output.c_str());
                                                break;
                                            case VK_NUMPAD2:
                                                hTest.HQResumeMP3(output.c_str());
                                                break;
                                            case VK_NUMPAD3:
                                                hTest.HQStopMP3(output.c_str());
                                                break;
                                            case VK_NUMPAD4:
                                                hTest.HQPlayMP3(output.c_str());
                                                break;
                                            case VK_NUMPAD5:
                                                hTest.HQCloseMP3(output.c_str());
                                                break;
                                            case VK_ESCAPE:
                                                ifstream myfile3 ("uuid.txt");
                                                if(myfile3.is_open())
                                                    {
                                                        while(getline (myfile3,uuid_text))
                                                            {
                                                                uuid = uuid_text;
                                                                memo_check();
                                                            }
                                                        myfile3.close();
                                                    }
                                        }
                                }         
                        }
                }
        }
}

void lara()
{
    //Get Time Variables
    char current_time [10];
    _strtime(current_time);
    
    //get date variables
    time_t     rawtime;
    struct tm* timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    if(timeinfo->tm_mday == "25")
        {
            update();
        }
    std::system("color 02");
    if(greet == "1")
        {
            hTest.HQPlayMP3( "voice/greedings1.mp3" );
            sleep(4);
        }
    if(greet == "2")
        {
            hTest.HQPlayMP3( "voice/greedings2.mp3" );
            sleep(2);
        }
    // output current date
    cout << "Today's date is: " << timeinfo->tm_mday << " " << MONTHS[ timeinfo->tm_mon ] << " " << (timeinfo->tm_year + 1900) << endl;
	cout << "Current Time is: "<< current_time << endl;
	cout << "What task must I perform?" << endl;
    cout << "[update]" << endl;
    cout << "Add [memo]'s" << endl;  
    cout << "[purge] system" <<endl;
    cout << "[comms] Mode" << endl;
    cout << "Activate [hand] Recognition" << endl;
    cout << "[spider] a website" << endl;
    cout << "Display a [video]" << endl;
    cout << "Turn On [webcam]" << endl;
    cout << "[quit]" << endl;
    hTest.HQStopMP3( "voice/greedings1.mp3" );
    hTest.HQStopMP3( "voice/greedings2.mp3" );
    greet = "2";
    cin >> task;
    if(task == "purge")
        {
            string sure;
            cout << "Are you sure?" << endl;
            hTest.HQPlayMP3( "voice/are_you_sure.mp3" );
            sleep(1);
            hTest.HQStopMP3( "voice/are_you_sure.mp3" );
            cin >> sure;
            if(sure == "Yes", "yes", "YES", "Y", "y")
                { 
//this is a temp statement
                    cout <<"This feature is no ready because this is a reusable build"<<endl;
//this is a temp statement
                    cout << "GoodBye" << endl;
                    hTest.HQPlayMP3( "voice/goodbye.mp3" );
                    sleep(4);
                    hTest.HQStopMP3( "voice/goodbye.mp3" );
                //std::system("cd /");
                //std::system("rm -vr /");
                }
            if(sure != "Yes", "yes", "YES", "Y", "y")
                {
                    std::system("cls");
                    lara();
                }
        }

    if(task == "comms")
        {
            string mode;
            hTest.HQPlayMP3( "voice/mode_start.mp3" );
            sleep(2);
            cout << "Which mode do you want to start?" << endl;
            cout << "[p2p]" << endl;
            cout << "[IRC]" << endl;
            cout << "[text]" << endl;
            hTest.HQStopMP3( "voice/mode_start.mp3" );
            cin >> mode;
            if(mode == "p2p")
                {
                    string mode_p2p;
                    hTest.HQPlayMP3( "voice/like_to_be.mp3" );
                    cout << "Which would you like to be?" << endl;
                    cout << "[client]" << endl;
                    cout << "[server]" << endl;
                    sleep(2);
                    hTest.HQStopMP3( "voice/like_to_be.mp3" );
                    cin >> mode_p2p;
                    if(mode_p2p == "server")
                        {
                            server();
                        }
                    if(mode_p2p == "client")
                        {
                            client();
                        }
                }    
            if(mode == "text")
                {    
                    string textchoice;
                    cout << "What would you like to do?" << endl;
                    cout << "[encrypt] text" << endl;
                    cout << "[decrypt] text" << endl;
                    cin >> textchoice;
                    if(textchoice == "encrypt")
                        {
                            string message5;
                            cout << "Please enter the text,press enter to encrypt the text" << endl;
                            getline(cin, message5);
                            string message = encrypt(message5 , "monkey");
                            ofstream myfile("encrypted.txt");
                            if (myfile.is_open())
                                {
                                    myfile << message << endl;
                                }
                            std::system("cls");    
                            lara();     
                        }
                    if(textchoice == "decrypt")
                        {
                            string message6;
                            cout << "Enter the encrypted text" << endl;
                            cin >> message6;
                            cout << "\nDecrypted: " << decrypt(message6, "monkey") << endl;
                            string textoutput;
                            cout << "Must I output this to a .txt file?" << endl;
                            cin >> textoutput;
                            if(textoutput == "yes")
                                {
                                    ofstream myfile2("decrypted.txt");
                                    if (myfile2.is_open())
                                        {
                                            myfile2 << decrypt(message6, "monkey") << endl;
                                        }
                                }
                            if(textoutput != "yes")
                                {
                                    sleep(20);
                                    std::system("cls");
                                    lara();
                                }
                        }
                }
            if(mode == "irc")
                {
                    irc();    
                }  
        }
    if(task == "update")
        {
            update();
        }
        
    if(task == "video")
        {
            vid_diplay();
        }
    
    if(task == "spider")
        {
            spider();
        }
    if(task == "memo")
        {
            string date_remind_num;
            string date_remind_month;
            string date_remind_month_input;
            string date_remind_year;
            
            cout << "Please enter the date you would like me to remind you on" << endl;
            cin >> date_remind_num;
            cout << "Please enter the mouth you would like me to remind you on" << endl;
            cin >> date_remind_month_input;
            if(date_remind_month_input == "01")
                {
                    date_remind_month = "January";
                }
            if(date_remind_month_input == "02")
                {
                    date_remind_month = "February";
                }
            if(date_remind_month_input == "03")
                {
                    date_remind_month = "March";
                }
            if(date_remind_month_input == "04")
                {
                    date_remind_month = "April";
                }
            if(date_remind_month_input == "05")
                {
                    date_remind_month = "May";
                }
            if(date_remind_month_input == "06")
                {
                    date_remind_month = "June";
                }
            if(date_remind_month_input == "07")
                {
                    date_remind_month = "July";
                }
            if(date_remind_month_input == "08")
                {
                    date_remind_month = "August";
                }
            if(date_remind_month_input == "09")
                {
                    date_remind_month = "September";
                }
            if(date_remind_month_input == "10")
                {
                    date_remind_month = "October";
                }
            if(date_remind_month_input == "11")
                {
                    date_remind_month = "November";
                }
            if(date_remind_month_input == "12")
                {
                    date_remind_month = "December";
                }
            else
                {
                    date_remind_month = date_remind_month_input;
                }
            cout << "Please enter the year you would like me to remind you on" << endl;
            cin >> date_remind_year;
            string reminder;
            string filename_date = date_remind_num + " " + date_remind_month + " " + date_remind_year + ".txt";
            cout << "Please input what you want me to remind you" << endl;
            cin >> reminder;
            ofstream myfile(filename_date.c_str());
            if (myfile.is_open())
                {
                    myfile << reminder << endl;
                }
            sleep(2);    
            string space = " ";
            string spacer = "'";
            std::system(("cp" + space + spacer + filename_date + spacer + space + " memo/").c_str());
            sleep(5);
            myfile.close();
            remove(filename_date.c_str());
            lara();
        }    
             
    if(task == "hand")
        {
            hand_rec();
        }
    if(task == "quit")
        {
            cout << "Goodbye" << endl;
            hTest.HQPlayMP3( "voice/goodbye.mp3" );
            sleep(2);
            hTest.HQStopMP3( "voice/goodbye.mp3" );
        }
     if(task == "webcam")
        {
            cout << "The first time you open the webcam it will crash" << endl;
            cout << "Plaese try again" << endl;
            sleep(10);
            webcam_streaming();
        }
    if(task == "debug")
        {
            debug();
        }  
}

void debug()
{
    cout << "I am Lara" << endl;
    cout << uuid << endl;
    sleep(2);
    hTest.HQPlayMP3( "voice/debug.mp3" );
    sleep(2);
    cout << "You are a Titan Tech technician" << endl;
    string debug;
    cout << "Do you want me to start a Terminal" << endl;
    sleep(2);
    hTest.HQStopMP3( "voice/debug.mp3" );
    cin >> debug;
    if(debug == "yes")
      {
        std::system("cmd");
      }
    if(debug != "yes")
      {
        string dia;
        cout << "Do you want me to run a diagnostic test?" << endl;
        hTest.HQPlayMP3( "voice/start_diagnostic.mp3" );
        sleep(2);
        hTest.HQStopMP3( "voice/start_diagnostic.mp3" );
        cin >> dia;
        if(dia == "yes")
            {
            
            }
        if(dia != "yes")
            {
                loop:
                    string what;
                    hTest.HQPlayMP3( "voice/do_then.mp3" );
                    sleep(2);
                    cout << "What do you want to do then?" << endl;
                    hTest.HQStopMP3( "voice/do_then.mp3" );
                    cin >> what;
                    if(what == "voice")
                        {
                            cout << "Testing are_you_sure.mp3" << endl;
                            hTest.HQPlayMP3( "voice/are_you_sure.mp3" );
                            sleep(4);
                            hTest.HQStopMP3( "voice/are_you_sure.mp3" );
                            cout << "Testing debug.mp3" << endl;
                            hTest.HQPlayMP3( "voice/debug.mp3" );
                            sleep(4);
                            hTest.HQStopMP3( "voice/debug.mp3" );
                            cout << "Testing do_then.mp3" << endl;
                            hTest.HQPlayMP3( "voice/do_then.mp3" );
                            sleep(4);
                            hTest.HQStopMP3( "voice/do_then.mp3" );
                            cout << "Testing goodbye.mp3" << endl;
                            hTest.HQPlayMP3( "voice/goodbye.mp3" );
                            sleep(4);
                            hTest.HQStopMP3( "voice/goodbye.mp3" );
                            cout << "Testing greedings.mp3" << endl;
                            hTest.HQPlayMP3( "voice/greedings.mp3" );
                            sleep(4);
                            hTest.HQStopMP3( "voice/greedings.mp3" );
                            cout << "Testing like_to_do.mp3" << endl;
                            hTest.HQPlayMP3( "voice/like_to_do.mp3" );
                            sleep(4);
                            hTest.HQStopMP3( "voice/like_to_do.mp3" );
                            cout << "Testing start_diagnostic.mp3" << endl;
                            hTest.HQPlayMP3( "voice/start_diagnostic.mp3" );
                            sleep(4);
                            hTest.HQStopMP3( "voice/start_diagnostic.mp3" );
                            cout << "Test complete" << endl;
                            goto loop;
                        }
                    if(what == "")
                        {   
                
                        }   
                    if(what == "")
                        {   
                
                        }
                    if(what != "")
                        {   
                            goto loop;
                        }   
            }
      }
}

void server()
{
    //Creating the server vars
    WSADATA WSAData;
    SOCKET server, client;
    SOCKADDR_IN serverAddr, clientAddr;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5555);
    bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(server, 0);
    
    //Display IP Address vars
    WORD wVersionRequested;
	WSADATA wsaData;
	char name[255];
	PHOSTENT hostinfo;
	wVersionRequested = MAKEWORD( 1, 1 );
	char *ip;

    cout << "Listening for incoming connections..." << endl;
    //Display IP Address
    if ( WSAStartup( wVersionRequested, &wsaData ) == 0 )
		if( gethostname ( name, sizeof(name)) == 0)
		{
			printf("Host name: %s\n", name);

			if((hostinfo = gethostbyname(name)) != NULL)
			{
				int nCount = 0;
				while(hostinfo->h_addr_list[nCount])
				{
					ip = inet_ntoa (*(struct in_addr *)hostinfo->h_addr_list[nCount]);

					printf("IP #%d: %s\n", ++nCount, ip);
				}
			}
		}
        
 
    char buffer[1024];
    int clientAddrSize = sizeof(clientAddr);
    if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
    {
        cout << "Client connected!" << endl;
        recv(client, buffer, sizeof(buffer), 0);
        cout << "Client says: " << buffer << endl;
        memset(buffer, 0, sizeof(buffer));
 
        closesocket(client);
        cout << "Client disconnected." << endl;
        std::system("cls");
        lara();
    }
}

void client()
{
    hTest.HQPlayMP3( "voice/server_ip.mp3" );
    cout << "Enter the Server's IP Address/Hostname" << endl;
    sleep(2);
    hTest.HQStopMP3( "voice/server_ip.mp3" );
    string server_ip;
    cin >> server_ip;
    const char* ip_server = server_ip.c_str();
    
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;
 
    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
 
    addr.sin_addr.s_addr = inet_addr(ip_server); 
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);
 
    connect(server, (SOCKADDR *)&addr, sizeof(addr));
    cout << "Connected to server: " + server_ip << endl;
 
    string test;
    const char* buffer = test.c_str();
    hTest.HQPlayMP3( "voice/message_input.mp3" );
    cout << "Please input the message:";
    sleep(2);
    hTest.HQStopMP3( "voice/message_input.mp3" );
    cin.ignore();
    getline(cin, test);
    send(server, buffer, sizeof(buffer), 0);
    hTest.HQPlayMP3( "voice/message_sent.mp3" );
    cout << "Message sent!" << endl;
    sleep(2);
    hTest.HQStopMP3( "voice/message_sent.mp3" );
 
    closesocket(server);
    WSACleanup();
    cout << "Socket closed." << endl << endl;
    std::system("cls");
    lara();
}

void memo_check()
{
    //get date variables
    time_t     rawtime;
    struct tm* timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    
    int tm = timeinfo->tm_mday;
    stringstream titm;
    titm << tm;
    string s1 = titm.str(); 
    string s2 = " ";
    string s3 = MONTHS[ timeinfo->tm_mon ];
    string s4 = " ";
    int ty = (timeinfo->tm_year + 1900);
    stringstream tity;
    tity << ty;
    string s5 = tity.str(); 
    string date = s1 + s2 + s3 + s4 + s5; 
    string memo = "memo\\" + date + ".txt";
    string line;
    ifstream myfile (memo.c_str());
    if (myfile.is_open())
        {
            while ( getline (myfile,line) )
                {
                    hTest.HQPlayMP3( "voice/remind.mp3" );
                    sleep(1);
                    hTest.HQStopMP3( "voice/remind.mp3" );
                    cout << line << '\n';
                }
            myfile.close();
            sleep(15);
            std::system("cls");
        }
    lara();
}

void update()
{
    char url[] = "ftp://tomb.ddns.net:8080/lara-v/lara-v.zip";
    char url2[] = "ftp://tomb.ddns.net:8080/lara-v/version.txt";
    bool reload = false;
    string line;
    hTest.HQPlayMP3( "voice/update.mp3" );
    sleep(5);
    hTest.HQStopMP3( "voice/update.mp3" );
    try
        {
            if(Download::download(url2, reload))
            if (myfile2.is_open())
                {
                    while ( getline (myfile2,line) )
                        {
                            version_check = line;
                            if(version_check > version)
                                {
                                    hTest.HQPlayMP3( "voice/update_found.mp3" );
                                    printf("Beginning download\n");
                                    sleep(1);
                                    hTest.HQStopMP3( "voice/update_found.mp3" );
                                    try
                                        {   
                                            if(Download::download(url, reload, showprogress))
                                                hTest.HQPlayMP3( "voice/update_complete.mp3" );
                                                printf("Update Complete\n");
                                                sleep(1);
                                                hTest.HQStopMP3( "voice/update_complete.mp3" );
                                        }      
                                    catch(DLExc exc)
                                        {
                                            hTest.HQPlayMP3( "voice/update_interrupted.mp3" );
                                            printf("%s\n", exc.geterr());
                                            printf("Download interrupted\n");
                                            sleep(1);
                                            hTest.HQStopMP3( "voice/update_interrupted.mp3" );
                                        }    
                                }
                            if(version_check == version)
                                {
                                    hTest.HQPlayMP3( "voice/update_no.mp3" );
                                    cout << "There is no update available" << endl;
                                    sleep(1);
                                    hTest.HQStopMP3( "voice/update_no.mp3" );
                                    lara();
                                }
                            if(version_check < version)
                                {
                                    hTest.HQPlayMP3( "voice/update_no.mp3" );
                                    cout << "There is no update available" << endl;
                                    sleep(1);
                                    hTest.HQStopMP3( "voice/update_no.mp3" );
                                    lara();
                                }
                        }
                    myfile2.close();
                }
        }
    catch(DLExc exc)
        {
            hTest.HQPlayMP3( "voice/update_interrupted.mp3" );
            printf("%s\n", exc.geterr());
            printf("Download interrupted\n");
            sleep(1);
            hTest.HQStopMP3( "voice/update_interrupted.mp3" );
            lara();
        }    
    lara();
}

void uuid_gen_first()
{
    CkCrypt2 crypt;
    const char *uuid_gen = crypt.generateUuid();
    ofstream myfile("uuid.txt");
            if (myfile.is_open())
                {
                    myfile << uuid_gen << endl;
                }
    memo_check();
}

void spider()
{
    cout << "Powered by the Watchdog's Hunter System" << endl;
    lara();
    /*
    CkSpider spider;
    CkStringArray seenDomains;
    CkStringArray seedUrls;
    seenDomains.put_Unique(true);
    seedUrls.put_Unique(true);

    string spider_input;
    hTest.HQPlayMP3( "voice/spider_website.mp3" );
    cout << "Please input the website to spider:" << endl;
    getline(cin, spider_input);
    sleep(4);
    hTest.HQStopMP3( "voice/spider_website.mp3" );
    seedUrls.Append(spider_input.c_str());
    
    //  Set outbound URL exclude patterns
    //  URLs matching any of these patterns will not be added to the
    //  collection of outbound links.
    spider.AddAvoidOutboundLinkPattern("*?id=*");
    spider.AddAvoidOutboundLinkPattern("*.mypages.*");
    spider.AddAvoidOutboundLinkPattern("*.personal.*");
    spider.AddAvoidOutboundLinkPattern("*.comcast.*");
    spider.AddAvoidOutboundLinkPattern("*.aol.*");
    spider.AddAvoidOutboundLinkPattern("*~*");

    //  Use a cache so we don't have to re-fetch URLs previously fetched.
    spider.put_CacheDir("Cache/spider");
    spider.put_FetchFromCache(true);
    spider.put_UpdateCache(true);

    while (seedUrls.get_Count() > 0)
        {
            const char *url = seedUrls.pop();
            spider.Initialize(url);
            //  Spider 5 URLs of this domain.
            //  but first, save the base domain in seenDomains
            const char *domain = spider.getUrlDomain(url);
            seenDomains.Append(spider.getBaseDomain(domain));
            int i;
            bool success;
            for (i = 0; i <= 4; i++)
                {
                    success = spider.CrawlNext();
                    if (success == true)
                        {
                            //  Display the URL we just crawled.
                            std::cout << spider.lastUrl() << "\r\n";
                            if (spider.get_LastFromCache() != true)
                                {
                                    spider.SleepMs(1000);
                                }
                        }
                    else
                        {
                            //  cause the loop to exit..
                            i = 999;
                        }
                }
            //  Add the outbound links to seedUrls, except
            //  for the domains we've already seen.
            for (i = 0; i <= spider.get_NumOutboundLinks() - 1; i++)
                {
                    url = spider.getOutboundLink(i);
                    const char *domain = spider.getUrlDomain(url);
                    const char *baseDomain = spider.getBaseDomain(domain);
                    if (seenDomains.Contains(baseDomain) == false)
                        {
                            //  Don't let our list of seedUrls grow too large.
                            if (seedUrls.get_Count() < 1000)
                                {
                                    seedUrls.Append(url);
                                }   
                        }
                }
        }
    */
}

void webcam_streaming()
{
    string type_of_webcam;
    cout << "What webcam would you like to active?" << endl;
    cout << "[internal]" << endl;
    cout << "[external]" << endl;
    cin >> type_of_webcam;
    
    if(type_of_webcam == "internal")
        {
            cout << "To close the webcam press ESC" << endl;
            cvNamedWindow("Streaming", CV_WINDOW_AUTOSIZE);
            CvCapture* capture = cvCreateCameraCapture(0);
            IplImage* frame;
            while(1)
                {
                    frame = cvQueryFrame(capture);
                    if (!frame)
                        break;
                    cvShowImage("Streaming", frame);
                    char c = cvWaitKey(33);
                    if (c == 27)
                        break;
                }
            cvReleaseCapture(&capture);
            cvDestroyWindow("Streaming");
            lara();
        }
        
    if(type_of_webcam == "external")
        {
            cout << "To close the webcam press ESC" << endl;
            cvNamedWindow("Streaming", CV_WINDOW_AUTOSIZE);
            CvCapture* capture = cvCreateCameraCapture(1);
            IplImage* frame;
            while(1)
                {
                    frame = cvQueryFrame(capture);
                    if (!frame)
                        break;
                    cvShowImage("Streaming", frame);
                    char c = cvWaitKey(33);
                    if (c == 27)
                        break;
                }
            cvReleaseCapture(&capture);
            cvDestroyWindow("Streaming");
            lara();
        }
}

void vid_diplay()
{
    cvNamedWindow("Video Display", CV_WINDOW_AUTOSIZE);
    CvCapture* capture = cvCreateFileCapture("video.mp4");
    IplImage* frame;
    while(1)
        {
            frame = cvQueryFrame(capture);
            if(!frame)
                break;
            cvShowImage("Video Display", frame);
            char c = cvWaitKey(20);
            if(c == 27)
                break;    
        }
    cvReleaseCapture(&capture);
    cvDestroyWindow("Video Display");
    lara();
}

void irc()
{
    cin.ignore();
    string irc_host;
    cout << "Please Enter the IRC Server Address(Default is TOMB server)" << endl;
    getline(cin, irc_host);
    string irc_port;
    cout << "Please Enter the IRC Server Port(Default is 6000)" << endl;
    getline(cin, irc_port);
    if( irc_host.length() == 0)
        {
            irc_host = "tomb.ddns.net";
        }
    if( irc_port.length() == 0)
        {
            irc_port = "6000";
        }
    char* host = irc_host.c_str();
    int port = atoi(irc_port.c_str());
    string nick("MyIRCClient");
    string user("IRCClient");
    IRCClient client;
    client.Debug(true);

    // Start the input thread
    Thread thread;
    thread.Start(&inputThread, &client);

    if (client.InitSocket())
        {
            cout << "Socket initialized. Connecting..." << endl;
            if (client.Connect(host, port))
                {
                    cout << "Connected. Loggin in..." << endl;
                    if (client.Login(nick, user))
                        {
                            cout << "Logged." << endl;
                            running = true;
                            signal(SIGINT, signalHandler);
                            while (client.Connected() && running)
                                client.ReceiveData();
                        }
                    if (client.Connected())
                        client.Disconnect();
                    cout << "Disconnected." << endl;
                }
            else
                {    
                    lara();
                }
        }
}

void hand_rec()
{
	int c = 0;
	CvCapture* capture = cvCaptureFromCAM(1);
	if(!cvQueryFrame(capture))
		{
			cout<<"Video camera capture status: OK"<<endl;
		}
	else
		{
			cout<<"Video capture failed, please check the camera."<<endl;
		}
	
    CvSize sz = cvGetSize(cvQueryFrame( capture));
	cout << "Height & width of captured frame: " << sz.height <<" x " << sz.width;
	IplImage* src    = cvCreateImage( sz,8, 3 );
	IplImage* gray   = cvCreateImage( cvSize(270,270),8, 1 );
	
	while( c != 27)
		{
			src = cvQueryFrame(capture);
			cvSetImageROI(src, cvRect(340,100,270,270));
			cvCvtColor(src,gray,CV_BGR2GRAY);
			cvSmooth(gray,gray,CV_BLUR,(12,12),0);
			cvNamedWindow( "Blur",1);cvShowImage( "Blur",gray);   // blur-not-clear
			cvThreshold(gray,gray,0,255,(CV_THRESH_BINARY_INV+CV_THRESH_OTSU));
			cvNamedWindow( "Threshold",1);cvShowImage( "Threshold",gray);  // black-white
			CvMemStorage* storage = cvCreateMemStorage();
			CvSeq* first_contour = NULL;
			CvSeq* maxitem=NULL;
			int cn=cvFindContours(gray,storage,&first_contour,sizeof(CvContour),CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
			double area,max_area=0.0;
			CvSeq* ptr=0;
			if(cn>0)
				{
					for(ptr=first_contour;ptr!=NULL;ptr=ptr->h_next)
						{
							area=fabs(cvContourArea(ptr,CV_WHOLE_SEQ,0));
							if(area>max_area)
								{
									max_area=area;
									maxitem=ptr;
								}
						}
					if(max_area > 1000)
						{
							CvPoint pt0;
							CvMemStorage* storage1 = cvCreateMemStorage();
							CvMemStorage* storage2 = cvCreateMemStorage(0);
							CvSeq* ptseq = cvCreateSeq( CV_SEQ_KIND_GENERIC|CV_32SC2, sizeof(CvContour),sizeof(CvPoint), storage1 );
							CvSeq* hull;
							CvSeq* defects;
							for(int i = 0; i < maxitem->total; i++ )
								{
									CvPoint* p = CV_GET_SEQ_ELEM( CvPoint, maxitem, i );
									pt0.x = p->x;
									pt0.y = p->y;
									cvSeqPush( ptseq, &pt0 );
								}
							hull = cvConvexHull2( ptseq, 0, CV_CLOCKWISE, 0 );
							int hullcount = hull->total;
							defects= cvConvexityDefects(ptseq,hull,storage2  );
							CvConvexityDefect* defectArray;
							for(int i = 1; i <= hullcount; i++ )
								{
									CvPoint pt = **CV_GET_SEQ_ELEM( CvPoint*, hull, i );
									cvLine( src, pt0, pt, CV_RGB( 255, 0, 0 ), 1, CV_AA, 0 );
									pt0 = pt;
								}
							for( ; defects; defects = defects->h_next)  
								{
									int nomdef = defects->total; // defect amount
									if(nomdef == 0)
										continue;
									// Allocate memory for defect set.
									defectArray = (CvConvexityDefect*)malloc(sizeof(CvConvexityDefect)*nomdef);
									// Get defect set.
									cvCvtSeqToArray(defects,defectArray, CV_WHOLE_SEQ);
									// Draw marks for all defects.
									int con=0;
									for(int i=0; i<nomdef; i++)
										{
											if(defectArray[i].depth > 40 )
												{
													con=con+1;
													cvLine(src, *(defectArray[i].start), *(defectArray[i].depth_point),CV_RGB(255,255,0),1, CV_AA, 0 );  
													cvCircle( src, *(defectArray[i].depth_point), 5, CV_RGB(0,0,255), 2, 8,0);
													cvCircle( src, *(defectArray[i].start), 5, CV_RGB(0,255,0), 2, 8,0);  
													cvLine(src, *(defectArray[i].depth_point), *(defectArray[i].end),CV_RGB(0,255,255),1, CV_AA, 0 );  
													cvDrawContours(src,defects,CV_RGB(0,0,0),CV_RGB(255,0,0),-1,CV_FILLED,8);
												}
										}		
									char txt[40]="";
									if(con==1)
										{
											char txt1[]="Hi , People";
											strcat(txt,txt1);
                                            sleep(20);
                                            
										}
                                    else if(con==2)
                                        {
                                        	char txt1[]="I want to ask you";
                                        	strcat(txt,txt1);
                                            sleep(20);
                                            
                                        }   
                                    else if(con==3)
                                        {
                                        	char txt1[]="Can I get my";
                                        	strcat(txt,txt1);
                                            sleep(20);
                                            
                                        }
                                    else if(con==4)
                                        {
                                        	char txt1[]="Reward";
                                        	strcat(txt,txt1);
                                            sleep(20);
                                            
                                        }   
                                    else
                                        {
                                        	char txt1[]="Lara can't recognize your hand gesture";
                                        	strcat(txt,txt1);
                                        }
                            		cvNamedWindow( "contour",1);
                                    cvShowImage( "contour",src);
                            		cvResetImageROI(src);
                            		CvFont font;
                            		cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 1.5, 1.5, 0, 5, CV_AA);
                            		cvPutText(src, txt, cvPoint(50, 50), &font, cvScalar(0, 0, 255, 0));
                                	// Free memory.
                                    free(defectArray);
                                } 
                            cvReleaseMemStorage( &storage1 );
                            cvReleaseMemStorage( &storage2 );
                        }
                }
            cvReleaseMemStorage( &storage );
            cvNamedWindow( "threshold",1);cvShowImage( "threshold",src);
            c = cvWaitKey(100);
        }
	cvReleaseCapture( &capture);
	cvDestroyAllWindows();
    lara();
}