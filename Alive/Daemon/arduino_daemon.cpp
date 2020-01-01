#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<unistd.h>

using namespace std;

int delay_time = 2000000;

void send_cmd(string cmd)
{
    FILE *file;
    file = fopen("/dev/ttyACM0","w");
    fprintf(file,"%s",cmd.c_str());
    fclose(file);
}

int main(int argc,char* argv[])
{
send_cmd(argv[1]);
}
