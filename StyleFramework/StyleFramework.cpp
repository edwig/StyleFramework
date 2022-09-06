////////////////////////////////////////////////////////////////////////
//
// File: StyleFrameWork.cpp
// Function: General header of the StylingFramework
//
//   _____ _         _ _             ______                                           _    
//  / ____| |       | (_)           |  ____|                                         | |   
// | (___ | |_ _   _| |_ _ __   __ _| |__ _ __ __ _ _ __ ___   _____      _____  _ __| | __
//  \___ \| __| | | | | | '_ \ / _` |  __| '__/ _` | '_ ` _ \ / _ \ \ /\ / / _ \| '__| |/ /
//  ____) | |_| |_| | | | | | | (_| | |  | | | (_| | | | | | |  __/\ V  V / (_) | |  |   < 
// |_____/ \__|\__, |_|_|_| |_|\__, |_|  |_|  \__,_|_| |_| |_|\___| \_/\_/ \___/|_|  |_|\_\
//              __/ |           __/ |                                                      
//             |___/           |___/                                                       
//
//
// Author: ir. W.E. Huisman
// For license: See the file "LICENSE.txt" in the root folder
//
#include "stdafx.h"

// Factor to resize ALL fonts, dialogs and controls
static int g_sfx_factor = 100;

// Setting the size factor
// To be called in your main program or InitInstance **BEFORE** you create any dialog or window
bool 
SetSFXSizeFactor(int p_factor)
{
  if(p_factor > 50 && p_factor < 1000)
  {
    g_sfx_factor = p_factor;
    return STYLEFONTS.SetFactor(p_factor);
  }
  return false;
}

int GetSFXSizeFactor()
{
  return g_sfx_factor;
}

void
SFXResizeByFactor(CRect& p_rect)
{
  p_rect.top    = (p_rect.top    * g_sfx_factor) / 100;
  p_rect.bottom = (p_rect.bottom * g_sfx_factor) / 100;
  p_rect.left   = (p_rect.left   * g_sfx_factor) / 100;
  p_rect.right  = (p_rect.right  * g_sfx_factor) / 100;
}

void 
SFXResizeByFactor(int& p_x,int& p_y,int& p_w,int& p_h)
{
  p_x = (p_x * g_sfx_factor) / 100;
  p_y = (p_y * g_sfx_factor) / 100;
  p_w = (p_w * g_sfx_factor) / 100;
  p_h = (p_h * g_sfx_factor) / 100;
}
