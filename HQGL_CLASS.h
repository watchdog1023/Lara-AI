// By The Hidden Ghost
#ifndef HQGL_CLASS                      
#define HQGL_CLASS

#include <windows.h>
#include <stdio.h>

class HQGL {
      
private:
              
public:
    
void HQGL::HQPlayMP3( char* _MP3_path )
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

void HQGL::HQCloseMP3( char* _MP3_path )
{
     char MP3CmdCl[40] = "close ";
     strcat( MP3CmdCl,_MP3_path );
     mciSendString( MP3CmdCl,0,0,0 );
} 

void HQGL::HQPauseMP3( char* _MP3_path )
{
     char MP3CmdRe[40] = "resume ";
     strcat( MP3CmdRe,_MP3_path );
     mciSendString( MP3CmdRe,0,0,0 );
} 
 
void HQGL::HQResumeMP3( char* _MP3_path )
{
     char MP3CmdPa[40] = "pause ";
     strcat( MP3CmdPa,_MP3_path );
     mciSendString( MP3CmdPa,0,0,0 ); 
} 
   
void HQGL::HQStopMP3( char* _MP3_path )
{
     char MP3CmdSt[40] = "stop ";
     strcat( MP3CmdSt,_MP3_path );
     mciSendString( MP3CmdSt,0,0,0 );
} 

void HQGL::HQGoFullScreenMode( void )
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

//HQConstructor( );
//~HQDestructor( );
};

class HQRECTANGLE {

private: 
         
public:

void HQRECTANGLE::HQDrawRect( int x,int y,int AB,int AC,int CD,int BD,int color )
{
     int d,y1,y2,x1;
     HANDLE Rect = GetStdHandle( STD_OUTPUT_HANDLE );
     COORD cursor = { x,y };
     y1 = y + 1;
     y2 = y;
     x1 = x;
     SetConsoleTextAttribute( Rect,color ); 
     SetConsoleCursorPosition( Rect,cursor );
     for( d = 0;d <= AB;d++ )
          printf( "%lc",196 );
     cursor.X = x + AB;
     SetConsoleCursorPosition( Rect,cursor );
     printf( "%lc",191 );
     for( d = 0;d <= BD;d++ ){
          cursor.X = x + AB;cursor.Y = y + 1;
          SetConsoleCursorPosition( Rect,cursor );
          printf( "%lc",179 );
          y++;
     }
     for( d = 0;d <= CD-1;d++ ){
          cursor.X = x;cursor.Y = y + 1;
          SetConsoleCursorPosition( Rect,cursor );
          printf( "%lc",196 );
          x++;
     }
     cursor.X = x1 + CD;cursor.Y = y2 + ( BD + 2 );
     SetConsoleCursorPosition( Rect,cursor );
     printf( "%lc",217 );
     for( d = 0;d <= AC;d++ ){
          cursor.X = x - AB - 1;cursor.Y = y1;
          SetConsoleCursorPosition( Rect,cursor );
          printf( "%lc",179 );
          y1++;
     }
     cursor.X = x - AB - 1;cursor.Y = y2;
     SetConsoleCursorPosition( Rect,cursor );
     printf( "%lc",218 );
     cursor.X = x - AB - 1;cursor.Y = y1;
     SetConsoleCursorPosition( Rect,cursor );
     printf( "%lc",192 );
}};

class HQLINE {

private:

public:
       
void HQDrawLinexy( int x,int y,int HORIZ_OR_VERT,int length,int color )
{
     int x1;
     HANDLE Line = GetStdHandle( STD_OUTPUT_HANDLE );
     COORD cursor = { x,y };
     SetConsoleTextAttribute( Line,color );
     if( HORIZ_OR_VERT == 1 ){
         SetConsoleCursorPosition( Line,cursor );
         for( x1 = 0;x1 <= length;x1++ )
              printf( "%lc",196 ); // Horizontal Line
     }
     else if( HORIZ_OR_VERT == 2 ){
          for( x1 = 0;x1 <= length;x1++ ){
               cursor.X = x;
               cursor.Y = y;
               SetConsoleCursorPosition( Line,cursor );
               printf( "%lc",179 );// vertical Line
               y++;
          }
     }
}};

#endif
