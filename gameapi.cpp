#include "gameapi.h"


//----------------------------------------------------------------------
GameApi::GameApi() { }
//----------------------------------------------------------------------
void GameApi::view()
{
    // Windows API implementation
//   InvalidateRect(_hwnd, NULL, true);
   for(int i=0; i<width; i++) {
      for(int j=0; j<height; j++) {
         if(board[i][j]) (HBRUSH)::SelectObject( _hdc, _BgBrush );
         else (HBRUSH)::SelectObject( _hdc, _MyBrush );

//         Rectangle( _hdc, i*width, j*height, i*width+height, j*height+height );
         Ellipse( _hdc, i*width, j*height, i*width+height, j*height+height );
      }
   }
   Sleep(200);
}
//----------------------------------------------------------------------
void GameApi::InitApi(HWND hwnd, const char* fName)
{
    // Init game board
    GameOfLife::init(fName);
// 5. Brush
   _hwnd = hwnd;
   _hdc = GetDC( _hwnd );
   _MyBrush = ::CreateSolidBrush(0x00fff000);
   _BgBrush = ::CreateSolidBrush(0x00000fff);
//   _BgBrush = (HBRUSH)::SelectObject( _hdc, WHITE_BRUSH );
}

GameApi::~GameApi()
{
//   ::DeleteObject( _MyBrush );
//   ::DeleteObject( _BgBrush );
}
//======================================================================
