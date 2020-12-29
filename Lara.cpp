//AI Designed for home use
//Built using Mingw32 Build Mr Robot
//Modded Lexa code
//Check for C++ Compiler
#ifndef __cplusplus
	#error A C++ compiler is required!
#endif
#ifdef __clang__
	#error Lara will not compile with clang,please use gcc
#endif
//Definations
#define Pocketsphinx "5prealpha"
#define sphinx "5prealpha"
#ifdef FOUNDER
	#define ALIVE
    #define IRON_HIDE
#endif
#include<iostream>
#include<sstream>
#include<fstream>
#include<istream>
#ifdef __linux__
	#include<string.h>
#endif
#include<stdio.h>
#include<string>
#undef max
#include<vector>
#include<cmath>
#include<math.h>
#include<cassert>
#include<assert.h>
//Neural Network Pattern Recognition
#include<stdexcept>
//Internet Connectivity 
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<winsock2.h>
    #include<WinSock.h>
    #include<ws2tcpip.h>
#else
    #include<sys/socket.h>
    #include<sys/types.h>
    #include<netinet/in.h>
    #include<netdb.h>
    #include<arpa/inet.h>
    #include<unistd.h>
#endif
//for date & time
#include<ctime>
#if defined(WIN32) || defined(__CYGWIN32__) 
    #include<direct.h>
#else
	#include<sys/time.h>
#endif
#include<time.h>
//for sleep fuction
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<conio.h>
    #include<windows.h>
#endif
#include<unistd.h>
//For getch(),linux
#ifdef __linux__
    #include<termios.h>
#endif
//C libs to use system function
#include<cstdio>
#include<cstdlib>
//mp3 Playback
#if defined(WIN32) || defined(__CYGWIN32__)
    #include "include/MP3.h"
#endif
#include<SFML/Audio.hpp>
//Downloading
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<wininet.h>
    #include "include/download.h"
#else
    #include<arpa/inet.h>
#endif
#include<curl/curl.h>
//Chatting
#include<SFML/Network.hpp>
#include<iterator>
//UUID Generaterion
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
//Tesseract-OCR
#include<tesseract/baseapi.h>
//#include<leptonica/allheaders.h>
//Threading
#include<limits.h>
#include<boost/thread.hpp>
#include<boost/chrono.hpp>
#include<boost/atomic.hpp>
#include<boost/bind.hpp>
#ifdef __linux__
   #include<pthread.h>
#endif
//MPI
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<mpi.h>
#elif __APPLE__
    #include<mpi.h>
#else
    #include<mpi.h>
#endif
#include<boost/mpi.hpp>
//MYSQL database
#if defined(WIN32) || defined(__CYGWIN32__)
	#include<cppconn/driver.h>
	#include<cppconn/exception.h>
	#include<cppconn/resultset.h>
	#include<cppconn/statement.h>
#elif __APPLE__
	#include<jdbc/cppconn/driver.h>
	#include<jdbc/cppconn/exception.h>
	#include<jdbc/cppconn/resultset.h>
	#include<jdbc/cppconn/statement.h>
#elif __linux__ 
	#ifdef __arm__
		#include<jdbc/cppconn/driver.h>
		#include<jdbc/cppconn/exception.h>
		#include<jdbc/cppconn/resultset.h>
		#include<jdbc/cppconn/statement.h>
	#else	
		#include<cppconn/driver.h>
		#include<cppconn/exception.h>
		#include<cppconn/resultset.h>
		#include<cppconn/statement.h>
	#endif
#endif
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<mysql.h>
#else
    #include<mysql/mysql.h>
#endif
#include<sqlite3.h> 
//Video and Image Displaying
#if (CV_VERSION_MAJOR >= 4)
	#include<opencv4/opencv2/highgui/highgui.hpp>
	#include<opencv4/opencv2/highgui/highgui.hpp>
#else
	#include<opencv2/highgui/highgui.hpp>
	#include<opencv/cv.h>
	#include<opencv/highgui.h>
#endif
//Hand Recognition
#include<opencv/cxcore.h>
//IRC Commuication
#include<map>
#include<algorithm>
#include<signal.h>
#include "include/IRC/IRCClient.h"
#include "include/IRC/IRCHandler.h"
#include "include/IRC/IRCSocket.h"
#include "include/IRC/Thread.h"
//QR Code Generation
#include<cstdint>
#if defined(WIN32) || defined(__CYGWIN32__)
	#include "include/qr_code/QrCode.hpp"
#endif
//QR code Scanner
#if defined(WIN32) || defined(__CYGWIN32__)
	#include<zbar.h>
#endif
#if (CV_VERSION_MAJOR >= 4)
	#include<opencv4/imgproc/imgproc.hpp>
#else
	#include<opencv2/imgproc/imgproc.hpp>
#endif
//SDL Creation
//#include<SDL/SDL.h>
//#include<SDL2/SDL.h>
//Set width
#include<iomanip>
//Colour Changer
#include<termcolor/termcolor.hpp>
//Nerve
#define BUF_LEN 65540
#include<locale>
#include<cstring>
//For UDPSocket and SocketException
#include "include/PracticalSocket/PracticalSocket.h"
//Configuration
#include "include/webcam_comm/config.h"
//CUDA Functions
#ifdef CUDA
	//This is Customs CUDA Functions
	#include<cuda_functions.h>
#endif
//GPIO
#include<cerrno>
#ifdef ARM
    #include<wiringPi.h>
#endif
//Python Environment
#if defined(WIN32) || defined(__CYGWIN32__)
    #include<Python.h>
#else
    #include<Python.h>
#endif
//Ruby Environment
//#include<ruby/ruby.h>
//Java Environment
//#include<jni.h>
//Encryption Headers
/*#include<cryptopp/osrng.h>
#include<cryptopp/modes.h>
#include<cryptopp/aes.h>
#include<cryptopp/filters.h>*/
//Bitcoin Balance
//#include<bitcoinapi/bitcoinapi.h>
//Neural Net
//ISO/ANSII C/C++
//#include "include/Neuron.h"
//#include "include/Network.h"
//#include "include/trainingdata.h"
#if defined(WIN32) || defined(__CYGWIN32__)
    //OpenNN
//    #include<opennn/opennn.h>
#elif __linux__
    //Tensorflow
    //#include<tensorflow/c/c_api.h>
#elif _WIN64
    //Tensorflow
    #include<tensorflow/c/c_api.h>
#endif
//For Voice Recognition and Voice Synthesis
#include<sphinxbase/err.h>
#include<sphinxbase/ad.h>
#include<pocketsphinx/pocketsphinx.h>
#if __linux__
    #include<sys/select.h>
#endif
//Websocket
#if defined(WIN32) || defined(__CYGWIN32__)
	#include<websocketpp/config/asio_no_tls.hpp>
	#include<websocketpp/server.hpp>
	#include<websocketpp/config/asio_no_tls_client.hpp>
	#include<websocketpp/client.hpp>
#endif
//Hostname Getting
//#include<boost/asio/ip/host_name.hpp>
//Serial Port Handling
/*#if defined(WIN32) || defined(__CYGWIN32__)
    #include "include/SerialPort.h"
#else
    #include<SerialStream.h>
#endif*/
//Boost Version
#include<boost/version.hpp>
#ifdef ALIVE
	//Emotions detection
	#include "include/Emotions.h"
#endif
//Titan Robotics Lib
#include "Titans.h"
//OPENGL
#ifdef OPENCL
	#define CL_USE_DEPRECATED_OPENCL_2_0_APIS
	#include<CL/cl.hpp>
#endif
//JSON
#include<json/json.h>
#include<json/reader.h>
#include<json/writer.h>
#include<json/value.h>
//Satellite Commuincation
#include "wraith.hpp"
//My Source Checksum signature header
//#include "include/my_checksum.h"

//Parameters
#pragma comment(lib, "wsock32.lib")

using namespace Titan;
using namespace std;
using namespace cv;
using namespace http;
using namespace Json;
#if defined(WIN32) || defined(__CYGWIN32__)
	using namespace qrcodegen;
#endif
using namespace termcolor;
#if defined(WIN32) || defined(__CYGWIN32__)
    using namespace mp3;
#endif
//using namespace CryptoPP;
//using namespace sf;
//Boost Namespaces
//using namespace boost;
//using namespace boost::mpi;
//using namespace boost::this_thread;
//MPI Protocol Handling
//using namespace MPI;
//Tesseract-OCR Namespcaes
//using namespace tesseract;
//MYSQL Connection
using namespace sql;
#if defined(WIN32) || defined(__CYGWIN32__)
	//Websocket
	using namespace websocketpp;
#endif
//NN
#if defined(WIN32) || defined(__CYGWIN32__)    
//    using namespace OpenNN;
#else
    //using namespace tensorflow;
#endif
#if defined(WIN32) || defined(__CYGWIN32__)
	using namespace zbar;
#endif
#ifdef OPENCL
	using namespace cl;
#endif

//Volatile Bool
volatile bool running;

//SMFL Vars
sf::Music music2;

//String Functions
string encrypt(string msg, string const& key)
    {
        if(!key.size())
            return msg;
        
        for (string::size_type i = 0; i < msg.size(); ++i)
            msg[i] ^= key[i % key.size()];
        return msg;
    }
    
string decrypt(string const& msg, string const& key)
    {
        return encrypt(msg, key); 
    }
	 
string GetStdoutFromCommand(string cmd)
{
	string data;
	FILE * stream;
	const int max_buffer = 256;
	char buffer[max_buffer];
	cmd.append(" 2>&1");
	stream = popen(cmd.c_str(), "r");
	if(stream)
		{
			while (!feof(stream))
				if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
					pclose(stream);
		}
	return data;
}

#if defined(WIN32) || defined(__CYGWIN32__)  
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

void unix_alarm(const string& filename)
{
    // Load an ogg music file
    if (!music2.openFromFile("voice/ogg/" + filename))
        return;
    // Play it
    music2.play();
	music2.setLoop(true);
}

void voice(const string& filename)
{
    // Load an ogg music file
    sf::Music music;
    if (!music.openFromFile("voice/ogg/" + filename))
        return;

    // Play it
    music.play();

    // Loop while the music is playing
    while (music.getStatus() == sf::Music::Playing)
        {
            // Leave some CPU time for other processes
            sf::sleep(sf::milliseconds(100));
        }
}

//Constants
const char* MONTHS[] ={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};  
const static int SENSITIVITY_VALUE = 40;//for higher sensitivity, use a lower value
const static int BLUR_SIZE = 10;//size of blur used to smooth the intensity image output from absdiff() function
const sf::Uint8 audioData = 1;
const sf::Uint8 endOfStream = 2;
const unsigned short port = 2435;

//Static Constants
static const arg_t cont_args_def[] = {
    POCKETSPHINX_OPTIONS,
    /* Argument file. */
    {"-argfile",ARG_STRING,NULL,"Argument file giving extra arguments."},
    {"-adcdev",ARG_STRING,NULL,"Name of audio device to use for input."},
    {"-inmic",ARG_BOOLEAN,"yes","Transcribe audio from microphone."},
    {"-time",ARG_BOOLEAN,"no","Print word times in file transcription."},
    CMDLN_EMPTY_OPTION
};

//Int Functions
#ifdef __linux__
    int getch(void)
        {
            struct termios oldattr, newattr;
            int ch;
            tcgetattr( STDIN_FILENO, &oldattr );
            newattr = oldattr;
            newattr.c_lflag &= ~( ICANON | ECHO );
            tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
            ch = getchar();
            tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
            return ch;
        }   

    int getche(void)
        {
            struct termios oldattr, newattr;
            int ch;
            tcgetattr( STDIN_FILENO, &oldattr );
            newattr = oldattr;
            newattr.c_lflag &= ~( ICANON );
            tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
            ch = getchar();
            tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
            return ch;
        }
#endif

//Voice Rec Variables
static ps_decoder_t *ps;
static cmd_ln_t *vconfig;
string voutput;

//Bool Vaules
bool debugMode;//toggled pressing 'd'
bool trackingEnabled;//toggled pressing 't'

//Timer
bool flag = true;

//mp3 Playback Variables
char Key;

#if defined(WIN32) || defined(__CYGWIN32__)
    //Portname must contain these backslashes, and remember to replace the following com port
    char *port_name = "\\\\.\\COM2";
#else
    const string port_name = "/dev/ttyACM0";
#endif

//String for incoming data
char incomingData[1000000];

//Neural Net Variables
//Global Net Variables
/*DataSet data_set;
NeuralNetwork neural_network;
LossIndex loss_index;
TrainingStrategy training_strategy;
ModelSelection model_selection;
//Local Net Variables
DataSet local_data_set;
NeuralNetwork local_neural_network;
LossIndex local_loss_index;
TrainingStrategy local_training_strategy;
ModelSelection local_model_selection;*/

//Prototypes
//C/C+
void memo_check();
void start();
void debug();
void update();
void uuid_gen_first();
void spider();
#if defined(WIN32) || defined(__CYGWIN32__)
    void win_server();
    void win_client();
#else
    void unix_server();
    void unix_client();
#endif
void lara();
void webcam_streaming();
#ifndef __arm__
	void vid_diplay();
#endif
void irc();
void hand_rec();
#ifndef __arm__
	void vid_diplay_holo(string holovid);
#endif
void init_start();
#if defined(WIN32) || defined(__CYGWIN32__)
	void qr_scanner();
#endif
void NN();
void open_img();
void BTC();
#ifndef __arm__
	void holo_logo();
#endif
void wait();
void timer(string quit);
void generate_random_number(int lowest,int highest);
void recognize_from_microphone();
void sleep_msec(int32 ms);
void websocket_server();
void alarm_timer();
#ifndef __arm__
	//Looper
	void holo_looper();
	void holo_looper_working();
#endif
#ifdef RFID || #ifdef DEBUG || #ifdef ALL
	void start_rfid_daemon();
#endif
#ifdef MOTOR || #ifdef DEBUG || #ifdef ALL
	void start_motor_daemon(string state);
#endif
#ifdef CUDA
    void run();
#endif
#ifdef FOUNDER
	void cad();
#endif
#ifdef __linux__
	void syscheck();
#endif
#ifdef ALIVE
	void temperature_check();
#endif
void socket_connect();

//Python3
void py_spider();
void py_NN(string state);
void py_functions(string function);

//global variables
string task;
string uuid_text;
string version_check;
ifstream myfile2 ("version.txt");
int holovideo;
string debugmode;

//Threading Variables
boost::mutex mutex;

//Thread Group
boost::thread_group tgroup;

//Const fuctions
const string currentDateTime()
{
    time_t     now = std::time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}
//Classes
#ifdef __linux__
	//TCP Client class
	class tcp_client
		{
		    private:
		        int sock;
		        std::string address;
		        int port;
		        struct sockaddr_in server;
	     
		    public:
		        tcp_client();
		        bool conn(string, int);
		        bool send_data(string data);
		        string receive(int);
		};
 
	tcp_client::tcp_client()
		{
		    sock = -1;
		    port = 0;
		    address = "";
		}
 
	//Connect to a host on a certain port number
	bool tcp_client::conn(string address , int port)
		{
		    //create socket if it is not already created
		    if(sock == -1)
		        {
		            //Create socket
		            sock = socket(AF_INET , SOCK_STREAM , 0);
		            if (sock == -1)
		                {
		                }
		        }
		    else
		        {
		            //Nothing
		        }
     
		    //setup address structure
			if(inet_addr(address.c_str()) == -1)
			    {
			        struct hostent *he;
			        struct in_addr **addr_list;
			        if((he = gethostbyname(address.c_str())) == NULL)
			            {
							return false;
			            }
			        addr_list = (struct in_addr **) he->h_addr_list;
			        for(int i = 0; addr_list[i] != NULL; i++)
			            {
			            server.sin_addr = *addr_list[i]; 
		                //cout<<address<<" resolved to "<<inet_ntoa(*addr_list[i])<<endl;
		                break;
			            }
				}   
			//plain ip address
			else
				{
					server.sin_addr.s_addr = inet_addr( address.c_str() );
				}
			server.sin_family = AF_INET;
			server.sin_port = htons(port);
			//Connect to remote server
			if(connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
				{
					return;
				}
			return true;
		}
 
	//Send data to the connected host
	bool tcp_client::send_data(string data)
		{
		    //Send some data
		    if(send(sock,data.c_str(),strlen(data.c_str()),0) < 0)
				{
				    return false;
				}
			return true;
		}
 
	//Receive data from the connected host
	string tcp_client::receive(int size=512)
		{
		    char buffer[size];
			string reply;
			//Receive a reply from the server
			if(recv(sock,buffer,sizeof(buffer),0) < 0)
				{
				}
			reply = buffer;
			return reply;
		}
#endif
//IRC Class
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
                void (*handler)(string , IRCClient* );
            };
    
        map<string, CommandEntry> _commands;
};

class NetworkRecorder : public sf::SoundRecorder
{
public:
    NetworkRecorder(const sf::IpAddress& host, unsigned short port) :
    m_host(host),
    m_port(port)
    {
    }
    ~NetworkRecorder()
    {
        // Make sure to stop the recording thread
        onStop();
    }

private:

    virtual bool onStart()
    {
        if (m_socket.connect(m_host, m_port) == sf::Socket::Done)
        {
            std::cout << "Connected to server " << m_host << std::endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    virtual bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
    {
        // Pack the audio samples into a network packet
        sf::Packet packet;
        packet << audioData;
        packet.append(samples, sampleCount * sizeof(sf::Int16));

        // Send the audio packet to the server
        return m_socket.send(packet) == sf::Socket::Done;
    }

    virtual void onStop()
    {
        // Send a "end-of-stream" packet
        sf::Packet packet;
        packet << endOfStream;
        m_socket.send(packet);

        // Close the socket
        m_socket.disconnect();
    }

    sf::IpAddress  m_host;   ///< Address of the remote host
    unsigned short m_port;   ///< Remote port
    sf::TcpSocket  m_socket; ///< Socket used to communicate with the server
};

class NetworkAudioStream : public sf::SoundStream
{
public:

    NetworkAudioStream() :
    m_offset     (0),
    m_hasFinished(false)
    {
        // Set the sound parameters
        initialize(1, 44100);
    }

    void start(unsigned short port)
    {
        if (!m_hasFinished)
        {
            // Listen to the given port for incoming connections
            if (m_listener.listen(port) != sf::Socket::Done)
                return;
            std::cout << "Server is listening to port " << port << ", waiting for connections... " << std::endl;

            // Wait for a connection
            if (m_listener.accept(m_client) != sf::Socket::Done)
                return;
            std::cout << "Client connected: " << m_client.getRemoteAddress() << std::endl;

            // Start playback
            play();

            // Start receiving audio data
            receiveLoop();
        }
        else
        {
            // Start playback
            play();
        }
    }

private:

    virtual bool onGetData(sf::SoundStream::Chunk& data)
    {
        // We have reached the end of the buffer and all audio data have been played: we can stop playback
        if ((m_offset >= m_samples.size()) && m_hasFinished)
            return false;

        // No new data has arrived since last update: wait until we get some
        while ((m_offset >= m_samples.size()) && !m_hasFinished)
            sf::sleep(sf::milliseconds(10));

        // Copy samples into a local buffer to avoid synchronization problems
        // (don't forget that we run in two separate threads)
        {
            sf::Lock lock(m_mutex);
            m_tempBuffer.assign(m_samples.begin() + m_offset, m_samples.end());
        }

        // Fill audio data to pass to the stream
        data.samples     = &m_tempBuffer[0];
        data.sampleCount = m_tempBuffer.size();

        // Update the playing offset
        m_offset += m_tempBuffer.size();

        return true;
    }

    virtual void onSeek(sf::Time timeOffset)
    {
        m_offset = timeOffset.asMilliseconds() * getSampleRate() * getChannelCount() / 1000;
    }

    void receiveLoop()
    {
        while (!m_hasFinished)
        {
            // Get waiting audio data from the network
            sf::Packet packet;
            if (m_client.receive(packet) != sf::Socket::Done)
                break;

            // Extract the message ID
            sf::Uint8 id;
            packet >> id;

            if (id == audioData)
            {
                // Extract audio samples from the packet, and append it to our samples buffer
                const sf::Int16* samples     = reinterpret_cast<const sf::Int16*>(static_cast<const char*>(packet.getData()) + 1);
                size_t      sampleCount = (packet.getDataSize() - 1) / sizeof(sf::Int16);

                // Don't forget that the other thread can access the sample array at any time
                // (so we protect any operation on it with the mutex)
                {
                    sf::Lock lock(m_mutex);
                    copy(samples, samples + sampleCount, back_inserter(m_samples));
                }
            }
            else if (id == endOfStream)
            {
                // End of stream reached: we stop receiving audio data
                cout << "Audio data has been 100% received!" << endl;
                m_hasFinished = true;
            }
            else
            {
                // Something's wrong...
                cout << "Invalid packet received..." << endl;
                m_hasFinished = true;
            }
        }
    }

    sf::TcpListener        m_listener;
    sf::TcpSocket          m_client;
    sf::Mutex              m_mutex;
    vector<sf::Int16> m_samples;
    vector<sf::Int16> m_tempBuffer;
    size_t            m_offset;
    bool                   m_hasFinished;
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

//Temp
IplImage* fps;

//Version Variable
string version = "1.0.0";

//Greeting Variable
string greet;

string nowtime;

//IP Array
string ips[] = {"192.168.1.100","192.168.1.101","192.168.1.102","192.168.1.103","192.168.1.104","192.168.1.105","192.168.1.106","192.168.1.107","192.168.1.108","192.168.1.109","192.168.1.110","192.168.1.111","192.168.1.112","192.168.1.113","192.168.1.114","192.168.1.115","192.168.1.116","192.168.1.117","192.168.1.118","192.168.1.119","192.168.1.120","192.168.1.121","192.168.1.122","192.168.1.123","192.168.1.124","192.168.1.125","192.168.1.126","192.168.1.127","192.168.1.128","192.168.1.129","192.168.1.130"};

//MP3 Player
string mp3player;

//UUID Variable
string uuid = uuid_text;

//Idle Bool
bool idle = true;
//int kill = 0;
boost::thread ty;
boost::thread tfs;
boost::thread tw;
boost::thread t;
boost::thread tu;

int main(int argc, char* argv[])
{
    #if defined(WIN32) || defined(__CYGWIN32__)
        std::system ("title Lara");
        std::system("color 02");
    #else
        cout << termcolor::green;
    #endif
    greet = "1";
    if(argv[1] == NULL)
        {
            ifstream myfile3 ("uuid.txt");
            if(myfile3.is_open())
                {
                    while(getline(myfile3,uuid_text))
						{
                            uuid = uuid_text;
							memo_check();
						}
					#if defined(WIN32) || defined(__CYGWIN32__)
						myfile3.close();
					#endif
                }
            else
                {
                    init_start();
                }
        }
	#ifdef ALIVE
	if(string(argv[1]) == "body")
		{
			boost::thread emo{&emot_reg};
			boost::thread tim{&alarm_timer};
            tgroup.join_all();
            char const *cfg;
            err_set_logfp(NULL);
            err_set_debug_level(0);
            loop:
                    cout << "start loop" << endl;
                    vconfig = cmd_ln_parse_r(NULL, cont_args_def, argc, argv, TRUE);
                    ps_default_search_args(vconfig);
                    ps = ps_init(vconfig);
                    if (ps == NULL)
                        {
                            cmd_ln_free_r(vconfig);
                            return 1;
                        }
                    recognize_from_microphone();
                    ps_free(ps);
                    cmd_ln_free_r(vconfig);
                    if(voutput.find("lara") != std::string::npos)
                        {
                            cout << "Yes!" << endl;
                            AI::TTS("yes");
                            sleep(1);
                            goto loop;
                        }
                    if(voutput.find("can") != std::string::npos)
                        {
                            if(voutput.find("you") != std::string::npos)
                                {
                                    if(voutput.find("hear") != std::string::npos)
                                        {
                                            if(voutput.find("me") != std::string::npos)
                                                {
                                                    AI::TTS("yes i can boss");
                                                    sleep(1);
                                                    goto loop;
                                                }
                                            else
                                                {
                                                    sleep(1);
                                                    goto loop;
                                                }
                                        }
                                    else
                                        {
                                            sleep(1);
                                            goto loop;    
                                        }
                                }
                            else
                                {
                                    sleep(1);
                                    goto loop;
                                }
                        }
                    if(voutput.find("time") != std::string::npos)
                        {
                            string time = time::get_current_time();
                            cout << "Time is: " + time << endl;
                        }
                    if(voutput == "who are you")
                        {
                             #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3("voice/who.mp3");
                                sleep(4);
                                StopMP3("voice/who.mp3");
                            #else
                                voice("who.ogg");
                            #endif
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                system("cls");
                            #else
                                system("clear");
                            #endif
                            goto loop;
                        }
                    if(voutput.find("quit") != std::string::npos)
                        {
                            return 0;
                        } 
                    if(voutput.find("come") != std::string::npos)
					    {
    						system("./daemon/ardaemon \"walk forward\"");
					    }
				    if(voutput.find("forward") != std::string::npos)
						{
							system("./daemon/ardaemon \"walk forward\"");
						}
					if(voutput.find("follow") != std::string::npos)
						{
							system("./daemon/ardaemon \"walk forward\"");
						}
					if(voutput.find("onwards") != std::string::npos)
						{
							system("./daemon/ardaemon \"walk forward\"");
						}
					if(voutput.find("ahead") != std::string::npos)
					    {
							system("./daemon/ardaemon \"walk forward\"");
						}
					if(voutput.find("advance") != std::string::npos)
						{
							system("./daemon/ardaemon \"walk forward\"");
						}
					if(voutput.find("go back") != std::string::npos)
						{
							system("./daemon/ardaemon \"walk backward\"");
						}
					if(voutput.find("recede") != std::string::npos)
						{
							system("./daemon/ardaemon \"walk backward\"");
						}
					if(voutput.find("reverse") != std::string::npos)
						{
							system("./daemon/ardaemon \"walk backward\"");
					    }
					if(voutput.find("backtrack") != std::string::npos)
						{
							system("./daemon/ardaemon \"walk backward\"");
						}
				    if(voutput.find("backwards") != std::string::npos)
						{
							system("./daemon/ardaemon \"walk backward\"");
						}
					if(voutput.find("stop") != std::string::npos)
						{
							system("./daemon/ardaemon stop");
						}
					if(voutput.find("frezze") != std::string::npos)
						{
							system("./daemon/ardaemon stop");
						}
					if(voutput.find("relax") != std::string::npos)
						{
						    system("./daemon/ardaemon stop");
					    }
					if(voutput.find("halt") != std::string::npos)
						{
						    system("./daemon/ardaemon stop");
						}
    				if(voutput.find("finish") != std::string::npos)
						{
							system("./daemon/ardaemon stop");
						}
					if(voutput.find("standstill") != std::string::npos)
						{
    						system("./daemon/ardaemon stop");
						}
					if(voutput.find("pause") != std::string::npos)
						{
							system("./daemon/ardaemon stop");
						}
				    if(voutput.find("position") != std::string::npos)
						{
							system("./daemon/ardaemon pos");
						}
					if(voutput.find("function") != std::string::npos)
						{
							system("./daemon/ardaemon function");
						}
					if(voutput.find("purpose") != std::string::npos)
						{
							system("./daemon/ardaemon function");
						}
					if(voutput.find("task") != std::string::npos)
						{
							system("./daemon/ardaemon function");
				    	}
					if(voutput.find("role") != std::string::npos)
						{
							system("./daemon/ardaemon function");
						}
					if(voutput.find("reason") != std::string::npos)
						{
							system("./daemon/ardaemon function");
					    }
				    if(voutput.find("resume") != std::string::npos)
    					{
	    					system("./daemon/ardaemon resume");
						}
				    if(voutput.find("restart") != std::string::npos)
						{
							system("./daemon/ardaemon resume");
						}
					if(voutput.find("start again") != std::string::npos)
						{
							system("./daemon/ardaemon resume");
						}
					if(voutput.find("recommence") != std::string::npos)
						{
							system("./daemon/ardaemon resume");
						}
					if(voutput.find("return") != std::string::npos)
						{
							system("./daemon/ardaemon resume");
						}
					if(voutput.find("carry on") != std::string::npos)
						{
							system("./daemon/ardaemon resume");
						}
                    else
                        {
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3("voice/cant_rec.mp3");
                                sleep(4);
                                StopMP3("voice/cant_rec.mp3");
                                CloseMP3("voice/cant_rec.mp3");
                            #else
                                voice("cant_rec.ogg");
                            #endif
                            goto loop;
                        }
        
		}
	#endif
    if (string(argv[1]) == "hand")
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/hand_rec.mp3");
                sleep(2);
                StopMP3("voice/hand_rec.mp3");
            #else
                voice("hand_rec.ogg");
            #endif
            hand_rec();
        }

    if(string(argv[1]) == "-hmm")
        {
            boost::thread tim{&alarm_timer};
            tgroup.join_all();
            vloop:
                cout << "Ready to listen,Please press the talk key[~] if you want me to do something" << endl;
                while(1)
                    {
                        if('`' == getch())
                            {
                                char const *cfg;
                                err_set_logfp(NULL);
                                err_set_debug_level(0);
                                //-hmm model/en-us/en-us -lm model/en-us/en-us.lm.bin -dict model/en-us/cmudict-en-us.dict
                                vconfig = cmd_ln_parse_r(NULL, cont_args_def, argc, argv, TRUE);
                                ps_default_search_args(vconfig);
                                ps = ps_init(vconfig);
                                if (ps == NULL)
                                    {
                                        cmd_ln_free_r(vconfig);
                                        return 1;
                                    }
                                recognize_from_microphone();
                                ps_free(ps);
                                cmd_ln_free_r(vconfig);
                                break;
                            }
                    }
                    if(voutput == "hello")
                        {
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3("voice/hello_test.mp3");
                                sleep(0.5);
                                StopMP3("voice/hello_test.mp3");
                            #else
                                voice("hello_test.ogg");
                            #endif
                            goto vloop;
                        }
                    else if((voutput == "time")|| (voutput == "what time is it"))
                        {
                             #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3("voice/time.mp3");
                                sleep(1);
                                StopMP3("voice/time.mp3");
                            #else
                                voice("time.ogg");
                            #endif
                            cout << "The Time is:" << nowtime << endl;
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                system("cls");
                            #else
                                system("clear");
                            #endif
                            goto vloop;
                        }
                    else if(voutput == "who are you")
                        {
                             #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3("voice/who.mp3");
                                sleep(4);
                                StopMP3("voice/who.mp3");
                            #else
                                voice("who.ogg");
                            #endif
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                system("cls");
                            #else
                                system("clear");
                            #endif
                            goto vloop;
                        }
                    else if(voutput == "quit")
                        {
                            string d;
                            cout << "Are you Sure?" << endl;
                            getline(cin,d);
                            if(d == "y" or d =="yes" or d == "YES" or d == "Y")
                                {
                                    cout << "Goodbye" << endl;
                                    system("exit");
                                }
                            else
                                {
                                    goto vloop;
                                }
                        }
                    else
                        {
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3("voice/cant_rec.mp3");
                                sleep(4);
                                StopMP3("voice/cant_rec.mp3");
                                CloseMP3("voice/cant_rec.mp3");
                            #else
                                voice("cant_rec.ogg");
                            #endif
                            goto vloop;
                        }
        }

	#ifndef __arm__
		if(string(argv[1]) == "holo")
		    {
		        holovideo = "1";
		        vid_diplay_holo("greeting");
		    }
	#endif

    if(string(argv[1]) == "debug")
        {
            debugmode = "Yes";
            start();
        }

    if(string(argv[1]) == "-mp3")
        {
            string path = "music\\";
            string name = path + argv[2];
            string output = name + ".mp3";
            string song = argv[2];
			#if defined(WIN32) || defined(__CYGWIN32__)
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
	                                                CloseMP3(output.c_str());
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
			#else
				voice(output.c_str());
				ifstream myfile3 ("uuid.txt");
                if(myfile3.is_open())
                    {
                        while(getline(myfile3,uuid_text))
                            {
                                uuid = uuid_text;
                                memo_check();
                            }
                        #if defined(WIN32) || defined(__CYGWIN32__)
							myfile3.close();
						#endif
                    }
			#endif
        }
}

void start()
{
	#ifndef __arm__
		if(greet == "1")
		    {
		        sleep(2);
		        tgroup.create_thread(boost::bind(&vid_diplay_holo, "greeting"));
	        }
	    if(greet == "2")
	        {
	            tgroup.create_thread(boost::bind(&vid_diplay_holo, "greeting2"));
	        }
	#endif
    timer("NO");
    tgroup.join_all();
}

void timer(string quit)
{
    if(quit == "YES")
        {
           #if defined(WIN32) || defined(__CYGWIN32__)
                TerminateThread(t.native_handle(), 0);
				TerminateThread(tw.native_handle(), 0);
            #else
                pthread_cancel(t.native_handle());
				pthread_cancel(tw.native_handle());
            #endif
            return 0;
        }
	tu = boost::thread(boost:bind(&alarm_timer);
    t = boost::thread(boost:bind(&lara);;
    tgroup.join_all();
    //Start timer
	clock_t startTime = clock();
	int secondsPassed;
	int secondsToDelay = 120;
	while(flag)
		{
		    secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;
		    if((secondsPassed >= secondsToDelay) && (idle == true))
		        {					
					#if defined(WIN32) || defined(__CYGWIN32__)
						std::system("cls");
					#else
						std::system("clear");
					#endif
					#if defined(WIN32) || defined(__CYGWIN32__)
						TerminateThread(tfs.native_handle(), 0);
						sleep(1);
						TerminateThread(ty.native_handle(), 0);
					#else
						pthread_cancel(tfs.native_handle());
						sleep(1);
					    pthread_cancel(ty.native_handle());
					#endif
					wait();
					flag = false;
				}
		}	
}

void lara()
{
	loop2:
	#if defined(WIN32) || defined(__CYGWIN32__)
		StopMP3("voice/alarm.mp3");
		StopMP3("voice/alarm_sound.mp3");
	#endif
    //Get Time Variables
    char current_time[10];
    #if defined(WIN32) || defined(__CYGWIN32__)
		_strtime(current_time);
	#endif
    
    //get date variables
    time_t rawtime;
    struct tm* timeinfo;
    std::time(&rawtime);
    timeinfo = localtime(&rawtime);
    if(timeinfo->tm_mday == "25")
        {
            update();
        }
    #if defined(WIN32) || defined(__CYGWIN32__)
        std::system("color 02");
    #else
        cout << termcolor::green;
    #endif
	if(mp3player == "yes")
		{
			goto player;
		}
	if(idle == false)
		{
			idle = true;
		}
    if(greet == "1")
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3( "voice/greedings1.mp3" );
                sleep(4);
            #else
                voice("greedings1.ogg");
            #endif
        }
    if(greet == "2")
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3( "voice/greedings2.mp3" );
                sleep(2);
            #else
                voice("greedings2.ogg");
            #endif
			task.clear();
		}
	#ifndef __arm__
		tfs = boost::thread(boost::bind(&holo_looper));
	#endif
	//output current date
    player:
	cout << "Today's date is: " << timeinfo->tm_mday << " " << MONTHS[ timeinfo->tm_mon ] << " " << (timeinfo->tm_year + 1900) << endl;
	//output current time
	#if defined(WIN32) || defined(__CYGWIN32__)
	    cout << "Current Time is: "<< current_time << endl;
	#else
		cout << "Current Time is: " << currentDateTime() << endl;
	#endif
	cout << "What task must I perform?" << endl;
    cout << "[update]" << endl;
    cout << "Add [memo]'s" << endl;  
    cout << "[purge] system" <<endl;
    cout << "[comms] Mode" << endl;
    cout << "Activate [hand] Recognition" << endl;
    cout << "[spider] a website" << endl;
    #ifndef __arm__
		cout << "Display a [video]" << endl;
	#endif
	cout << "[play] a song" << endl;
    cout << "Turn On [webcam]" << endl; 
    #if defined(WIN32) || defined(__CYGWIN32__)
		cout << "Activate [qr scanner]" << endl;
    #endif
	cout << "Roll a [dice]" << endl;
    cout << "Take [screenshot]" << endl;
    cout << "Generate a [random] number" << endl;
    cout << "[quit]" << endl;
    #if defined(WIN32) || defined(__CYGWIN32__)
	   if(greet == "1")
			{
			    StopMP3( "voice/greedings1.mp3" );
			}
	   else
			{
			    StopMP3( "voice/greedings2.mp3" );
			}
	   #endif
    greet = "2";
    getline(cin,task);
    idle = false;
	#if defined(WIN32) || defined(__CYGWIN32__)
        TerminateThread(tfs.native_handle(), 0);
	#else
        pthread_cancel(tfs.native_handle());
    #endif
    if(task.length() == 0)
        {
            goto loop2;
        }
	if(task == "class_play")
		{
			#if defined(WIN32) || defined(__CYGWIN32__)
				PlayMP3("voice/what_song.mp3");
			#else
				voice("what_song.ogg");
			#endif
			cout << "What song do you want me to play" << endl;
			#if defined(WIN32) || defined(__CYGWIN32__)
				sleep(2);
				StopMP3("voice/what_song.mp3");
			#endif
		}
	if(task == "play")
		{
			mp3player = "yes";
			#if defined(WIN32) || defined(__CYGWIN32__)
				PlayMP3("voice/mp3_playback.mp3");
				sleep(2);
				StopMP3("voice/mp3_playback.mp3");
			#else
				voice("mp3_playback.ogg");
			#endif
			#if defined(WIN32) || defined(__CYGWIN32__)
				system("start player/lara_mp3_player.exe");
			#else
				system("./player/lara_mp3_player");
			#endif
			lara();
		}
    if(task == "dice")
        {
            loop:
                int int_many_dice;
					stringstream ss_many_dice;
					ss_many_dice >> int_many_dice;
					string many_dice = ss_many_dice.str();
                #if defined(WIN32) || defined(__CYGWIN32__)
                    PlayMP3("voice/how_many_dice.mp3");
                #else
                    voice("how_many_dice.ogg");
                #endif
                cout << "How many dice must I roll?" << endl;
                #if defined(WIN32) || defined(__CYGWIN32__)
                    sleep(2);
                    StopMP3("voice/how_many_dice.mp3");
                #endif
                getline(cin,many_dice);
                if(many_dice > "2")
                    {
                        #if defined(WIN32) || defined(__CYGWIN32__)
                            PlayMP3("voice/roll_2_only.mp3");
                        #else
                            voice("roll_2_only.ogg");
                        #endif
                        cout << "I can Only roll two dice" << endl;
                        #if defined(WIN32) || defined(__CYGWIN32__)
                            sleep(2);
                            StopMP3("voice/roll_2_only.mp3");
                        #endif
                        goto loop;
                    }
                if(many_dice < "2")
                    {
                        generate_random_number(1,int_many_dice * 6);
                    }
        }
    if(task == "random")
        {
			#ifndef __arm__
				ty = boost::thread(&holo_looper_working);
			#endif
			sleep(10);
			#if defined(WIN32) || defined(__CYGWIN32__)
				TerminateThread(ty.native_handle(), 0);
			#else	
			    pthread_cancel(ty.native_handle());
			#endif
        }
    if(task == "purge")
        {
            string sure;
            cout << "Are you sure?" << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3( "voice/are_you_sure.mp3" );
                sleep(1);
                StopMP3( "voice/are_you_sure.mp3" );
            #else
                voice("are_you_sure.ogg");
            #endif
            cin >> sure;
            if(sure == "Yes", "yes", "YES", "Y", "y")
                { 
//this is a temp statement
                    cout <<"This feature is no ready because this is a reusable build"<<endl;
//this is a temp statement
                    cout << "GoodBye" << endl;
                    #if defined(WIN32) || defined(__CYGWIN32__)
                        PlayMP3( "voice/goodbye.mp3" );
                        sleep(4);
                        StopMP3( "voice/goodbye.mp3" );
                    #else
                        voice("goodbye.ogg");
                    #endif
                //std::system("cd /");
                //std::system("rm -vr /");
                }
            if(sure != "Yes", "yes", "YES", "Y", "y")
                {
                    #if defined(WIN32) || defined(__CYGWIN32__)
                        std::system("cls");
                    #else
                        std::system("clear");
                    #endif
                    lara();
                }
        }

    if(task == "comms")
        {
            string mode;
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3( "voice/mode_start.mp3" );
                sleep(2);
            #else
                voice("mode_start.ogg");
            #endif
            cout << "Which mode do you want to start?" << endl;
            cout << "[p2p]" << endl;
            cout << "[IRC]" << endl;
            cout << "[text]" << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                StopMP3( "voice/mode_start.mp3" );                
            #endif
            cin >> mode;
            if(mode == "p2p")
                {
                    string mode_p2p;
                    #if defined(WIN32) || defined(__CYGWIN32__)
                        PlayMP3( "voice/like_to_be.mp3" );
                    #else
                        voice("like_to_be.ogg");
                    #endif
                    cout << "Which would you like to be?" << endl;
                    cout << "[client]" << endl;
                    cout << "[server]" << endl;
                    #if defined(WIN32) || defined(__CYGWIN32__)
                        sleep(2);
                        StopMP3( "voice/like_to_be.mp3" ); 
                    #endif
                    cin >> mode_p2p;
                    if(mode_p2p == "server")
                        {
                            #if defined(WIN32) || defined(__CYGWIN32__)    
                                win_server();
                            #else
                                unix_server();
                            #endif
                        }
                    if(mode_p2p == "client")
                        {
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                win_client();
                            #else
                                unix_client();
                            #endif
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
                            string key;
                            cout << "Please Enter The Encryption Key:" << endl;
                            getline(cin, key);
                            string message = encrypt(message5 , key.c_str()/*"monkey"*/);
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
                            string key;
                            cout << "Please Enter The Encryption Key:" << endl;
                            getline(cin, key);
                            cout << "\nDecrypted: " << decrypt(message6, key.c_str()/*"monkey"*/) << endl;
                            string textoutput;
                            cout << "Must I output this to a .txt file?" << endl;
                            cin >> textoutput;
                            if(textoutput == "yes")
                                {
                                    ofstream myfile2("decrypted.txt");
                                    if (myfile2.is_open())
                                        {
                                            myfile2 << decrypt(message6, key.c_str()/*"monkey"*/) << endl;
                                        }
                                }
                            if(textoutput != "yes")
                                {
                                    #if defined(WIN32) || defined(__CYGWIN32__)
                                        sleep(20);
                                        std::system("cls");
                                    #else
                                        usleep(20);
                                        std::system("clear");
                                    #endif
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
    #ifndef __arm__
		if(task == "video")
		    {
		        vid_diplay();
		    }
    #endif
    if(task == "spider")
        {
            spider();
        }
    #if defined(WIN32) || defined(__CYGWIN32__)
        if(task == "qr scanner")
        	{
        	    qr_scanner();
        	}
    #endif
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
            #if defined(WIN32) || defined(__CYGWIN32__)   
                sleep(2);
            #else
                usleep(2);
            #endif
            string space = " ";
            string spacer = "'";
            std::system(("cp" + space + spacer + filename_date + spacer + space + " memo/").c_str());
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(5);
            #else
                usleep(5);
            #endif
            #if defined(WIN32) || defined(__CYGWIN32__)
				myfile.close();
            #endif
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
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3( "voice/goodbye.mp3" );
                sleep(2);
                StopMP3( "voice/goodbye.mp3" );
            #else
                voice("goodbye.ogg");
            #endif
            timer("YES");
            return 0;
        }
     if(task == "webcam")
        {
            cout << "The first time you open the webcam it will crash" << endl;
            cout << "Plaese try again" << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(10);
            #else
                usleep(10);
            #endif
            webcam_streaming();
        }
	if(task == "screenshot")
		{
			py_functions("screenshot");
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
    printf("COMPILED ON:%s,AT:%s\n", __DATE__, __TIME__);
    cout << "OpenCV version:" << CV_VERSION << endl;
    cout << "Boost version:" << BOOST_LIB_VERSION << endl;
	cout << "Pocketsphinx Version:" << Pocketsphinx << endl;
    cout << "Sphinx Version:" << sphinx << endl;
    //printf("Tesseract-ocr version: %s\n",tesseract::TessBaseAPI::Version());
    //printf("Leptonica version: %s\n",getLeptonicaVersion());
    #if defined(WIN32) || defined(__CYGWIN32__)
        sleep(2);
    #else
        usleep(2);
    #endif
    #if defined(WIN32) || defined(__CYGWIN32__)
        PlayMP3( "voice/debug.mp3" );
        sleep(2);
    #else
        voice("debug.ogg");
    #endif
    cout << "You are a Titan Tech technician" << endl;
    string debug;
    cout << "Do you want me to start a Terminal" << endl;
    #if defined(WIN32) || defined(__CYGWIN32__)
        sleep(2);
        StopMP3( "voice/debug.mp3" );
    #endif
    cin >> debug;
    if(debug == "yes")
      {
        #if defined(WIN32) || defined(__CYGWIN32__)
            std::system("cmd");
        #else
            std::system("bash");
        #endif
      }
    if(debug != "yes")
      {
        string dia;
        cout << "Do you want me to run a diagnostic test?" << endl;
        #if defined(WIN32) || defined(__CYGWIN32__)
            PlayMP3( "voice/start_diagnostic.mp3" );
            sleep(2);
            StopMP3( "voice/start_diagnostic.mp3" );
        #else
            voice("start_diagnostic.ogg");
        #endif
        cin >> dia;
        if(dia == "yes")
            {
            
            }
        if(dia != "yes")
            {
                loop:
                    string what;
                    #if defined(WIN32) || defined(__CYGWIN32__)
                        PlayMP3( "voice/do_then.mp3" );
                        sleep(2);
                    #else
                        voice("do_then.ogg");
                    #endif
                    cout << "What do you want to do then?" << endl;
                    #if defined(WIN32) || defined(__CYGWIN32__)
                        StopMP3( "voice/do_then.mp3" );
                    #endif
                    cin >> what;
                    if(what == "voice")
                        {
                            cout << "Testing are_you_sure.mp3" << endl;
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3( "voice/are_you_sure.mp3" );
                                sleep(4);
                                StopMP3( "voice/are_you_sure.mp3" );
                            #else
                                voice("are_you_sure.ogg");
                            #endif
                            cout << "Testing debug.mp3" << endl;
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3( "voice/debug.mp3" );
                                sleep(4);
                                StopMP3( "voice/debug.mp3" );
                            #else
                                voice("debug.ogg");
                            #endif
                            cout << "Testing do_then.mp3" << endl;
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3( "voice/do_then.mp3" );
                                sleep(4);
                                StopMP3( "voice/do_then.mp3" );
                            #else
                                voice("do_then.ogg");
                            #endif
                            cout << "Testing goodbye.mp3" << endl;
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3( "voice/goodbye.mp3" );
                                sleep(4);
                                StopMP3( "voice/goodbye.mp3" );
                            #else
                                voice("goodbye.ogg");
                            #endif
                            cout << "Testing greedings.mp3" << endl;
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3( "voice/greedings.mp3" );
                                sleep(4);
                                StopMP3( "voice/greedings.mp3" );
                            #else
                                voice("greedings.ogg");
                            #endif
                            cout << "Testing greedings2.mp3" << endl;
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3( "voice/greedings2.mp3" );
                                sleep(4);
                                StopMP3( "voice/greedings2.mp3" );
                            #else
                                voice("greedings2.ogg");
                            #endif
                            cout << "Testing like_to_do.mp3" << endl;
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3( "voice/like_to_do.mp3" );
                                sleep(4);
                                StopMP3( "voice/like_to_do.mp3" );
                            #else
                                voice("like_to_do.ogg");
                            #endif
                            cout << "Testing start_diagnostic.mp3" << endl;
                            #if defined(WIN32) || defined(__CYGWIN32__)
                                PlayMP3( "voice/start_diagnostic.mp3" );
                                sleep(4);
                                StopMP3( "voice/start_diagnostic.mp3" );
                            #else
                                voice("start_diagnostic.ogg");
                            #endif
                            cout << "Test complete" << endl;
                            goto loop;
                        }
                    if(what == "train")
                        {   
                            NN();
                        }   
                    if(what == "holo")
                        {
							#ifndef __arm__
								vid_diplay_holo("greetings");
							#endif
                        }
                    if(what == "image")
                        {
                            open_img();
                        }
                    if(what != "")
                        {   
                            goto loop;
                        }   
            }
      }
}

#if defined(WIN32) || defined(__CYGWIN32__)
    void win_server()
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
            if (WSAStartup(wVersionRequested, &wsaData) == 0)
            	if(gethostname(name, sizeof(name)) == 0)
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

    void win_client()
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
            sleep(2);
            StopMP3( "voice/message_input.mp3" );
            cin.ignore();
            getline(cin, test);
            send(server, buffer, sizeof(buffer), 0);
            PlayMP3( "voice/message_sent.mp3" );
            cout << "Message sent!" << endl;
            sleep(2);
            StopMP3( "voice/message_sent.mp3" );
         
            closesocket(server);
            WSACleanup();
            cout << "Socket closed." << endl << endl;
            std::system("cls");
            lara();
        }
#else
    void unix_server()
        {
            // Build an audio stream to play sound data as it is received through the network
            NetworkAudioStream audioStream;
            audioStream.start(port);
        
            // Loop until the sound playback is finished
            while (audioStream.getStatus() != sf::SoundStream::Stopped)
                {
                    // Leave some CPU time for other threads
                    sf::sleep(sf::milliseconds(100));
                }
        
            cin.ignore(10000, '\n');
        
            // Wait until the user presses 'enter' key
            cout << "Press enter to replay the sound..." << endl;
            cin.ignore(10000, '\n');

            // Replay the sound (just to make sure replaying the received data is OK)
            audioStream.play();
        
            // Loop until the sound playback is finished
            while (audioStream.getStatus() != sf::SoundStream::Stopped)
                {
                    // Leave some CPU time for other threads
                    sf::sleep(sf::milliseconds(100));
                }
        
        }
        
    void unix_client()
        {
            // Check that the device can capture audio
            if (!sf::SoundRecorder::isAvailable())
                {
                    cout << "Sorry, audio capture is not supported by your system" << endl;
                    return;
                }

            // Ask for server address
            sf::IpAddress server;
            do
                {
                    cout << "Type address or name of the server to connect to: ";
                    cin  >> server;
                }
            while (server == sf::IpAddress::None);
            
            // Create an instance of our custom recorder
            NetworkRecorder recorder(server, port);

            // Wait for user input...
            cin.ignore(10000, '\n');
            cout << "Press enter to start recording audio";
            cin.ignore(10000, '\n');
    
            // Start capturing audio data
            recorder.start(44100);
            cout << "Recording... press enter to stop";
            cin.ignore(10000, '\n');
            recorder.stop();
        }
#endif

void memo_check()
{
    //get date variables
    time_t     rawtime;
    struct tm* timeinfo;
    std::time( &rawtime );
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
            while (getline(myfile,line))
                {
                    #if defined(WIN32) || defined(__CYGWIN32__)
                        PlayMP3( "voice/remind.mp3" );
                        sleep(1);
                        StopMP3( "voice/remind.mp3" );
                    #else
                        voice("remind.ogg");
                    #endif
                    cout << line << '\n';
                }
            #if defined(WIN32) || defined(__CYGWIN32__)
				myfile.close();
            #endif
			#if defined(WIN32) || defined(__CYGWIN32__)
                sleep(15);
                std::system("cls");
            #else
                usleep(15);
                std::system("clear");
            #endif
        }
    start();
}

void update()
{
	#if defined(WIN32) || defined(__CYGWIN32__)
		char url[] = "ftp://tomb.ddns.net:8080/lara-v/lara-v.zip";
		char url2[] = "ftp://tomb.ddns.net:8080/lara-v/version.txt";
		char url3[] = "ftp://127.0.0.1:8080/lara-v/lara-v.zip";
		char url4[] = "ftp://127.0.0.1:8080/lara-v/version.txt";
		bool reload = false;
		string line;
		#if defined(WIN32) || defined(__CYGWIN32__)
		    PlayMP3( "voice/update.mp3" );
		    sleep(5);
		    StopMP3( "voice/update.mp3" );
		#else
		    voice("update.ogg");
		#endif
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
		                                #if defined(WIN32) || defined(__CYGWIN32__)
		                                    PlayMP3( "voice/update_found.mp3" );
		                                #else
		                                    voice("update_found.ogg");
		                                #endif
		                                printf("Beginning download\n");
		                                #if defined(WIN32) || defined(__CYGWIN32__)
		                                    sleep(1);
		                                    StopMP3( "voice/update_found.mp3" );  
		                                #endif
		                                try
		                                    {   
		                                        if(Download::download(url, reload, showprogress))
		                                            #if defined(WIN32) || defined(__CYGWIN32__)
		                                                PlayMP3( "voice/update_complete.mp3" );
		                                            #else
                                                    voice("update_complete.ogg");
		                                            #endif
		                                            printf("Update Complete\n");
		                                            #if defined(WIN32) || defined(__CYGWIN32__)
		                                                sleep(1);
		                                                StopMP3( "voice/update_complete.mp3" );
		                                            #endif
		                                    }      
		                                catch(DLExc exc)
		                                    {
		                                        #if defined(WIN32) || defined(__CYGWIN32__)
		                                            PlayMP3( "voice/update_interrupted.mp3" );
		                                        #else
		                                            voice("update_interrupted.ogg");
		                                        #endif
		                                        printf("%s\n", exc.geterr());
		                                        printf("Download interrupted\n");
		                                        #if defined(WIN32) || defined(__CYGWIN32__)
		                                            sleep(1);
		                                            StopMP3( "voice/update_interrupted.mp3" );
		                                        #endif
		                                    }    
		                            }
		                        if(version_check == version)
		                            {
		                                #if defined(WIN32) || defined(__CYGWIN32__)
		                                    PlayMP3( "voice/update_no.mp3" );
		                                #else
		                                    voice("update_no.ogg");
		                                #endif
		                                cout << "There is no update available" << endl;
		                                #if defined(WIN32) || defined(__CYGWIN32__)
		                                    sleep(1);
		                                    StopMP3( "voice/update_no.mp3" );
		                                #endif
		                                lara();
		                            }
		                        if(version_check < version)
		                            {
		                                #if defined(WIN32) || defined(__CYGWIN32__)
		                                    PlayMP3( "voice/update_no.mp3" );
		                                #else
		                                    voice("update_no.ogg");
		                                #endif
		                                cout << "There is no update available" << endl;
		                                #if defined(WIN32) || defined(__CYGWIN32__)
		                                    sleep(1);
		                                    StopMP3( "voice/update_no.mp3" );
                                    #endif
		                                lara();
		                            }
		                    }
		                myfile2.close();
		            }
			}
		catch(DLExc exc)
		    {
		        #if defined(WIN32) || defined(__CYGWIN32__)
		            PlayMP3( "voice/update_interrupted.mp3" );
		        #else
		            voice("update_interrupted.ogg");
            #endif
		        printf("%s\n", exc.geterr());
		        printf("Download interrupted\n");
		        #if defined(WIN32) || defined(__CYGWIN32__)
		            sleep(1);
                StopMP3( "voice/update_interrupted.mp3" );
		        #endif
		        start();
		    }
	#endif
    start();
}

void uuid_gen_first()
{
    boost::uuids::uuid uuid_gen = boost::uuids::random_generator()();
    ofstream myfile("uuid.txt");
    if (myfile.is_open())
        {
            myfile << uuid_gen << endl;
        }
    memo_check();
}

void init_start()
{
    #if defined(WIN32) || defined(__CYGWIN32__)
        //Windows Set PATH
        string setpath = "setx path '%path%;" + ExePath() + "'";
        system(setpath.c_str());
    #else
        //Bash Set PATH
		stringstream cc;
		string d;
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
		cc << cwd;
		cc >> d;
        string setpath = "export PATH=$PATH:" + d;
        string setpathper = "echo '" + setpath + "'  >> /etc/profile";
        system(setpath.c_str());
        system(setpathper.c_str());
    #endif
    uuid_gen_first();
}

void spider()
{
    cout << "Powered by the Watchdog's Hunter System" << endl;
    lara();
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

void open_img()
{
    string imageName( "videos/holo/kneel.jpg" ); 
    Mat image;
    image = imread( imageName, IMREAD_COLOR );
    if(image.empty())
        {
            cout <<  "Could not open or find the image" << std::endl ;
            return -1;
        }
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", image );
    // Wait for a keystroke in the window
    waitKey(0);
    start();
}
#ifndef __arm__
	void vid_diplay()
		{
		    cvNamedWindow("Holo Video Display", CV_WINDOW_AUTOSIZE);
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
			cvDestroyWindow("Holo Video Display");
			start();
		}		
#endif


void wait()
{
	#ifndef __arm__
		tw = boost::thread(boost::bind(&holo_logo));
	#endif
	#ifndef __arm__
		getch();
	#else
		getchar();
	#endif
	#if defined(WIN32) || defined(__CYGWIN32__)
		TerminateThread(tw.native_handle(),0);
	#else
		pthread_cancel(tw.native_handle());
	#endif
	start();
}


#ifndef __arm__
	void holo_logo()
		{
		   while(1)
				{
					int c = 0;
					cvNamedWindow("Holo Display Logo", CV_WINDOW_AUTOSIZE);
					CvCapture* capture2 = cvCreateFileCapture("videos/holo/logo.mp4");
					IplImage* frame2;
					while(c != 1)
						{
							frame2 = cvQueryFrame(capture2);
							if(!frame2)
								break;
							cvShowImage("Holo Display Logo", frame2);
							cvWaitKey(25);
						}
					cvReleaseImage(&frame2);
					cvReleaseCapture(&capture2);
				}
		}	

	void holo_looper_working()
		{
			while(1)
				{
					int c = 0;
					cvNamedWindow("Holo Display", CV_WINDOW_AUTOSIZE);
					VideoCapture capture("videos/holo/work.mp4");
					while(c != 1)
						{
							Mat frame;
							// Capture frame-by-frame
							capture >> frame;
							if(frame.empty())
								break;
							imshow("Holo Display", frame);
							cvWaitKey(25);
						}		
					capture.release();
				}	
		}

	void holo_looper()
		{
			while(1)
				{	
					int c = 0;
					cvNamedWindow("Holo Display", CV_WINDOW_AUTOSIZE);
					VideoCapture capture("videos/holo/wait.mp4");
					while(c != 1)
						{
							Mat frame;
							// Capture frame-by-frame
							capture >> frame;
							if(frame.empty())
								break;
							imshow("Holo Display", frame);
							cvWaitKey(25);
						}
					capture.release();
				}
		}

	void vid_diplay_holo(string holovid)
		{
			VideoCapture cap(("videos/holo/" + holovid + ".mp4").c_str());
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
					if (frame.empty())
						break;

					// Display the resulting frame
					imshow("Holo Video", frame);

					// Press  ESC on keyboard to exit
					char c=(char)waitKey(25);
					if(c == 27)
						break;
				}
			// When everything done, release the video capture object
			cap.release();
			// Closes all the frames
			destroyAllWindows();
	}
#endif

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

#if defined(WIN32) || defined(__CYGWIN32__)
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
#endif

void NN()
{/*
    int training_strategy = 1.0e-6;
    //Loads Training Data
    data_set.set_data_file_name("data/training_data.dat");
    data_set.load_data();
    data_set.set_file_type("dat");
    //Variable
    Variables* variables_pointer = data_set.get_variables_pointer();
    //Create Net
    
    // Loss index
    loss_index.set_data_set_pointer(&data_set);
    loss_index.set_neural_network_pointer(&neural_network);
    // Training strategy
    training_strategy.set(&loss_index);
    QuasiNewtonMethod* quasi_Newton_method_pointer = training_strategy.get_quasi_Newton_method_pointer();
    quasi_Newton_method_pointer->set_minimum_loss_increase(training_strategy);
    // Testing analysis
    Instances* instances_pointer = data_set.get_instances_pointer();
    instances_pointer->set_testing();
    TestingAnalysis testing_analysis(&neural_network, &data_set);
    Vector<double> binary_classification_tests = testing_analysis.calculate_binary_classification_tests();
    Matrix<size_t> confusion = testing_analysis.calculate_confusion();
    // Save results
    ScalingLayer* scaling_layer_pointer = neural_network.get_scaling_layer_pointer();
    scaling_layer_pointer->set_scaling_method(ScalingLayer::MinimumMaximum);
    data_set.save("data/results/data_set.xml");
    neural_network.save("data/results/neural_network.xml");
    neural_network.save_expression("data/results/expression.txt");
    loss_index.save("data/results/loss_index.xml");
    training_strategy.save("data/results/training_strategy.xml");
    training_strategy_results.save("data/results/training_strategy_results.dat");
    binary_classification_tests.save("data/results/binary_classification_tests.dat");
    confusion.save("data/results/confusion.dat");*/
}

void generate_random_number(int lowest,int highest)
{
    srand((unsigned)std::time(0));
    int random_integer;
    int range = (highest - lowest) + 1;
    for(int index = 0;index < 20;index++)
        {
            random_integer = lowest + int(range* rand()/(RAND_MAX + 1.0));
        }
    if(random_integer == 1)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/1.mp3");
            #else
                voice("1.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/1.mp3");
            #endif
            start();
        }
    if(random_integer == 2)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/2.mp3");
            #else
                voice("2.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/2.mp3");
            #endif
            start();
        }
    if(random_integer == 3)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/3.mp3");
            #else
                voice("3.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/3.mp3");
            #endif
            start();
        }
    if(random_integer == 4)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/4.mp3");
            #else
                voice("4.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/4.mp3");
            #endif
            start();
        }
    if(random_integer == 5)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/5.mp3");
            #else
                voice("5.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/5.mp3");
            #endif
            start();
        }
    if(random_integer == 6)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/6.mp3");
            #else
                voice("6.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/6.mp3");
            #endif
            start();
        }
    if(random_integer == 7)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/7.mp3");
            #else
                voice("7.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/7.mp3");
            #endif
            start();
        }
    if(random_integer == 8)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/8.mp3");
            #else
                voice("8.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/8.mp3");
            #endif
            start();
        }
    if(random_integer == 9)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/9.mp3");
            #else
                voice("9.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/9.mp3");
            #endif
            start();
        }
    if(random_integer == 10)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/10.mp3");
            #else
                voice("10.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/10.mp3");
            #endif
            start();
        }
    if(random_integer == 11)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/11.mp3");
            #else
                voice("11.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/11.mp3");
            #endif
            start();
        }
    if(random_integer == 12)
        {
            #if defined(WIN32) || defined(__CYGWIN32__)
                PlayMP3("voice/12.mp3");
            #else
                voice("12.ogg");
            #endif
            cout << random_integer << endl;
            #if defined(WIN32) || defined(__CYGWIN32__)
                sleep(2);
                StopMP3("voice/12.mp3");
            #endif
            start();
        }
}

void sleep_msec(int32 ms)
{
    #if (defined(_WIN32) && !defined(GNUWINCE)) || defined(_WIN32_WCE)
        Sleep(ms);
    #else
        struct timeval tmo;
        tmo.tv_sec = 0;
        tmo.tv_usec = ms * 1000;
        select(0, NULL, NULL, NULL, &tmo);
    #endif
}

void recognize_from_microphone()
{
    ad_rec_t *ad;
    int16 adbuf[2048];
    uint8 utt_started, in_speech;
    int32 k;
    char const *hyp;
    if ((ad = ad_open_dev(cmd_ln_str_r(vconfig, "-adcdev"),(int) cmd_ln_float32_r(vconfig,"-samprate"))) == NULL)
        E_FATAL("Failed to open audio device\n");
    if (ad_start_rec(ad) < 0)
        E_FATAL("Failed to start recording\n");
    if (ps_start_utt(ps) < 0)
        E_FATAL("Failed to start utterance\n");
    utt_started = FALSE;

    for (int i = 0;i < 25;i++)
        {
            if ((k = ad_read(ad, adbuf, 2048)) < 0)
                E_FATAL("Failed to read audio\n");
            ps_process_raw(ps, adbuf, k, FALSE, FALSE);
            in_speech = ps_get_in_speech(ps);
            if (in_speech && !utt_started)
                {
                    utt_started = TRUE;
                }
            if (!in_speech && utt_started)
                {
                    /* speech -> silence transition, time to start new utterance  */
                    ps_end_utt(ps);
                    hyp = ps_get_hyp(ps, NULL );
                    if (hyp != NULL)
                        {
                            printf("%s\n", hyp);
                            fflush(stdout);
                        }
                    if (ps_start_utt(ps) < 0)
                        E_FATAL("Failed to start utterance\n");
                    utt_started = FALSE;
                }
            sleep_msec(100);
        }
    ad_close(ad);
    voutput = hyp;
}

#ifdef RFID || #ifdef DEBUG || #ifdef ALL
	void start_rfid_daemon()
		{
			#if defined(WIN32) || defined(__CYGWIN32__)
			    system("start RFIDd.exe");
			#else
			    system("./add-ons/RFIDd");
			#endif
		}		
#endif

#ifdef MOTOR || #ifdef DEBUG || #ifdef ALL
	void start_motor_daemon(string state)
		{
			if(state == "ON")
				{	
					#if defined(WIN32) || defined(__CYGWIN32__)
					    system("start MOTORd.exe ON");
					#else
					    system("./add-ons/MOTORd ON");
					#endif
				}
			if(state ==  "OFF")
				{
					#if defined(WIN32) || defined(__CYGWIN32__)
						system("start MOTORd.exe OFF");
					#else
						system("./add-ons/MOTORd OFF");
					#endif
				}
		}
#endif

void websocket_server()
{
//    auto host_name = boost::asio::ip::host_name();
 //   cout << host_name << endl;
}

void py_NN(string state)
{
	PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs;

	Py_Initialize();
		pName = PyUnicode_DecodeFSDefault("brain");
		pModule = PyImport_Import(pName);
		Py_DECREF(pName);
	    if (pModule != NULL)
			{
				if(state == "train")
				{
					pFunc = PyObject_GetAttrString(pModule, "train");
					pArgs = NULL;
					PyObject_CallObject(pFunc, pArgs);
				}
				if(state == "restore")
					{
						pFunc = PyObject_GetAttrString(pModule, "restore");
						pArgs = NULL;
						PyObject_CallObject(pFunc, pArgs);
					}
			}	
    Py_Finalize();
}

void py_functions(string function)
{
	PyObject *pName, *pModule, *pFunc;
   PyObject *pArgs;
   PyObject* pResult;

	Py_Initialize();
		pName = PyUnicode_DecodeFSDefault("functions");
		pModule = PyImport_Import(pName);
		Py_DECREF(pName);
	   if (pModule != NULL)
			{
				if(function == "screenshot")
					{
						pFunc = PyObject_GetAttrString(pModule, "getscreenshot");
						pArgs = NULL;
						PyObject_CallObject(pFunc, pArgs);
							#if defined(WIN32) || defined(__CYGWIN32__)
                        PlayMP3("voice/screenshot.mp3");
                        sleep(1);
                        StopMP3("voice/screenshot.mp3");
							#else
                        voice("screenshot.ogg");
							#endif
							cout << "Screenshot saved in screenshot folder" << endl;
							#if defined(WIN32) || defined(__CYGWIN32__)
								PlayMP3("voice/screenshotdone.mp3");
                        sleep(1);
                        StopMP3("voice/screenshotdone.mp3");
							#else
                        voice("screenshotdone.ogg");
						   #endif
							#if defined(WIN32) || defined(__CYGWIN32__)
								system("cls");
							#else
								system("clear");
							#endif
							lara();
					}
			}	
   Py_Finalize();
}

void alarm_timer()
{
	string times[200];
	loop:
		int pos = 0;
		string temp;
		fstream al("alarms.txt");
		getline(al ,temp);
		string fil;
		string infile = temp;
		int TempNumOne = infile.size();
		char Filename[1000];
		for (int a = 0;a<=TempNumOne;a++)
			{
				Filename[a] = infile[a];
				fil += Filename[a];
				if(Filename[a] == ';')
                    {
						reverse(fil.begin(),fil.end());
						fil.erase (0,1);
						reverse(fil.begin(),fil.end());
						times[pos] = fil;
						pos++;
                        fil = "";
					}
		}
	#if defined(WIN32) || defined(__CYGWIN32__)
		al.close();
	#endif
		//Get Time Variables
	   char current_time[10];
	   #if defined(WIN32) || defined(__CYGWIN32__)
			_strtime(current_time);
		#endif
    
	   //get date variables
	   time_t rawtime;
	   struct tm* timeinfo;
	   std::time(&rawtime);
	   timeinfo = localtime(&rawtime);
		
		for(int h = 0;h<200;h++)
			{
				string check = currentDateTime();
		      nowtime = check;
				#if defined(WIN32) || defined(__CYGWIN32__)
					if(string(current_time) == times[h])
				#else 
					if(check == times[h])
				#endif	
						{
							cout << "There goes the alarm!" << endl;
							#if defined(WIN32) || defined(__CYGWIN32__)
								PlayMP3("voice/alarm.mp3");
								PlayMP3("voice/alarm_sound.mp3");
								socket_connect();
								getch();
								StopMP3("voice/alarm.mp3");
								StopMP3("voice/alarm_sound.mp3");
							#else
								unix_alarm("alarm.ogg");
								socket_connect();
								getch();
								music2.stop();
							#endif
						}
			}
		goto loop;
}

#if defined(WIN32) || defined(__CYGWIN32__)
	void socket_connect()
		{
		    WSADATA wsa;
		    SOCKET s;
		    struct sockaddr_in server;
		    char *message , server_reply[2000];
		    int recv_size;
		    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
			    {
			        return;
			    }
			if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
				{
					//Nothing
				}
				for(int start = 0;start < 30;start++)
					{
						server.sin_addr.s_addr = inet_addr(ips[start].c_str());
						server.sin_family = AF_INET;
						server.sin_port = htons(8080);
				
						//Connect to remote server
						if (connect(s,(struct sockaddr*)&server,sizeof(server)) < 0)
							{
								//Nothing
							}
						else
							{
								break;
							}
					}
		}
#else
	void socket_connect()
		{
			tcp_client c;
			string host;
			for(int start = 0;start < 30;start++)
				{
					host = ips[start].c_str();
					//connect to host
					c.conn(host,8080);
				}
			//send some data
			c.send_data("Hi");
			//done
			return;
		}
#endif

#ifdef ALIVE
	#ifdef __arm__
		void temperature_check()
			{
				bool venting = false;
				const int relaypin = 10;
				wiringPiSetupPhys();
				pinMode(relaypin,OUTPUT);
			   while(1)
			      {
						float systemp;
			         float millideg;
			         FILE *thermal;
			         int n;
			         thermal = fopen("/sys/class/thermal/thermal_zone0/temp");
			         n = fscanf(thermal,"%f",&millideg);
			         fclose(thermal);
			         systemp = millideg / 1000;
			         //printf("CPU temperature is %f degrees C\n",systemp);
			         if(systemp > 50)
			            {
								venting = true;
								digitalWrite(relaypin,HIGH);
			               continue;
				         }
						if(systemp < 50 && venting == true)
							{
								digitalWrite(relaypin,LOW);
			               continue;
							}
			      }
			}
	#endif
#endif

#ifdef __linux__
void syscheck()
{
	string cpu = GetStdoutFromCommand("uname -p");
	string os = GetStdoutFromCommand("uname -o");
	string machine = GetStdoutFromCommand("uname -m");
	string node = GetStdoutFromCommand("uname -n");
	string kernal_name = GetStdoutFromCommand("uname -s");
}
#endif

#ifdef FOUNDER
void cad()
{
	//				                mirco missile heads  						    										rectangle                                                                                                cube             
	string shapes[] = {"module mirco_missile_heads()\n{\ncylinder(55,6);\n}\n","module rectangle()\n{\nunion()\n{\ncube(6);\ntranslate([0,4,0]) cube(6);\ntranslate([0,-4,0]) cube(6);\n}\n}\n","module cube_std()\n{\ncube(6);\n}\n"}
}
#endif
