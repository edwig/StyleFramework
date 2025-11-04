////////////////////////////////////////////////////////////////////////
//
// File: StyleMonitor.h
// Function: Connected monitors to the system
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
#pragma once
#include <vector>
#include "StyleFonts.h"

class StyleMonitor
{
public:
  StyleMonitor(HMONITOR p_handle
              ,CString  p_name
              ,RECT     p_rect
              ,bool     p_primary);
 ~StyleMonitor() = default;

 void InitMonitor();

  // GETTERS
  const HMONITOR    GetMonitor()   const;
  const CString     GetName()      const; 
  const CRect       GetRect()      const;
  const bool        GetIsPrimary() const;
  const bool        GetIsMarked()  const;
  const StyleFonts& GetFonts()     const;
  const int         GetHeight()    const;
  const int         GetWidth()     const;
  void              GetDPI(int& p_dpi_x,int& p_dpi_y) const;

  void SetAsMarked(bool p_mark = true);

private:
  HMONITOR   m_monitor;
  CString    m_name;
  CRect      m_rect;
  bool       m_primary;
  bool       m_mark { false };

  StyleFonts m_fonts;
  int        m_dpi_x { USER_DEFAULT_SCREEN_DPI };
  int        m_dpi_y { USER_DEFAULT_SCREEN_DPI };
};

using MonitorMap = std::vector<StyleMonitor*>;

//////////////////////////////////////////////////////////////////////////
//
// StyleMonitors: Handling of multiple StyleMonitor objects
//
////////////////////////////////////////////////////////////////////////

class StyleMonitors
{
public:
  StyleMonitors() = default;
 ~StyleMonitors();
  
  bool DiscoverAllMonitors();
  void ReDiscoverMonitors();
  bool TryAddMonitor(StyleMonitor* p_monitor);

  // GETTERS
  const MonitorMap&   GetMonitors() const;
  const StyleMonitor* GetPrimaryMonitor() const;
  const StyleMonitor* GetMonitor(HMONITOR p_monitor) const;
  const StyleMonitor* GetMonitor(int p_dpi_x,int p_dpi_y) const;

private:
  void UnMarkAllMonitors();
  void CleanupRemovedMonitors();

  MonitorMap    m_monitors;
  StyleMonitor* m_primaryMonitor { nullptr };
};

