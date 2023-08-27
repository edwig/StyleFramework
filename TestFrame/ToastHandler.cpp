//////////////////////////////////////////////////////////////////////////
//
// EXAMPLE OF A WinToast HANDLER CLASS
// Extend at your own convenience
//
//////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ToastHandler.h"
#include "MainFrm.h"

WinToastHandler::WinToastHandler(CDialogEx* p_dialog) 
                :m_dialog(p_dialog)
{
}

WinToastHandler::WinToastHandler(MainFrame* p_mainFrame)
                :m_mainFrame(p_mainFrame)
{
}

WinToastHandler::WinToastHandler(CWinAppEx* p_winapp)
                :m_winapp(p_winapp)
{
}

void
WinToastHandler::toastActivated() const 
{
  if(m_dialog)
  {
    m_dialog->MessageBox(_T("toastActivated: No button clicked!"),_T("info"), MB_OK | MB_SETFOREGROUND);
    return;
  }
  if(m_mainFrame)
  {
    m_mainFrame->PostMessage(WM_TOASTMSG,(WPARAM)-1,(LPARAM)-1);
  }
  if(!m_winapp)
  {
    CWnd* wnd = m_winapp->GetMainWnd();
    if(wnd)
    {
      wnd->PostMessage(WM_TOASTMSG,(WPARAM)-1,(LPARAM)-1);
    }
  }
}

void 
WinToastHandler::toastActivated(int actionIndex) const
{
  if (m_dialog)
  {
    CString activated;
    activated.Format(_T("Button clicked: %d"), actionIndex);
    m_dialog->MessageBox(activated, _T("Info"), MB_OK | MB_SETFOREGROUND);
  }
  if(m_mainFrame)
  {
    m_mainFrame->PostMessage(WM_TOASTMSG,actionIndex,(LPARAM)-1);
  }
  if(m_winapp)
  {
    CWnd* wnd = m_winapp->GetMainWnd();
    if(wnd)
    {
      wnd->PostMessage(WM_TOASTMSG, actionIndex,(LPARAM)-1);
    }
  }
}

void 
WinToastHandler::toastDismissed(WinToastDismissalReason state) const
{
  std::string reason = "Dismissal error!";
  switch(state)
  {
    case UserCanceled:      reason = "Toast dismissed: UserCanceled\n";      break;
    case ApplicationHidden: reason = "Toast dismissed: ApplicationHidden\n"; break;
    case TimedOut:          reason = "Toast dismissed: TimedOut\n";          break;
  }
  OutputDebugString(CA2W(reason.c_str()));

  if(m_dialog)
  {
    m_dialog->PostMessage(WM_TOASTMSG,(WPARAM)-1,(LPARAM)state);
  }
  if(m_mainFrame)
  {
    m_mainFrame->PostMessage(WM_TOASTMSG,(WPARAM)-1,(LPARAM)state);
  }
  if(m_winapp)
  {
    CWnd* wnd = m_winapp->GetMainWnd();
    if(wnd)
    {
      wnd->PostMessage(WM_TOASTMSG,(WPARAM)-1,(LPARAM)state);
    }
  }
}

void 
WinToastHandler::toastFailed() const
{
  OutputDebugString(CA2W("toastFailed() called\n"));
}
