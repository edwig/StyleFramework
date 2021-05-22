//////////////////////////////////////////////////////////////////////////
//
// EXAMPLE OF A WinToast HANDLER CLASS
// Extend at your own convenience
//
//////////////////////////////////////////////////////////////////////////

#pragma once
#include "WinToastLib.h"

#define WM_TOASTMSG  (WM_USER + 714)

class MainFrame;

class WinToastHandler : public WinToastLib::IWinToastHandler
{
public:
  WinToastHandler(CDialogEx* p_dialog);
  WinToastHandler(MainFrame* p_mainFrame);
  WinToastHandler(CWinAppEx* p_winapp);
  // Public interfaces
  virtual void toastActivated() const override;
  virtual void toastActivated(int actionIndex) const override;
  virtual void toastDismissed(WinToastDismissalReason state) const override;
  virtual void toastFailed() const override;
private:
  CDialogEx* m_dialog    { nullptr };
  MainFrame* m_mainFrame { nullptr };
  CWinAppEx* m_winapp    { nullptr };
};


