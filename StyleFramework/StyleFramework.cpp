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

// The one-and-only global styling object
StylingFramework g_styling;

StylingFramework::StylingFramework()
{
  if(m_instance || &g_styling != this)
  {
    throw CString(_T("SFX can only be initialized once!"));
  }
  m_instance = this;

  // Getting all monitors and fonts
  m_monitors.DiscoverAllMonitors();
}

const StyleMonitor* 
StylingFramework::GetMonitor(HWND p_hwnd) const
{
  HMONITOR hMonitor = ::MonitorFromWindow(p_hwnd,MONITOR_DEFAULTTONEAREST);
  if(hMonitor)
  {
    return GetMonitor(hMonitor);
  }
  return nullptr;
}

const StyleMonitor*
StylingFramework::GetMonitor(HMONITOR p_monitor) const
{
  return m_monitors.GetMonitor(p_monitor);
}

const StyleMonitor* 
StylingFramework::GetPrimaryMonitor() const
{
  return m_monitors.GetPrimaryMonitor();
}

void
SFXResizeByFactor(HWND p_hwnd,CRect& p_rect)
{
  const StyleMonitor* monitor = g_styling.GetMonitor(p_hwnd);
  if(!monitor)
  {
    return;
  }
  int dpi_x;
  int dpi_y;
  monitor->GetDPI(dpi_x,dpi_y);
  int factorx = (dpi_x * 100) / USER_DEFAULT_SCREEN_DPI;
  int factory = (dpi_y * 100) / USER_DEFAULT_SCREEN_DPI;

  p_rect.top    = (p_rect.top    * factorx) / 100;
  p_rect.bottom = (p_rect.bottom * factory) / 100;
  p_rect.left   = (p_rect.left   * factorx) / 100;
  p_rect.right  = (p_rect.right  * factory) / 100;
}

void 
SFXResizeByFactor(HWND p_hwnd,int& p_x,int& p_y,int& p_w,int& p_h)
{
  const StyleMonitor* monitor = g_styling.GetMonitor(p_hwnd);
  if(!monitor)
  {
    return;
  }
  int dpi_x;
  int dpi_y;
  monitor->GetDPI(dpi_x,dpi_y);
  int factorx = (dpi_x * 100) / USER_DEFAULT_SCREEN_DPI;
  int factory = (dpi_y * 100) / USER_DEFAULT_SCREEN_DPI;

  p_x = (p_x * factorx) / 100;
  p_y = (p_y * factory) / 100;
  p_w = (p_w * factorx) / 100;
  p_h = (p_h * factory) / 100;
}

int GetSFXSizeFactor(HWND p_hwnd)
{
  const StyleMonitor* monitor = g_styling.GetMonitor(p_hwnd);
  if(!monitor)
  {
    return 100;
  }
  int dpi_x;
  int dpi_y;
  monitor->GetDPI(dpi_x,dpi_y);
  return (dpi_y * 100) / USER_DEFAULT_SCREEN_DPI;
}

// Global function to get the correct font for a window
// based on its monitor
CFont*
GetSFXFont(HWND p_hwnd,StyleFontType p_type)
{
  const StyleMonitor* monitor = g_styling.GetMonitor(p_hwnd);
  if(monitor)
  {
    StyleFonts& fonts = const_cast<StyleFonts&>(monitor->GetFonts());
    return fonts.GetFont(p_type);
  }
  return nullptr;
}

CFont* 
GetSFXFont(HMONITOR hm,StyleFontType p_type)
{
  const StyleMonitor* monitor = g_styling.GetMonitor(hm);
  if(monitor)
  {
    StyleFonts& fonts = const_cast<StyleFonts&>(monitor->GetFonts());
    return fonts.GetFont(p_type);
  }
  return nullptr;
}
