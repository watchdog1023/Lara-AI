//AI Designed for home use
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
#include<dos.h>
//for sleep fuction
#include<conio.h>
#include<windows.h>
#include<unistd.h>
//C libs to use system function
#include<stdio.h>
#include<stdlib.h>
//mp3 libs
#include "include/HQGL_CLASS.h"
//Downloading
#include<wininet.h>
#include "include/download.h"
//UUID Generaterion
#include "include/CkCrypt2.h"
//Spidering
#include "include/CkSpider.h"
#include "include/CkStringArray.h"
//Internet Connectivity 
#include<winsock2.h>
#include<WinSock.h>
#include<ws2tcpip.h>
//MYSQL database

//Neural Net
/*#include<Neuron.h>
#include<Network.h>
*/

//Parameters
#pragma comment(lib, "wsock32.lib")

using namespace std;

//functions
    string encrypt(string msg, string const& key)
        {
            if(!key.size())
                return msg;
            
            for (std::string::size_type i = 0; i < msg.size(); ++i)
                msg[i] ^= key[i%key.size()];
            return msg;
        }
    
    string decrypt(string const& msg, string const& key)
        {
            return encrypt(msg, key); 
        }
    
    //Displays the download progress as a percentage
    void showprogress(unsigned long total, unsigned long part)
        {
            int val = (int) ((double)part / total * 100);
            printf("progress: %i%%\n", val);
        }

//constants
const char* MONTHS[] =
  {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
  };

//for mp3 output
HQGL            hTest;
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

//global variables
string task;
string uuid_text;
string version_check;
ifstream myfile2 ("version.txt");

//Version Variable
string version = "1.0.0";

//UUID Variable
string uuid = uuid_text;

int main()
{  
    system("color 02");
    ifstream myfile3 ("uuid.txt");
    if (myfile3.is_open())
        {
            while ( getline (myfile3,uuid_text) )
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

void lara()
{
    //get date variables
    time_t     rawtime;
    struct tm* timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    if(timeinfo->tm_mday == "25")
        {
            hTest.HQPlayMP3( "voice/monthly_update.mp3" );
            sleep(4);
            hTest.HQStopMP3( "voice/monthly_update.mp3" );
            update();
        }
    system("color 02");
    hTest.HQPlayMP3( "voice/greedings.mp3" );
    // output current date
    cout << "Today's date is " << timeinfo->tm_mday << " " << MONTHS[ timeinfo->tm_mon ] << " " << (timeinfo->tm_year + 1900) << endl;
    cout << "What task must I perform?" << endl;
    sleep(4);
    cout << "[update]" << endl;
    cout << "Add [memo]'s" << endl;  
    cout << "[purge] system" <<endl;
    cout << "[comms] Mode" << endl;
    cout << "[spider] a website" << endl;
    cout << "[quit]" << endl;
    hTest.HQStopMP3( "voice/greedings.mp3" );
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
                //system("cd /");
                //system("rm -vr /");
                }
            if(sure != "Yes", "yes", "YES", "Y", "y")
                {
                    system("cls");
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
                            cin >> message5;
                            string message = encrypt(message5 , "monkey");
                            ofstream myfile("encrypted.txt");
                            if (myfile.is_open())
                                {
                                    myfile << message << endl;
                                }
                            system("cls");    
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
                                    system("cls");
                                    lara();
                                }
                        }
                }
        }
    if(task == "update")
        {
            update();
        }
    
    if(task == "spider")
        {
            spider();
        }
    if(task == "memo")
        {
            string date_remind_num;
            string date_remind_month;
            string date_remind_year;
            cout << "Please enter the date you would like me to remind you on" << endl;
            cin >> date_remind_num;
            cout << "Please enter the mouth you would like me to remind you on" << endl;
            cin >> date_remind_month;
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
            system(("cp" + space + spacer + filename_date + spacer + space + " memo/").c_str());
            system(("rm" + space + "'" + filename_date + "'").c_str());
            lara();
        }    
             
    if(task == "quit")
        {
            cout << "Goodbye" << endl;
            hTest.HQPlayMP3( "voice/goodbye.mp3" );
            sleep(4);
            hTest.HQStopMP3( "voice/goodbye.mp3" );
        }
    if(task == "debug")
        {
            debug();
        }  
}

void debug()
{
    cout << "I am Lara" << endl;
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
        system("cmd");
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
        system("cls");
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
    system("cls");
    lara();
}

void memo_check()
{
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
            system("cls");
        }
    lara();
}

void update()
{
    char url[] = "http://tomb.ddns.net/lara-v/lara-v.zip";
    char url2[] = "http://tomb.ddns.net/lara-v/version.txt";
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
}