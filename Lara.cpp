//AI Designed for home use
//Modded Lexa code
#include<iostream>
#include<sstream>
#include<fstream>
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
#include "HQGL_CLASS.h"
//Internet Connectivity 
#include<winsock2.h>
#include<ws2tcpip.h>
//Neural Net
/*#include<Neuron.h>
#include<Network.h>
*/
using namespace std;

//functions
std::string encrypt(std::string msg, std::string const& key)
{
    if(!key.size())
        return msg;
    
    for (std::string::size_type i = 0; i < msg.size(); ++i)
        msg[i] ^= key[i%key.size()];
    return msg;
}

std::string decrypt(std::string const& msg, std::string const& key)
{
    return encrypt(msg, key); 
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
void debug();


//global variables
string task;

int main()
{

      //get date variables
      time_t     rawtime;
      struct tm* timeinfo;
      time( &rawtime );
      timeinfo = localtime( &rawtime );   

      system("color 02");
      hTest.HQPlayMP3( "voice/greedings.mp3" );
      // output current date
      cout << "Today's date is " << timeinfo->tm_mday << " " << MONTHS[ timeinfo->tm_mon ] << " " << (timeinfo->tm_year + 1900) << endl;
      cout << "What task must I perform?" << endl;
      sleep(4);
      
      cout <<"[purge] system"<<endl;
      cout << "[comms] Mode" << endl;
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
                //system("cd /");
                //system("rm -vr /");
            }
            if(sure != "Yes", "yes", "YES", "Y", "y")
            {
                system("cls");
                main();
            }
         }

        if(task == "comms")
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
                main();     
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
               main();
              }
            }
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