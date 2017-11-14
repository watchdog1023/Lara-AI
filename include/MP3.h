#ifndef MP3                      
#define MP3

#include <windows.h>
#include <stdio.h>

namespace mp3
{
void PlayMP3(char* _MP3_path)
{
     char MP3CmdOp[40] = "open ";
     strcat(MP3CmdOp,_MP3_path);
     strcat(MP3CmdOp," type mpegvideo");
     
     char MP3CmdPl[40] = "play ";
     strcat(MP3CmdPl,_MP3_path);
     strcat(MP3CmdPl," repeat");
     
     mciSendString( MP3CmdOp,0,0,0 );
     mciSendString( MP3CmdPl,0,0,0 );
}

void CloseMP3(char* _MP3_path)
{
     char MP3CmdCl[40] = "close ";
     strcat(MP3CmdCl,_MP3_path);
     mciSendString(MP3CmdCl,0,0,0);
} 

void PauseMP3(char* _MP3_path)
{
     char MP3CmdRe[40] = "resume ";
     strcat(MP3CmdRe,_MP3_path);
     mciSendString(MP3CmdRe,0,0,0);
} 
 
void ResumeMP3(char* _MP3_path)
{
     char MP3CmdPa[40] = "pause ";
     strcat(MP3CmdPa,_MP3_path);
     mciSendString(MP3CmdPa,0,0,0); 
} 
   
void StopMP3(char* _MP3_path)
{
     char MP3CmdSt[40] = "stop ";
     strcat(MP3CmdSt,_MP3_path);
     mciSendString(MP3CmdSt,0,0,0);
} 

void GoFullScreenMode(void)
{
     keybd_event(VK_MENU,0x38,0,0);
     keybd_event(VK_RETURN,0x1C,0,0);
     keybd_event(VK_RETURN,0x1C,KEYEVENTF_KEYUP,0);
     keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); 
     Sleep(10);  
}

void CursorCoordxy(int x,int y)
{
     HANDLE curs = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD cursor;
     cursor.X = x;
     cursor.Y = y;
     SetConsoleCursorPosition(curs,cursor);
}

void ChangeColor(int color)
{
     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,color);
}
}
#endif