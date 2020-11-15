#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<unistd.h>
#include<iostream>
#include<fstream>

using namespace std;


void send_cmd(string cmd)
{
    FILE *file;
    file = fopen("/dev/ttyACM0","w");
    fprintf(file,"%s",cmd.c_str());
    fclose(file);
}

int main(int argc,char* argv[])
{
    ifstream port("/dev/ttyACM0");
    if(!port)
        {
            #ifdef DEBUG
                cout << "I can't connect to the Device" << endl;
            #endif
            return false;
        }
    else
        {
            send_cmd(argv[1]);
        }
}
