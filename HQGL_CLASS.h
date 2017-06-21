// By The Hidden Ghost
#ifndef HQGL_CLASS                      
#define HQGL_CLASS

#include <windows.h>
#include <stdio.h>

class HQGL {
      
private:
              
public:
    
void HQPlayMP3( char* _MP3_path )
{
     
     char MP3CmdOp[40] = "open ";
     strcat( MP3CmdOp,_MP3_path );
     strcat( MP3CmdOp," type mpegvideo" );
     
     char MP3CmdPl[40] = "play ";
     strcat( MP3CmdPl,_MP3_path );
     strcat( MP3CmdPl," repeat" );
     
     mciSendString( MP3CmdOp,0,0,0 );
     mciSendString( MP3CmdPl,0,0,0 );
}

void HQCloseMP3( char* _MP3_path )
{
     char MP3CmdCl[40] = "close ";
     strcat( MP3CmdCl,_MP3_path );
     mciSendString( MP3CmdCl,0,0,0 );
} 

void HQPauseMP3( char* _MP3_path )
{
     char MP3CmdRe[40] = "resume ";
     strcat( MP3CmdRe,_MP3_path );
     mciSendString( MP3CmdRe,0,0,0 );
} 
 
void HQResumeMP3( char* _MP3_path )
{
     char MP3CmdPa[40] = "pause ";
     strcat( MP3CmdPa,_MP3_path );
     mciSendString( MP3CmdPa,0,0,0 ); 
} 
   
void HQStopMP3( char* _MP3_path )
{
     char MP3CmdSt[40] = "stop ";
     strcat( MP3CmdSt,_MP3_path );
     mciSendString( MP3CmdSt,0,0,0 );
} 

void HQGoFullScreenMode( void )
{
     keybd_event(VK_MENU,0x38,0,0);
     keybd_event(VK_RETURN,0x1C,0,0);
     keybd_event(VK_RETURN,0x1C,KEYEVENTF_KEYUP,0);
     keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0); 
     Sleep( 10 );  
}

void HQCursorCoordxy( int x,int y )
{
     HANDLE curs = GetStdHandle( STD_OUTPUT_HANDLE );
     COORD cursor;
     cursor.X = x;
     cursor.Y = y;
     SetConsoleCursorPosition( curs,cursor );
}

void HQChangeColor( int color )
{
     HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
     SetConsoleTextAttribute( h,color );
}

};

#endif
