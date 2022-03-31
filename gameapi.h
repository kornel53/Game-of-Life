#ifndef GAMEAPI_H
#define GAMEAPI_H

#include <windows.h>
#include "gameoflife.h"

//----------------------------------------------------------------------
//----------------------------------------------------------------------
class GameApi : public GameOfLife
{
  public:
      GameApi();
      virtual ~GameApi();
      void InitApi(HWND hwnd, const char* fName);
      virtual void view();
  private:
      HDC _hdc;
      HWND _hwnd;
      HBRUSH _MyBrush, _BgBrush;
  private:
      GameApi(const GameApi& g);
      GameApi& operator=(const GameApi& g);
};
//======================================================================

#endif
