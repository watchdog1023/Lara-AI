//AI Designed for home use
//Built using Mingw32 Build Mr Robot
//Modded Lexa code
#include<iostream>
#include<sstream>
#include<fstream>
#include<istream>
#include<string>
#include<vector>
#include<cmath>
#include<math.h>
#include<cassert>
//for date & time
#include<ctime>
#ifdef WIN32
    #include<dos.h>
#endif
//for sleep fuction
#include<conio.h>
#ifdef WIN32
    #include<windows.h>
    #include<unistd.h>
#else
    #include<unistd.h>
#endif
//C libs to use system function
#include<cstdio>
#include<cstdlib>
//mp3 Playback
#include "include/MP3.h"
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
//Twitter
#include<chilkat/CkHttp.h>
#include<chilkat/CkHttpRequest.h>
#include<chilkat/CkHttpResponse.h>
#include<chilkat/CkHashtable.h>
#include<chilkat/CkStringBuilder.h>
#include<chilkat/CkSocket.h>
#include<chilkat/CkTask.h>
#include<chilkat/CkJsonObject.h>
#include<chilkat/CkFileAccess.h>
#include<chilkat/CkOAuth1.h>
//Paypal
#include<chilkat/CkRest.h>
#include<chilkat/CkDateTime.h>
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
//QR code Scanner
#include<zbar.h>
#include<opencv2/imgproc/imgproc.hpp>
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
#include<cerrno>
#ifdef UNIX
    #include<wiringPi.h>
#endif
//Python Environment
#include<python3/Python.h>
//#include<python2/Python.h>
//Ruby Environment
//#include<ruby/ruby.h>
//Java Environment
//#include<java/jni.h>
//Encryption Headers
#include<crypto++/osrng.h>
#include<crypto++/modes.h>
#include<crypto++/aes.h>
#include<crypto++/filters.h>
//Neural Net
//ISO/ANSI C/C++
//#include "include/Neuron.h"
//#include "include/Network.h"
//#include "include/trainingdata.h"
//Tensorflow
#ifdef UNIX
    #include<tensorflow/cc/client/client_session.h>
    #include<tensorflow/cc/ops/standard_ops.h>
    #include<tensorflow/core/framework/tensor.h>
#else
//OpenNN
    #include<opennn/opennn.h>
#endif

//Parameters
#pragma comment(lib, "wsock32.lib")

using namespace std;
using namespace cv;
using namespace qrcodegen;
using namespace termcolor;
using namespace mp3;
using namespace CryptoPP;
//using namespace boost;
#ifdef UNIX
	using namespace tensorflow;
	using namespace tensorflow::ops;
#else
	using namespace OpenNN;
#endif
using namespace zbar;

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

#ifdef WIN32  
	string ExePath()
		{
    			char buffer[MAX_PATH];
    			GetModuleFileName( NULL, buffer, MAX_PATH );
    			string::size_type pos = string( buffer ).find_last_of( "\\/" );
    			return string( buffer ).substr( 0, pos);
		}
#endif

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
char Key;

//Prototypes
//C/C+
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
void vid_diplay_holo();
void init_start();
void get_twitter_token();
void get_paypal_token();
void validate_paypal_token();
void tweet();
void tweet_with_image();
void tweet_with_image_multi();
void qr_scanner();
//Python2

//Python3
void py_tensrflow_lstm();
void py_spider();

//global variables
string task;
string uuid_text;
string version_check;
ifstream myfile2 ("version.txt");
int holovideo;

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

//Class Variables
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
string version = "5.0.0";

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
            PlayMP3("voice/hand_rec.mp3");
            sleep(2);
            StopMP3("voice/hand_rec.mp3");
            hand_rec();
        }
    if(argc != 3)
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
                    init_start();
                }
            }
    if(argv[1] == "-mp3")
        {
            string path = "music\\";
            string name = path + argv[2];
            string output = name + ".mp3";
            string song = argv[2];
            PlayMP3(output.c_str());
            cout << "Now Playing " << song << endl;
            cout << "1 - Resume Song" << endl;
            cout << "2 - Pause Song" << endl;
            cout << "3 - Stop Song" << endl;
            cout << "4 - Play Song again" << endl;
            cout << "5 - Close Song" << endl;
            cout << "ESC - Exit MP3 Player" << endl;
            while(2013)
                {
                    for(Key = 0;Key < 256;Key++)
                        {
                            if(GetAsyncKeyState(Key) == -32767)
                                {    
                                    switch(Key)
                                        {
                                            case VK_NUMPAD1:
                                                PauseMP3(output.c_str());
                                                break;
                                            case VK_NUMPAD2:
                                                ResumeMP3(output.c_str());
                                                break;
                                            case VK_NUMPAD3:
                                                StopMP3(output.c_str());
                                                break;
                                            case VK_NUMPAD4:
                                                PlayMP3(output.c_str());
                                                break;
                                            case VK_NUMPAD5:
                                                CloseMP3(output.c_str());
                                                break;
                                            case VK_ESCAPE:
                                                ifstream myfile3 ("uuid.txt");
                                                if(myfile3.is_open())
                                                    {
                                                        while(getline(myfile3,uuid_text))
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
            PlayMP3( "voice/greedings1.mp3" );
            #ifdef WIN32
                sleep(4);
            #else
                usleep(4);
            #endif
        }
    if(greet == "2")
        {
            PlayMP3( "voice/greedings2.mp3" );
            #ifdef WIN32
                sleep(2);
            #else
                usleep(2);
            #endif
        }
    //output current date
    cout << "Today's date is: " << timeinfo->tm_mday << " " << MONTHS[ timeinfo->tm_mon ] << " " << (timeinfo->tm_year + 1900) << endl;
	//output current time
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
    StopMP3( "voice/greedings1.mp3" );
    StopMP3( "voice/greedings2.mp3" );
    greet = "2";
    cin >> task;
    if(task == "purge")
        {
            string sure;
            cout << "Are you sure?" << endl;
            PlayMP3( "voice/are_you_sure.mp3" );
            #ifdef WIN32
                sleep(1);
            #else
                usleep(1);
            #endif
            StopMP3( "voice/are_you_sure.mp3" );
            cin >> sure;
            if(sure == "Yes", "yes", "YES", "Y", "y")
                { 
//this is a temp statement
                    cout <<"This feature is no ready because this is a reusable build"<<endl;
//this is a temp statement
                    cout << "GoodBye" << endl;
                    PlayMP3( "voice/goodbye.mp3" );
                    #ifdef WIN32
                        sleep(4);
                    #else
                        usleep(4);
                    #endif
                    StopMP3( "voice/goodbye.mp3" );
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
            PlayMP3( "voice/mode_start.mp3" );
            #ifdef WIN32
                sleep(2);
            #else
                usleep(2);
            #endif
            cout << "Which mode do you want to start?" << endl;
            cout << "[p2p]" << endl;
            cout << "[IRC]" << endl;
            cout << "[text]" << endl;
            StopMP3( "voice/mode_start.mp3" );
            cin >> mode;
            if(mode == "p2p")
                {
                    string mode_p2p;
                    PlayMP3( "voice/like_to_be.mp3" );
                    cout << "Which would you like to be?" << endl;
                    cout << "[client]" << endl;
                    cout << "[server]" << endl;
                    #ifdef WIN32
                        sleep(2);
                    #else
                        usleep(2);
                    #endif
                    StopMP3( "voice/like_to_be.mp3" );
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
                                    #ifdef WIN32
                                        sleep(20);
                                    #else
                                        usleep(20);
                                    #endif
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
            #ifdef WIN32   
                sleep(2);
            #else
                usleep(2);
            #endif
            string space = " ";
            string spacer = "'";
            std::system(("cp" + space + spacer + filename_date + spacer + space + " memo/").c_str());
            #ifdef WIN32
                sleep(5);
            #else
                usleep(5);
            #endif
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
            PlayMP3( "voice/goodbye.mp3" );
            #ifdef WIN32
                sleep(2);
            #else
                usleep(2);
            #endif
            StopMP3( "voice/goodbye.mp3" );
        }
     if(task == "webcam")
        {
            cout << "The first time you open the webcam it will crash" << endl;
            cout << "Plaese try again" << endl;
            #ifdef WIN32
                sleep(10);
            #else
                usleep(10);
            #endif
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
    #ifdef WIN32
        sleep(2);
    #else
        usleep(2);
    #endif
    PlayMP3( "voice/debug.mp3" );
    #ifdef WIN32
        sleep(2);
    #else
        usleep(2);
    #endif
    cout << "You are a Titan Tech technician" << endl;
    string debug;
    cout << "Do you want me to start a Terminal" << endl;
    #ifdef WIN32
        sleep(2);
    #else
        usleep(2);
    #endif
    StopMP3( "voice/debug.mp3" );
    cin >> debug;
    if(debug == "yes")
      {
        std::system("cmd");
      }
    if(debug != "yes")
      {
        string dia;
        cout << "Do you want me to run a diagnostic test?" << endl;
        PlayMP3( "voice/start_diagnostic.mp3" );
        #ifdef WIN32
            sleep(2);
        #else
            usleep(2);
        #endif
        StopMP3( "voice/start_diagnostic.mp3" );
        cin >> dia;
        if(dia == "yes")
            {
            
            }
        if(dia != "yes")
            {
                loop:
                    string what;
                    PlayMP3( "voice/do_then.mp3" );
                    #ifdef WIN32
                        sleep(2);
                    #else
                        usleep(2);
                    #endif
                    cout << "What do you want to do then?" << endl;
                    StopMP3( "voice/do_then.mp3" );
                    cin >> what;
                    if(what == "voice")
                        {
                            cout << "Testing are_you_sure.mp3" << endl;
                            PlayMP3( "voice/are_you_sure.mp3" );
                            #ifdef WIN32
                                sleep(4);
                            #else
                                usleep(4);
                            #endif
                            StopMP3( "voice/are_you_sure.mp3" );
                            cout << "Testing debug.mp3" << endl;
                            PlayMP3( "voice/debug.mp3" );
                            #ifdef WIN32
                                sleep(4);
                            #else
                                usleep(4);
                            #endif
                            StopMP3( "voice/debug.mp3" );
                            cout << "Testing do_then.mp3" << endl;
                            PlayMP3( "voice/do_then.mp3" );
                            #ifdef WIN32
                                sleep(4);
                            #else
                                usleep(4);
                            #endif
                            StopMP3( "voice/do_then.mp3" );
                            cout << "Testing goodbye.mp3" << endl;
                            PlayMP3( "voice/goodbye.mp3" );
                            #ifdef WIN32
                                sleep(4);
                            #else
                                usleep(4);
                            #endif
                            StopMP3( "voice/goodbye.mp3" );
                            cout << "Testing greedings.mp3" << endl;
                            PlayMP3( "voice/greedings.mp3" );
                            #ifdef WIN32
                                sleep(4);
                            #else
                                usleep(4);
                            #endif
                            StopMP3( "voice/greedings.mp3" );
                            cout << "Testing like_to_do.mp3" << endl;
                            PlayMP3( "voice/like_to_do.mp3" );
                            #ifdef WIN32
                                sleep(4);
                            #else
                                usleep(4);
                            #endif
                            StopMP3( "voice/like_to_do.mp3" );
                            cout << "Testing start_diagnostic.mp3" << endl;
                            PlayMP3( "voice/start_diagnostic.mp3" );
                            #ifdef WIN32
                                sleep(4);
                            #else
                                usleep(4);
                            #endif
                            StopMP3( "voice/start_diagnostic.mp3" );
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
    PlayMP3( "voice/server_ip.mp3" );
    cout << "Enter the Server's IP Address/Hostname" << endl;
    sleep(2);
    StopMP3( "voice/server_ip.mp3" );
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
    PlayMP3( "voice/message_input.mp3" );
    cout << "Please input the message:";
    #ifdef WIN32
        sleep(2);
    #else
        usleep(2);
    #endif
    StopMP3( "voice/message_input.mp3" );
    cin.ignore();
    getline(cin, test);
    send(server, buffer, sizeof(buffer), 0);
    PlayMP3( "voice/message_sent.mp3" );
    cout << "Message sent!" << endl;
    #ifdef WIN32
        sleep(2);
    #else
        usleep(2);
    #endif
    StopMP3( "voice/message_sent.mp3" );
 
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
                    PlayMP3( "voice/remind.mp3" );
                    #ifdef WIN32
                        sleep(1);
                    #else
                        usleep(1);
                    #endif
                    StopMP3( "voice/remind.mp3" );
                    cout << line << '\n';
                }
            myfile.close();
            #ifdef WIN32
                sleep(15);
            #else
                usleep(15);
            #endif
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
    PlayMP3( "voice/update.mp3" );
    #ifdef WIN32
        sleep(5);
    #else
        usleep(5);
    #endif
    StopMP3( "voice/update.mp3" );
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
                                    PlayMP3( "voice/update_found.mp3" );
                                    printf("Beginning download\n");
                                    #ifdef WIN32
                                        sleep(1);
                                    #else
                                        usleep(1);
                                    #endif
                                    StopMP3( "voice/update_found.mp3" );
                                    try
                                        {   
                                            if(Download::download(url, reload, showprogress))
                                                PlayMP3( "voice/update_complete.mp3" );
                                                printf("Update Complete\n");
                                                #ifdef WIN32
                                                    sleep(1);
                                                #else
                                                    usleep(1);
                                                #endif
                                                StopMP3( "voice/update_complete.mp3" );
                                        }      
                                    catch(DLExc exc)
                                        {
                                            PlayMP3( "voice/update_interrupted.mp3" );
                                            printf("%s\n", exc.geterr());
                                            printf("Download interrupted\n");
                                            #ifdef WIN32
                                                sleep(1);
                                            #else
                                                usleep(1);
                                            #endif
                                            StopMP3( "voice/update_interrupted.mp3" );
                                        }    
                                }
                            if(version_check == version)
                                {
                                    PlayMP3( "voice/update_no.mp3" );
                                    cout << "There is no update available" << endl;
                                    #ifdef WIN32
                                        sleep(1);
                                    #else
                                        usleep(1);
                                    #endif
                                    StopMP3( "voice/update_no.mp3" );
                                    lara();
                                }
                            if(version_check < version)
                                {
                                    PlayMP3( "voice/update_no.mp3" );
                                    cout << "There is no update available" << endl;
                                    #ifdef WIN32
                                        sleep(1);
                                    #else
                                        usleep(1);
                                    #endif
                                    StopMP3( "voice/update_no.mp3" );
                                    lara();
                                }
                        }
                    myfile2.close();
                }
        }
    catch(DLExc exc)
        {
            PlayMP3( "voice/update_interrupted.mp3" );
            printf("%s\n", exc.geterr());
            printf("Download interrupted\n");
            #ifdef WIN32
                sleep(1);
            #else
                usleep(1);
            #endif
            StopMP3( "voice/update_interrupted.mp3" );
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

void init_start()
{
    #ifdef WIN32
        //Windows Set PATH
        string setpath = "setx path '%path%;" + ExePath() + "'";
        system(setpath.c_str());
    #else
        //Bash Set PATH
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        string setpath = "export PATH=$PATH:" + cwd;
        string setpathper = "echo '" + setpath + "'  >> ~/.bash_profile"
        system(setpath.c_str());
        system(setpathper.c_str());
    #endif
    uuid_gen_first();
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
    PlayMP3( "voice/spider_website.mp3" );
    cout << "Please input the website to spider:" << endl;
    getline(cin, spider_input);
    sleep(4);
    StopMP3( "voice/spider_website.mp3" );
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

void vid_diplay_holo()
{
    string holovid;
    int vid;
    if(holovideo == "1")
        {
            holovid = "holo/.mp4";
            vid = "1";
        }
    int holosleep;
    cvNamedWindow("Holo Display", CV_WINDOW_AUTOSIZE);
    CvCapture* capture = cvCreateFileCapture(holovid.c_str());
    IplImage* frame;
    while(1)
        {
            frame = cvQueryFrame(capture);
            if(!frame)
                break;
            cvShowImage("Holo Display", frame);
            char c;
            //Setting video sleep variable
            if(vid == "1")
                {
                    #ifdef WIN32
                        holosleep = "1";
                        sleep(holosleep);
                    #else
                        holosleep = "1";
                        usleep(holosleep);
                    #endif
                    c = 27;
                }
            if(c == 27)
                break;
        }
    cvReleaseCapture(&capture);
    cvDestroyWindow("Holo Display");
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
/*
void py_tensorflow_lstm()
{
    //Calling Interperter
    Py_Initialize();
    //Python Script body
    PyRun_SimpleString( "from __future__ import absolute_import, division, print_function\n"
                        "import os\n"
                        "from six import moves\n"
                        "import ssl\n"
                        "import tflearn\n"
                        "from tflearn.data_utils import *\n"
                        "path = 'US_Cities.txt'\n"
                        "if not os.path.isfile(path):\n"
                        "context = ssl._create_unverified_context()\n"
                        "moves.urllib.request.urlretrieve('https://raw.githubusercontent.com/tflearn/tflearn.github.io/master/resources/US_Cities.txt', path, context=context)\n"
                        "maxlen = 20\n"
                        "X, Y, char_idx = \\n"
                        "textfile_to_semi_redundant_sequences(path, seq_maxlen=maxlen, redun_step=3)\n"
                        "g = tflearn.input_data(shape=[None, maxlen, len(char_idx)])\n"
                        "g = tflearn.lstm(g, 512, return_seq=True)\n"
                        "g = tflearn.dropout(g, 0.5)\n"
                        "g = tflearn.lstm(g, 512)\n"
                        "g = tflearn.dropout(g, 0.5)\n"
                        "g = tflearn.fully_connected(g, len(char_idx), activation='softmax')\n"
                        "g = tflearn.regression(g, optimizer='adam', loss='categorical_crossentropy', learning_rate=0.001)\n"
                        "m = tflearn.SequenceGenerator(g, dictionary=char_idx, seq_maxlen=maxlen, clip_gradients=5.0, checkpoint_path='model_us_cities')\n"
                        "#training\n"
                        "for i in range(40):\n"
                        "seed = random_sequence_from_textfile(path, maxlen)\n"
                        "m.fit(X, Y, validation_set=0.1, batch_size=128, n_epoch=1, run_id='us_cities')\n"
                        "print('-- TESTING...')\n"
                        "print('-- Test with temperature of 1.2 --')\n"
                        "print(m.generate(30, temperature=1.2, seq_seed=seed))\n"
                        "print('-- Test with temperature of 1.0 --')\n"
                        "print(m.generate(30, temperature=1.0, seq_seed=seed))\n"
                        "print('-- Test with temperature of 0.5 --')\n"
                        "print(m.generate(30, temperature=0.5, seq_seed=seed))\n"
                      );
    //Killing Interperter
    Py_Finalize();
}*/
/*
void py_spider()
{
    //Calling Interperter
    Py_Initialize();
    PyRun_SimpleString( "from html.parser import HTMLParser\n" 
                        "from urllib.request import urlopen  \n"
                        "from urllib import parse\n"
                        "\n"
                        "class LinkParser(HTMLParser):\n"
                        "def handle_starttag(self, tag, attrs):\n"
                        "if tag =='a':\n"
                        "for (key, value) in attrs:\n"
                        "if key == 'href':\n"
                        "newUrl = parse.urljoin(self.baseUrl, value)\n"
                        "self.links = self.links + [newUrl]\n"
                        "def getLinks(self, url):\n"
                        "self.links = []\n"
                        "self.baseUrl = url\n"
                        "response = urlopen(url)\n"
                        "if response.getheader('Content-Type')=='text/html':\n"
                        "htmlBytes = response.read()\n"
                        "htmlString = htmlBytes.decode("utf-8")\n"
                        "self.feed(htmlString)\n"
                        "return htmlString, self.links\n"
                        "else:\n"
                        "return "",[]\n"
                        "def spider(url, word, maxPages):\n"  
                        "pagesToVisit = [url]\n"
                        "numberVisited = 0\n"
                        "foundWord = False\n"
                        "while numberVisited < maxPages and pagesToVisit != [] and not foundWord:\n"
                        "numberVisited = numberVisited +1\n"
                        "url = pagesToVisit[0]\n"
                        "pagesToVisit = pagesToVisit[1:]\n"
                        "try:\n"
                        "print(numberVisited, "Visiting:", url)\n"
                        "parser = LinkParser()\n"
                        "data, links = parser.getLinks(url)\n"
                        "if data.find(word)>-1:\n"
                        "foundWord = True\n"
                        "pagesToVisit = pagesToVisit + links\n"
                        "print(' **Success!**')\n"
                        "except:\n"
                        "print(' **Failed!**')\n"
                        "if foundWord:\n"
                        "print('The word', word, 'was found at', url)\n"
                        "else:\n"
                        "print('Word never found')\n"
                      );
    //Killing Interperter
    Py_Finalize();
}*/

void get_twitter_token()
{
    const char *consumerKey = "TWITTER_CONSUMER_KEY";
    const char *consumerSecret = "TWITTER_CONSUMER_SECRET";
    const char *requestTokenUrl = "https://api.twitter.com/oauth/request_token";
    const char *authorizeUrl = "https://api.twitter.com/oauth/authorize";
    const char *accessTokenUrl = "https://api.twitter.com/oauth/access_token";
    //The port number is picked at random. It's some unused port that won't likely conflict with anything else..
    const char *callbackUrl = "http://localhost:3017/";
    int callbackLocalPort = 3017;
    //The 1st step in 3-legged OAuth1.0a is to send a POST to the request token URL to obtain an OAuth Request Token
    CkHttp http;
    bool success;
    http.put_OAuth1(true);
    http.put_OAuthConsumerKey(consumerKey);
    http.put_OAuthConsumerSecret(consumerSecret);
    http.put_OAuthCallback(callbackUrl);
    CkHttpRequest req;
    CkHttpResponse *resp = http.PostUrlEncoded(requestTokenUrl,req);
    if (http.get_LastMethodSuccess() != true)
        {
            cout << http.lastErrorText() << "\r\n";
            return;
        }
    cout << resp->bodyStr() << "\r\n";
    
    CkHashtable hashTab;
    hashTab.AddQueryParams(resp->bodyStr());
    const char *requestToken = hashTab.lookupStr("oauth_token");
    const char *requestTokenSecret = hashTab.lookupStr("oauth_token_secret");
    http.put_OAuthTokenSecret(requestTokenSecret);
    delete resp;
    
    cout << "oauth_token = " << requestToken << "\r\n";
    cout << "oauth_token_secret = " << requestTokenSecret << "\r\n";
    //  The next step is to form a URL to send to the authorizeUrl
    //  This is an HTTP GET that we load into a popup browser.
    CkStringBuilder sbUrlForBrowser;
    sbUrlForBrowser.Append(authorizeUrl);
    sbUrlForBrowser.Append("?oauth_token=");
    sbUrlForBrowser.Append(requestToken);
    const char *urlForBrowser = sbUrlForBrowser.getAsString();
    CkSocket listenSock;
    int backLog = 5;
    success = listenSock.BindAndListen(callbackLocalPort,backLog);
    if (success != true)
        {
            cout << listenSock.lastErrorText() << "\r\n";
            return;
        }
    //Wait for the browser's connection in a background thread.
    //Wait a max of 60 seconds before giving up.
    int maxWaitMs = 60000;
    CkTask *task = listenSock.AcceptNextConnectionAsync(maxWaitMs);
    task->Run();
    //At this point, your application should load the URL in a browser.
    //The Twitter account owner would interactively accept or deny the authorization request.
    //Add the code to load the url in a web browser here...
    //Wait for the listenSock's task to complete.
    success = task->Wait(maxWaitMs);
    if (!success || (task->get_StatusInt() != 7) || (task->get_TaskSuccess() != true))
        {
            if (!success)
                {
                    cout << task->lastErrorText() << "\r\n";
                }
            else
                {
                    cout << task->status() << "\r\n";
                    cout << task->resultErrorText() << "\r\n";
                }
            delete task;
            return;
        }
    //  We no longer need the listen socket...
    //  Stop listening on port 3017.
    listenSock.Close(10);
    //  First get the connected socket.
    CkSocket sock;
    sock.LoadTaskResult(*task);
    delete task;
    //  Read the start line of the request..
    const char *startLine = sock.receiveUntilMatch("\r\n");
    if (sock.get_LastMethodSuccess() != true)
        {
            cout << sock.lastErrorText() << "\r\n";
            return;
        }
    //  Read the request header.
    const char *requestHeader = sock.receiveUntilMatch("\r\n\r\n");
    if (sock.get_LastMethodSuccess() != true)
        {
            cout << sock.lastErrorText() << "\r\n";
            return;
        }
    //  The browser SHOULD be sending us a GET request, and therefore there is no body to the request.
    //  Once the request header is received, we have all of it.
    //  We can now send our HTTP response.
    CkStringBuilder sbResponseHtml;
    sbResponseHtml.Append("<html><body><p>Chilkat thanks you!</b></body</html>");
    CkStringBuilder sbResponse;
    sbResponse.Append("HTTP/1.1 200 OK\r\n");
    sbResponse.Append("Content-Length: ");
    sbResponse.AppendInt(sbResponseHtml.get_Length());
    sbResponse.Append("\r\n");
    sbResponse.Append("Content-Type: text/html\r\n");
    sbResponse.Append("\r\n");
    sbResponse.AppendSb(sbResponseHtml);
    sock.SendString(sbResponse.getAsString());
    sock.Close(50);
    CkStringBuilder sbStartLine;
    sbStartLine.Append(startLine);
    int numReplacements = sbStartLine.Replace("GET /?","");
    numReplacements = sbStartLine.Replace(" HTTP/1.1","");
    sbStartLine.Trim();
    cout << "startline: " << sbStartLine.getAsString() << "\r\n";
    hashTab.Clear();
    hashTab.AddQueryParams(sbStartLine.getAsString());
    requestToken = hashTab.lookupStr("oauth_token");
    const char *authVerifier = hashTab.lookupStr("oauth_verifier");
    
    //  Finally , we must exchange the OAuth Request Token for an OAuth Access Token.
    http.put_OAuthToken(requestToken);
    http.put_OAuthVerifier(authVerifier);
    resp = http.PostUrlEncoded(accessTokenUrl,req);
    if (http.get_LastMethodSuccess() != true)
        {
            cout << http.lastErrorText() << "\r\n";
            return;
        }
    //  Make sure a successful response was received.
    if (resp->get_StatusCode() != 200)
        {
            cout << resp->statusLine() << "\r\n";
            cout << resp->header() << "\r\n";
            cout << resp->bodyStr() << "\r\n";
            return;
        }
    cout << resp->bodyStr() << "\r\n";
    hashTab.Clear();
    hashTab.AddQueryParams(resp->bodyStr());
    const char *accessToken = hashTab.lookupStr("oauth_token");
    const char *accessTokenSecret = hashTab.lookupStr("oauth_token_secret");
    const char *userId = hashTab.lookupStr("user_id");
    const char *screenName = hashTab.lookupStr("screen_name");
    delete resp;
    //  The access token + secret is what should be saved and used for
    //  subsequent REST API calls.
    cout << "Access Token = " << accessToken << "\r\n";
    cout << "Access Token Secret = " << accessTokenSecret << "\r\n";
    cout << "user_id = " << userId << "\r\n";
    cout << "screen_name  = " << screenName << "\r\n";
    //  Save this access token for future calls.
    CkJsonObject json;
    json.AppendString("oauth_token",accessToken);
    json.AppendString("oauth_token_secret",accessTokenSecret);
    json.AppendString("user_id",userId);
    json.AppendString("screen_name",screenName);
    CkFileAccess fac;
    fac.WriteEntireTextFile("qa_data/tokens/twitter.json",json.emit(),"utf-8",false);
    cout << "Success." << "\r\n";
}

void get_paypal_token()
{
    //  Note: Requires Chilkat v9.5.0.64 or greater.
    //  This requires the Chilkat API to have been previously unlocked.

    CkRest rest;
    bool bAutoReconnect = true;
    bool success = rest.Connect("api.sandbox.paypal.com",443,true,bAutoReconnect);
    if (success != true)
        {
            cout << rest.lastErrorText() << "\r\n";
            return;
        }

    rest.AddHeader("Accept","application/json");
    rest.AddHeader("Accept-Language","en_US");
    rest.SetAuthBasic("PAYPAL_REST_API_CLIENT_ID","PAYPAL_REST_API_SECRET");
    rest.AddQueryParam("grant_type","client_credentials");

    const char *responseStr = rest.fullRequestFormUrlEncoded("POST","/v1/oauth2/token");
    if (rest.get_LastMethodSuccess() != true)
        {
            cout << rest.lastErrorText() << "\r\n";
            return;
        }

    CkJsonObject json;
    json.Load(responseStr);
    json.put_EmitCompact(false);

    if (rest.get_ResponseStatusCode() != 200)
        {
            cout << json.emit() << "\r\n";
            cout << "Failed." << "\r\n";
            return;
        }

    CkDateTime dateTime;
    bool bLocalTime = false;
    int dtNow = dateTime.GetAsUnixTime(bLocalTime);
    json.AppendInt("tokenCreateTimeUtc",dtNow);

    //  Examine the access token and save to a file.
    cout << "Access Token: " << json.stringOf("access_token") << "\r\n";
    cout << "Full JSON Response:" << "\r\n";
    cout << json.emit() << "\r\n";

    CkStringBuilder sbResponse;
    sbResponse.Append(json.emit());
    bool bEmitBom = false;
    sbResponse.WriteFile("qa_data/tokens/paypal.json","utf-8",bEmitBom);
    validate_paypal_token();
}

void validate_paypal_token()
{
    //  Note: Requires Chilkat v9.5.0.64 or greater.
    //  This requires the Chilkat API to have been previously unlocked.

    CkJsonObject json;
    bool success = json.LoadFile("qa_data/tokens/paypal.json");
    if (success != true)
        {
            cout << "Failed to load access key json file." << "\r\n";
            return;
        }
    //  Get the current date/time.
    CkDateTime dateTime;
    bool bLocalTime = false;
    int dtNow = dateTime.GetAsUnixTime(bLocalTime);
    //  Get the access token create date/time
    int dtCreate = json.IntOf("tokenCreateTimeUtc");
    //  Find out how many seconds have elapsed.
    int numSeconds = dtNow - dtCreate;
    //  Get the expires_in value from the JSON.
    int expires_in = json.IntOf("expires_in");

    cout << "token age (in seconds) = " << numSeconds << "\r\n";
    cout << "expires_in = " << expires_in << "\r\n";

    if (numSeconds < (expires_in - 300))
        {
            std::cout << "The token is not yet expired.  No need to fetch another." << "\r\n";
            return;
        }
    if (numSeconds > (expires_in - 300))
        {
            cout << "Time to fetch a new access token..." << "\r\n";
            get_paypal_token();
        }
}

void tweet()
{
    //  It requires the Chilkat API to have been previously unlocked.
    //  See Global Unlock Sample for sample code.

    //  ----------------------------------------------------------------------
    //  This initial setup, which involves setting the OAuth1 properties and connecting
    //  to api.twitter.com, is only required once at the beginning.  Once connected, the same
    //  object instance may be re-used, and if necessary, it will automatically reconnect
    //  as needed.

    //  Assume we've previously obtained an access token and saved it to a JSON file..
    CkJsonObject json;
    bool success = json.LoadFile("qa_data/tokens/twitter.json");

    CkRest rest;
    CkOAuth1 oauth1;

    oauth1.put_ConsumerKey("TWITTER_CONSUMER_KEY");
    oauth1.put_ConsumerSecret("TWITTER_CONSUMER_SECRET");
    oauth1.put_Token(json.stringOf("oauth_token"));
    oauth1.put_TokenSecret(json.stringOf("oauth_token_secret"));
    oauth1.put_SignatureMethod("HMAC-SHA1");
    oauth1.GenNonce(16);

    rest.SetAuthOAuth1(oauth1,false);

    bool bAutoReconnect = true;
    success = rest.Connect("api.twitter.com",443,true,bAutoReconnect);
    if (success != true)
        {
            cout << rest.lastErrorText() << "\r\n";
            return;
        }   

    //  This ends the initial setup...
    //  ----------------------------------------------------------------------

    const char *tweetContent = "This is a test tweet.";

    //  Send a tweet...
    rest.ClearAllQueryParams();
    rest.AddQueryParam("status",tweetContent);
    const char *response = rest.fullRequestFormUrlEncoded("POST","/1.1/statuses/update.json");
    if (rest.get_LastMethodSuccess() != true)
        {
            cout << rest.lastErrorText() << "\r\n";
            return;
        }

    CkJsonObject jsonResponse;
    jsonResponse.put_EmitCompact(false);
    jsonResponse.Load(response);

    if (rest.get_ResponseStatusCode() != 200)
        {
            cout << jsonResponse.emit() << "\r\n";
            return;
        }

    //  Show the successful response:
    cout << jsonResponse.emit() << "\r\n";
    cout << "Success." << "\r\n";
}

void tweet_with_image()
    {
    //  This example requires the Chilkat API to have been previously unlocked.
    //  See Global Unlock Sample for sample code.

    //  ----------------------------------------------------------------------
    //  This initial setup, which involves setting the OAuth1 properties and connecting
    //  to api.twitter.com, is only required once at the beginning.  Once connected, the same
    //  object instance may be re-used, and if necessary, it will automatically reconnect
    //  as needed.

    //  Assume we've previously obtained an access token and saved it to a JSON file..
    CkJsonObject json;
    bool success = json.LoadFile("qa_data/tokens/twitter.json");

    CkRest rest;
    CkOAuth1 oauth1;

    oauth1.put_ConsumerKey("TWITTER_CONSUMER_KEY");
    oauth1.put_ConsumerSecret("TWITTER_CONSUMER_SECRET");
    oauth1.put_Token(json.stringOf("oauth_token"));
    oauth1.put_TokenSecret(json.stringOf("oauth_token_secret"));
    oauth1.put_SignatureMethod("HMAC-SHA1");
    oauth1.GenNonce(16);

    rest.SetAuthOAuth1(oauth1,false);

    bool bAutoReconnect = true;
    success = rest.Connect("api.twitter.com",443,true,bAutoReconnect);
    if (success != true)
        {
            cout << rest.lastErrorText() << "\r\n";
            return;
        }   

    //  This ends the initial setup...
    //  ----------------------------------------------------------------------

    const char *tweetContent = "This is a test tweet with an image.";

    //  Send a tweet...
    rest.ClearAllQueryParams();
    rest.AddQueryParam("status",tweetContent);

    //  Add list of media_ids to associate with the Tweet.
    //  You may include up to 4 photos or 1 animated GIF or 1 video in a Tweet.
    //  The image needs to have been previously uploaded.  The upload response gave us
    //  the media ID we'll use to associate this tweet with the image (or video)
    //  See Twitter Upload Media for sample code.
    //  This example will add just a single image/photo.
    rest.AddQueryParam("media_ids","793137045996646400");

    const char *response = rest.fullRequestFormUrlEncoded("POST","/1.1/statuses/update.json");
    if (rest.get_LastMethodSuccess() != true)
        {
            cout << rest.lastErrorText() << "\r\n";
            return;
        }

    CkJsonObject jsonResponse;
    jsonResponse.put_EmitCompact(false);
    jsonResponse.Load(response);

    if (rest.get_ResponseStatusCode() != 200)
        {
            cout << jsonResponse.emit() << "\r\n";
            return;
        }

    //  Show the successful response:
    cout << jsonResponse.emit() << "\r\n";
    cout << "Success." << "\r\n";
}

void tweet_with_image_multi()
    {
    //  This example requires the Chilkat API to have been previously unlocked.
    //  See Global Unlock Sample for sample code.

    //  ----------------------------------------------------------------------
    //  This initial setup, which involves setting the OAuth1 properties and connecting
    //  to api.twitter.com, is only required once at the beginning.  Once connected, the same
    //  object instance may be re-used, and if necessary, it will automatically reconnect
    //  as needed.

    //  Assume we've previously obtained an access token and saved it to a JSON file..
    CkJsonObject json;
    bool success = json.LoadFile("qa_data/tokens/twitter.json");

    CkRest rest;
    CkOAuth1 oauth1;

    oauth1.put_ConsumerKey("TWITTER_CONSUMER_KEY");
    oauth1.put_ConsumerSecret("TWITTER_CONSUMER_SECRET");
    oauth1.put_Token(json.stringOf("oauth_token"));
    oauth1.put_TokenSecret(json.stringOf("oauth_token_secret"));
    oauth1.put_SignatureMethod("HMAC-SHA1");
    oauth1.GenNonce(16);

    rest.SetAuthOAuth1(oauth1,false);

    bool bAutoReconnect = true;
    success = rest.Connect("api.twitter.com",443,true,bAutoReconnect);
    if (success != true)
        {
            cout << rest.lastErrorText() << "\r\n";
            return;
        }

    //  This ends the initial setup...
    //  ----------------------------------------------------------------------

    const char *tweetContent = "This is a test tweet with multiple images.";

    //  Send a tweet...
    rest.ClearAllQueryParams();
    rest.AddQueryParam("status",tweetContent);

    //  Add list of comma separated media_ids to associate with the Tweet.
    //  You may include up to 4 photos or 1 animated GIF or 1 video in a Tweet.
    //  The image needs to have been previously uploaded.  The upload response gave us
    //  the media ID we'll use to associate this tweet with the image (or video)
    //  See Twitter Upload Media for sample code.
    rest.AddQueryParam("media_ids","793137045996646400,793192201392041984");

    const char *response = rest.fullRequestFormUrlEncoded("POST","/1.1/statuses/update.json");
    if (rest.get_LastMethodSuccess() != true)
        {
            cout << rest.lastErrorText() << "\r\n";
            return;
        }

    CkJsonObject jsonResponse;
    jsonResponse.put_EmitCompact(false);
    jsonResponse.Load(response);

    if (rest.get_ResponseStatusCode() != 200)
        {
            cout << jsonResponse.emit() << "\r\n";
            return;
        }

    //  Show the successful response:
    cout << jsonResponse.emit() << "\r\n";
    cout << "Success." << "\r\n";
}

void qr_scanner()
{
    string camera;
    int type_camera;
    cout << "Which Camera do you want to activate?" << endl;
    cout << "[external]" << endl;
    cout << "[internal]" << endl;
    getline(cin, camera);
    if(camera == "external")
        {
            type_camera = "1";    
        }
    if(camera == "internal")
        {
            type_camera = "0";    
        }
    VideoCapture cap(type_camera);
   // cap.set(CV_CAP_PROP_FRAME_WIDTH,800);
   // cap.set(CV_CAP_PROP_FRAME_HEIGHT,640);
   //if not success, return to lara
    if (!cap.isOpened())
        {
            cout << "Cannot open the video cam" << endl;
            lara();
        }
    ImageScanner scanner;  
/*      scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);  
*/
    //get the width of frames of the video
    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); 
    //get the height of frames of the video
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); 
    cout << "Frame size : " << dWidth << " x " << dHeight << endl;
    //create a window called "QR Scanner"
    namedWindow("QR Scanner",CV_WINDOW_AUTOSIZE); 
    while (1)
        {
            Mat frame;
            bool bSuccess = cap.read(frame); // read a new frame from video
            if (!bSuccess) //if not success, break loop
                {
                    cout << "Cannot read a frame from video stream" << endl;
                    lara();
                }
            Mat grey;
            cvtColor(frame,grey,CV_BGR2GRAY);
            int width = frame.cols;  
            int height = frame.rows;  
            uchar *raw = (uchar *)grey.data;  
            // wrap image data  
            Image image(width, height, "Y800", raw, width * height);  
            // scan the image for barcodes  
            int n = scanner.scan(image);  
            // extract results  
            for(Image::SymbolIterator symbol = image.symbol_begin();symbol != image.symbol_end();++symbol)
                {  
                    vector<Point> vp;  
                    //do something useful with results  
                    cout << "decoded " << symbol->get_type_name()  << " symbol \"" << symbol->get_data() << '"' <<" "<< endl;  
                    int n = symbol->get_location_size();  
                    for(int i=0;i<n;i++)
                        {  
                            vp.push_back(Point(symbol->get_location_x(i),symbol->get_location_y(i))); 
                        }  
                    RotatedRect r = minAreaRect(vp);  
                    Point2f pts[4];  
                    r.points(pts);  
                    for(int i=0;i<4;i++)
                        {  
                            line(frame,pts[i],pts[(i+1)%4],Scalar(255,0,0),3);  
                        }  
                    //cout<<"Angle: "<<r.angle<<endl;  
                }
            //show the frame in "QR Scanner" window
            imshow("QR Scanner", frame);
            //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
            if (waitKey(30) == 27) 
                {
                    cout << "esc key is pressed by user" << endl;
                    lara(); 
                }
        }
}
