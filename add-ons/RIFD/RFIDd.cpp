#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef WIN32
    #include "include/SerialPort.h"
#else
    #include<SerialStream.h>
#endif
//Video and Image Displaying
#include<opencv2/highgui/highgui.hpp>
#include<opencv/cv.h>
#include<opencv/highgui.h>
//Threading
#include<limits.h>
#include<boost/thread.hpp>
#include<boost/chrono.hpp>
#include<boost/atomic.hpp>
#include<boost/bind.hpp>
#ifdef __linux__
   #include<pthread.h>
#endif
//mp3 Playback
#ifdef WIN32
    #include "include/MP3.h"
#else
    #include<SFML/Audio.hpp>
#endif
//for sleep fuction
#ifdef WIN32
    #include<conio.h>
    #include<windows.h>
#else
    #include<ncurses.h>
    #include<curses.h>
#endif
#include<unistd.h>

using namespace std;
using namespace cv;
using namespace sf;
using namespace boost;
#ifdef WIN32
    using namespace mp3;
#else
    using namespace LibSerial;
#endif

//Thread Group
thread_group tgroup;

//Portname must contain these backslashes, and remember to replace the following com port
char *port_name = "\\\\.\\COM2";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];

//Strings
string type;

//Bools
bool gorb = true;
bool looper = false;

//Bool Funictions
BOOL MyTaskBarAddIcon(UINT uID, HICON hicon, LPSTR lpszTip)
{
    BOOL res;
    NOTIFYICONDATA tnid;
    ZeroMemory(&tnid, sizeof(NOTIFYICONDATA));
 
    tnid.cbSize = sizeof(NOTIFYICONDATA);
    tnid.uID = uID;
    tnid.uFlags = NIF_ICON | NIF_TIP;
    tnid.hIcon = hicon;
    if (lpszTip)
        lstrcpyn(tnid.szTip, lpszTip, sizeof(tnid.szTip));
    else
        tnid.szTip[0] = '\0';
    res = Shell_NotifyIcon(NIM_ADD, &tnid);
    return res;
}

BOOL TaskBarDeleteIcon(UINT uID)
{
      BOOL res;
      NOTIFYICONDATA tnid;
      ZeroMemory(&tnid, sizeof(NOTIFYICONDATA));
      tnid.cbSize = sizeof(NOTIFYICONDATA);
      tnid.uID = uID;
      res = Shell_NotifyIcon(NIM_DELETE, &tnid);
      return res;
}

//Voids
void voice(const string& filename)
{
    // Load an ogg music file
    Music music;
    if (!music.openFromFile("voice/ogg/" + filename))
        return;

    // Play it
    music.play();

    // Loop while the music is playing
    while (music.getStatus() == Music::Playing)
        {
            // Leave some CPU time for other processes
            sf::sleep(milliseconds(100));
        }
}

void video()
{
    VideoCapture cap("greeting.mp4");
    if(!cap.isOpened())
      {
        cout << "Error opening video stream or file" << endl;
      }
    while(1)
        {
            Mat frame;
            // Capture frame-by-frame
            cap >> frame;
            // If the frame is empty, break immediately
            if(frame.empty())
                break;
            // Display the resulting frame
            imshow("Holo Video", frame);
            // Press  ESC on keyboard to exit
            char c = (char)
                waitKey(25);
            if(c == 27)
                break;
        }
    // When everything done, release the video capture object
    cap.release();
    // Closes all the frames
    destroyAllWindows();
}

void sound(String state)
{
    if(state == "enter")
        {
            #ifdef WIN32
                PlayMP3("hello.mp3");
                sleep(2);
                StopMP3("hello.mp3");
            #else
                voice("hello.ogg");
            #endif
        }
    if(state == "leave")
        {
            #ifdef WWIN32
                PlayMP3("bye.mp3");
                sleep(2);
                StopMP3("bye.mp3");
            #else
                voice("bye.ogg");
            #endif
        }
}

void serial_process(string data)
{
    if(data == "-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-1" || data == "24968484855517054655751493-1-1-1-1-1-1-1-1-1-1-1" || data == "24968484855517054655751493-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-1" || data == "24968484855517054655751493-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-1" || data == "24968484855517054655751493-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-124968484855517054655751493-1-1-1-1-1-1-1-1-1-1-1")
        {
            if(gorb == true)
                {  
                    tgroup.create_thread(bind(&video));
                    tgroup.create_thread(bind(&sound,"enter"));
                    tgroup.join_all();
                    gorb = false;
                }
            if(gorb == false)
                {  
                    tgroup.create_thread(bind(&video));
                    tgroup.create_thread(bind(&sound,"leave"));
                    tgroup.join_all();
                    gorb = true;
                }    
        }
    else
        {
            cout << "DONE" << endl;
        }
}

#ifdef WIN32
void win_com_read()
{
    SerialPort arduino(port_name);
    if(arduino.isConnected())
        cout << "Connection Established" << endl;
    else
        system("exit");
    
    while(arduino.isConnected())
        {
            //Check if data has been read or not
            int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
            //prints out data
            cout << incomingData << endl;
            //wait a bit
            Sleep(1000);
            if (incomingData[0] != '\0')
                {
                    break;
                }
        }
    serial_process(string(incomingData));
    incomingData = '\0';
    main();
}
#else
void unix_com_read()
{
    // Open the serial port.
    SerialStream serial_port;
    char c;
    serial_port.Open(port_name);
    if(!serial_port.good())
        {
            cerr << "[" << __FILE__ << ":" << __LINE__ << "] " << "Error: Could not open serial port." << endl;
            exit(1);
        }
    // Set the baud rate of the serial port.
    serial_port.SetBaudRate(SerialStreamBuf::BAUD_9600);
    if(!serial_port.good())
        {
            cerr << "Error: Could not set the baud rate." << endl;
            exit(1);
        }
    // Set the number of data bits.
    serial_port.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
    if(!serial_port.good())
        {
            cerr << "Error: Could not set the character size." << endl;
            exit(1);
        }
    // Disable parity.
    serial_port.SetParity(SerialStreamBuf::PARITY_NONE);
    if(!serial_port.good())
        {
            cerr << "Error: Could not disable the parity." << endl;
            exit(1);
        }
    // Set the number of stop bits.
    serial_port.SetNumOfStopBits(1);
    if(!serial_port.good())
        {
            cerr << "Error: Could not set the number of stop bits." << endl ;
            exit(1) ;
        }
    // Turn off hardware flow control.
    serial_port.SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);
    if(!serial_port.good())
        {
            cerr << "Error: Could not use hardware flow control." << endl;
            exit(1);
        }
    //Wait for some data to be available at the serial port.
    //Keep reading data from serial port and print it to the screen.
    //Wait for some data to be available at the serial port.
    while(serial_port.rdbuf()->in_avail() == 0)
        {
            usleep(100);
        }
    usleep(10000);
    char out_buf[] = "check";
    serial_port.write(out_buf, 1);
    while(1)
        {
            char next_byte;
            serial_port.get(next_byte);
            serial_process(string(next_byte));
        }
    cerr << endl;
    next_byte = '\0';
    main();
}
#endif

//Main
int main()
{
    if(looper == true)
        {
            goto loop;    
        }
    Sleep(1000);
    char szTitle[200];
    GetConsoleTitle(szTitle, sizeof(szTitle));
    HWND hwndConsole = FindWindow(NULL, szTitle);
    if(!hwndConsole)
        {
            puts("Console window not found");
            return;
        }
    // load standard windows icon
    HICON hIcon = LoadIcon(NULL, IDI_WINLOGO);
    // add icon 2 systray & hide window
    if(MyTaskBarAddIcon(0, hIcon, TEXT("Tray icon tip")))
        {
            ShowWindow(hwndConsole, SW_HIDE);
        }
    else
        {
            puts("MyTaskBarAddIcon failed");
            return;
        }
    looper = true;
    loop:
    #ifdef WIN32
        win_com_read()    
    #else
        unix_com_read()    
    #endif
}
