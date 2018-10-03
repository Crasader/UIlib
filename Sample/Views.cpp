#include "StdAfx.h"
#include "Views.h"
#include <exdisp.h>
#include <comdef.h>


////////////////////////////////////////////////////////////////////////
//

UINT CStandardPageWnd::GetClassStyle() const
{
	return UI_CLASSSTYLE_CHILD;
}

void CStandardPageWnd::OnFinalMessage(HWND /*hWnd*/)
{
	delete this;
}

LRESULT CStandardPageWnd::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if( uMsg == WM_CREATE ) {
		m_pm.Init(m_hWnd);
		CDialogBuilder builder;
		CControlUI* pRoot = builder.Create(GetDialogResource());
		ASSERT(pRoot && "Failed to parse XML");
		m_pm.AttachDialog(pRoot);
		m_pm.AddNotifier(this);
		Init();
		return 0;
	}
	LRESULT lRes = 0;
	if( m_pm.MessageHandler(uMsg, wParam, lParam, lRes) ) return lRes;
	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}

void CStandardPageWnd::Init()
{
}

void CStandardPageWnd::OnPrepareAnimation()
{
}

void CStandardPageWnd::Notify(TNotifyUI& msg)
{
	if( msg.sType == _T("windowinit") ) OnPrepareAnimation();
}


////////////////////////////////////////////////////////////////////////
//

LPCTSTR CStartPageWnd::GetWindowClassName() const
{
	return _T("UIStart");
}

LPCTSTR CStartPageWnd::GetDialogResource() const
{
	return _T("<Dialog>")
		_T("<HorizontalLayout>")
		_T("<VerticalLayout width=\"150\" >")
		_T("<Toolbar>")
		_T("<ToolGripper />")
		_T("</Toolbar>")
		_T("<NavigatorPanel>")
		_T("<PaddingPanel height=\"18\" />")
		_T("<NavigatorButton name=\"page_start\" text=\"<i 0> Start\" selected=\"true\" tooltip=\"Vis start siden\" />")
		_T("<NavigatorButton name=\"page_registers\" text=\"<i 4> Registre\" tooltip=\"Vis forskellige registre\" />")
		_T("<NavigatorButton name=\"page_systems\" text=\"<i 4> Systemer\" />")
		_T("<NavigatorButton name=\"page_configure\" text=\"<i 4> Opsætning\" />")
		_T("<NavigatorButton name=\"page_reports\" text=\"<i 4> Rapporter\" />")
		_T("</NavigatorPanel>")
		_T("</VerticalLayout>")
		_T("<VerticalLayout>")
		_T("<Toolbar>")
		_T("<LabelPanel align=\"right\" text=\"<f 6><c #fffe28>Start Side</c></f>\" />")
		_T("</Toolbar>")
		_T("<ToolbarTitlePanel text=\"<f 7>Bjarke's Test Program</f>\" />")
		_T("<TitleShadow />")
		_T("<WindowCanvas watermark=\"StartWatermark\" >")
		_T("<VerticalLayout>")
		_T("<TextPanel text=\"<f 8>Vælg startområde?</h>\" />")
		_T("<FadedLine />")
		_T("<TileLayout scrollbar=\"true\" >")
		_T("<TextPanel name=\"link_registers\" text=\"<i 7 50><a><f 6>&Registre</f></a>\n<h>\n<c #444540>Vælg denne menu for at rette i diverse registre i systemet.\n\nDu kan rette i kunde, vogn og chauffør-reigsteret.\" shortcut=\"R\" />")
		_T("<TextPanel name=\"link_systems\" text=\"<i 9 50><a><f 6>&Systemer</f></a>\n<h>\n<c #444540>Gennem denne menu kan du opsætte diverse ting.\" shortcut=\"S\" />")
		_T("<TextPanel name=\"link_configure\" text=\"<i 6 50><a><f 6>Opsætning</f></a>\n<h>\n<c #444540>Opsætning giver adgang til konfiguration af de mange kørsels-systemer og regler.\" />")
		_T("<TextPanel name=\"link_reports\" text=\"<i 5 50><a><f 6>Rapporter</f></a>\n<h>\n<c #444540>Rapporter giver dig overblik over registre samt hverdagens ture og bestillinger.\n\nGennem statistik og lister kan du hurtigt få præsenteret historiske data fra systemet.\" />")
		_T("</TileLayout>")
		_T("</VerticalLayout>")
		_T("</WindowCanvas>")
		_T("</VerticalLayout>")
		_T("</HorizontalLayout>")
		_T("</Dialog>");
}

void CStartPageWnd::OnPrepareAnimation()
{
	COLORREF clrBack = m_pm.GetThemeColor(UICOLOR_WINDOW_BACKGROUND);
	RECT rcCtrl = m_pm.FindControl(_T("link_registers"))->GetPos();
	m_pm.AddAnimJob(CAnimJobUI(UIANIMTYPE_FLAT, 0, 350, clrBack, clrBack, CRect(rcCtrl.left, rcCtrl.top, rcCtrl.left + 50, rcCtrl.top + 50), 40, 0, 4, 255, 0.3f));
	rcCtrl = m_pm.FindControl(_T("link_systems"))->GetPos();
	m_pm.AddAnimJob(CAnimJobUI(UIANIMTYPE_FLAT, 200, 350, clrBack, clrBack, CRect(rcCtrl.left, rcCtrl.top, rcCtrl.left + 50, rcCtrl.top + 50), 40, 0, 4, 255, 0.3f));
	rcCtrl = m_pm.FindControl(_T("link_configure"))->GetPos();
	m_pm.AddAnimJob(CAnimJobUI(UIANIMTYPE_FLAT, 100, 350, clrBack, clrBack, CRect(rcCtrl.left, rcCtrl.top, rcCtrl.left + 50, rcCtrl.top + 50), 40, 0, 4, 255, 0.3f));
	rcCtrl = m_pm.FindControl(_T("link_reports"))->GetPos();
	m_pm.AddAnimJob(CAnimJobUI(UIANIMTYPE_FLAT, 250, 350, clrBack, clrBack, CRect(rcCtrl.left, rcCtrl.top, rcCtrl.left + 50, rcCtrl.top + 50), 40, 0, 4, 255, 0.3f));
}

void CStartPageWnd::Init()
{
}


////////////////////////////////////////////////////////////////////////
//

LPCTSTR CConfigurePageWnd::GetWindowClassName() const
{
	return _T("UIConfigure");
}

LPCTSTR CConfigurePageWnd::GetDialogResource() const
{
	return _T("<Dialog>")
		_T("<HorizontalLayout>")
		_T("<VerticalLayout width=\"150\" >")
		_T("<Toolbar>")
		_T("<ToolGripper />")
		_T("</Toolbar>")
		_T("<NavigatorPanel>")
		_T("<PaddingPanel height=\"18\" />")
		_T("<NavigatorButton name=\"page_start\" text=\"<i 0> Start\" tooltip=\"Vis start siden\" />")
		_T("<NavigatorButton name=\"page_registers\" text=\"<i 4> Registre\" tooltip=\"Vis forskellige registre\" />")
		_T("<NavigatorButton name=\"page_systems\" text=\"<i 4> Systemer\" />")
		_T("<NavigatorButton name=\"page_configure\" text=\"<i 4> Opsætning\" selected=\"true\" />")
		_T("<NavigatorButton name=\"page_reports\" text=\"<i 4> Rapporter\" />")
		_T("</NavigatorPanel>")
		_T("</VerticalLayout>")
		_T("<VerticalLayout>")
		_T("<Toolbar>")
		_T("<LabelPanel align=\"right\" text=\"<f 6><c #fffe28>System Opsætning</c></f>\" />")
		_T("</Toolbar>")
		_T("<ToolbarTitlePanel name=\"titlepanel\" text=\"<f 7>System Opsætning</f>\" />")
		_T("<TitleShadow />")
		_T("<WindowCanvas>")
		_T("<VerticalLayout>")
		_T("<TextPanel text=\"<f 8>Hvad vil du konfigurere?</h>\" />")
		_T("<FadedLine />")
		_T("<HorizontalLayout>")
		_T("<TaskPanel text=\"<f 2>Opgaver</f>\" >")
		_T("<TextPanel text=\"<i 2><a>Skift trafikniveau</a>\" />")
		_T("<TextPanel text=\"<i 3><a>Brugerindstillinger</a>\" />")
		_T("</TaskPanel>")
		_T("<PaddingPanel width=\"12\" />")
		_T("<VerticalLayout>")
		_T("<TextPanel text=\"<f 6><c #2c4378>Opsætningsliste</c></f>\" />")
		_T("<SeparatorLine />")
		_T("<TextPanel text=\"<c #414141>Dobbeltklik på et element i listen for at konfigurere det.</c>\n\" />")
		_T("<List header=\"hidden\" >")
		_T("<TextPanel text=\"<x 16><c #585ebf><b>Registre</b>\n<h>\" />")
		_T("<ListLabelElement text=\"<i 4> Vejregister\" />")
		_T("<ListLabelElement text=\"<i 4> Institutions register\" />")
		_T("<ListLabelElement text=\"<i 4> Kunde register\" />")
		_T("<ListLabelElement text=\"<i 4> Vognmandsregister\" />")
		_T("<ListLabelElement text=\"<i 4> Vogn register\" />")
		_T("<ListLabelElement text=\"<i 4> Chauffør register\" />")
		_T("<TextPanel text=\"<x 16><c #F00000><b>A cool effect</b>\n<h>\" />")
		_T("<ListLabelElement text=\"<i 7> RESIZE THIS PAGE (make smaller)\" />")
		_T("</List>")
		_T("</VerticalLayout>")
		_T("</HorizontalLayout>")
		_T("</VerticalLayout>")
		_T("</WindowCanvas>")
		_T("</VerticalLayout>")
		_T("</HorizontalLayout>")
		_T("</Dialog>");
}

void CConfigurePageWnd::OnPrepareAnimation()
{
	COLORREF clrBack = m_pm.GetThemeColor(UICOLOR_TITLE_BACKGROUND);
	const RECT rcCtrl = m_pm.FindControl(_T("titlepanel"))->GetPos();
	m_pm.AddAnimJob(CAnimJobUI(UIANIMTYPE_FLAT, 0, 300, clrBack, CLR_INVALID, rcCtrl, 140, 0, 5, 200, 0.1f));
}


////////////////////////////////////////////////////////////////////////
//

LPCTSTR CRegistersPageWnd::GetWindowClassName() const
{
	return _T("UIRegisters");
}

LPCTSTR CRegistersPageWnd::GetDialogResource() const
{
	return _T("<Dialog>")
		_T("<HorizontalLayout>")
		_T("<VerticalLayout width=\"150\" >")
		_T("<Toolbar>")
		_T("<ToolGripper />")
		_T("</Toolbar>")
		_T("<NavigatorPanel>")
		_T("<PaddingPanel height=\"18\" />")
		_T("<NavigatorButton name=\"page_start\" text=\"<i 0> Start\" tooltip=\"Vis start siden\" />")
		_T("<NavigatorButton name=\"page_registers\" text=\"<i 4> Registre\" tooltip=\"Vis forskellige registre\" selected=\"true\" />")
		_T("<NavigatorButton name=\"page_systems\" text=\"<i 4> Systemer\" />")
		_T("<NavigatorButton name=\"page_configure\" text=\"<i 4> Opsætning\" />")
		_T("<NavigatorButton name=\"page_reports\" text=\"<i 4> Rapporter\" />")
		_T("</NavigatorPanel>")
		_T("</VerticalLayout>")
		_T("<VerticalLayout>")
		_T("<Toolbar>")
		_T("<LabelPanel align=\"right\" text=\"<f 6><c #fffe28>Registre</c></f>\" />")
		_T("</Toolbar>")
		_T("<TitleShadow />")
		_T("<WindowCanvas>")
		_T("<SearchTitlePanel image=\"10\" >")
		_T("<TabFolder width=\"200\" inset=\"8 8\" >")
		_T("<TabPage text=\"Generelt\" >")
		_T("<DialogLayout scrollbar=\"true\" >")
		_T("<LabelPanel pos=\"0, 0, 150, 24\" text=\"S&øg efter\" />")
		_T("<SingleLineEdit pos=\"0, 24, 150, 44\" name=\"navn\" />")
		_T("<LabelPanel pos=\"0, 48, 150, 68\" text=\"&Type\" />")
		_T("<SingleLineEdit pos=\"0, 68, 150, 88\" name=\"type\" />")
		_T("<Button pos=\"100, 98, 150, 118\" name=\"ok\" text=\"Søg\" />")
		_T("</DialogLayout>")
		_T("</TabPage>")
		_T("</TabFolder>")
		_T("<List name=\"list\">")
		_T("<ListHeaderItem text=\"Navn\" width=\"240\" />")
		_T("<ListHeaderItem text=\"Type\" width=\"80\" />")
		_T("</List>")
		_T("</SearchTitlePanel>")
		_T("</WindowCanvas>")
		_T("</VerticalLayout>")
		_T("</HorizontalLayout>")
		_T("</Dialog>");
}

void CRegistersPageWnd::OnPrepareAnimation()
{
	CListUI* pList = static_cast<CListUI*>(m_pm.FindControl(_T("list")));
	pList->SetTextCallback(this);                                          // We want GetItemText for items
	for( int i = 0; i < 1000; i++ ) pList->Add(new CListTextElementUI);    // We want 1000 items in list
}

LPCTSTR CRegistersPageWnd::GetItemText(CControlUI* pControl, int iIndex, int iSubItem)
{
	if( iIndex == 0 && iSubItem == 0 ) return _T("<i 3>Item1");
	if( iIndex == 1 && iSubItem == 0 ) return _T("<i 3>Item2");
	if( iIndex == 2 && iSubItem == 0 ) return _T("<i 3>Item3");
	if( iIndex == 0 && iSubItem == 1 ) return _T("Horse");
	if( iIndex == 1 && iSubItem == 1 ) return _T("Dog");
	if( iIndex == 2 && iSubItem == 1 ) return _T("Rabbit");
	static CStdString sTemp;
	sTemp.Format(_T("Item %d %d"), iIndex, iSubItem);
	return sTemp;
}

int CRegistersPageWnd::CompareItem(CControlUI* pList, CControlUI* pItem1, CControlUI* pItem2)
{
	return 0;
}


////////////////////////////////////////////////////////////////////////
//

LPCTSTR CSystemsPageWnd::GetWindowClassName() const
{
	return _T("UISystems");
}

LPCTSTR CSystemsPageWnd::GetDialogResource() const
{
	return _T("<Dialog>")
		_T("<HorizontalLayout>")
		_T("<VerticalLayout width=\"150\" >")
		_T("<Toolbar>")
		_T("<ToolGripper />")
		_T("</Toolbar>")
		_T("<NavigatorPanel>")
		_T("<PaddingPanel height=\"18\" />")
		_T("<NavigatorButton name=\"page_start\" text=\"<i 0> Start\" tooltip=\"Vis start siden\" />")
		_T("<NavigatorButton name=\"page_registers\" text=\"<i 4> Registre\" tooltip=\"Vis forskellige registre\" />")
		_T("<NavigatorButton name=\"page_systems\" text=\"<i 4> Systemer\" selected=\"true\" />")
		_T("<NavigatorButton name=\"page_configure\" text=\"<i 4> Opsætning\" />")
		_T("<NavigatorButton name=\"page_reports\" text=\"<i 4> Rapporter\" />")
		_T("</NavigatorPanel>")
		_T("</VerticalLayout>")
		_T("<VerticalLayout>")
		_T("<Toolbar>")
		_T("<LabelPanel align=\"right\" text=\"<f 6><c #fffe28>Systemer</c></f>\" />")
		_T("</Toolbar>")
		_T("<TitleShadow />")
		_T("<WindowCanvas>")
		_T("<VerticalLayout>")
		_T("<DialogLayout scrollbar=\"true\" >")
		_T("<LabelPanel pos=\"0, 0, 80, 24\" text=\"<b>&Søg efter</b>\" stretch=\"group\" />")
		_T("<SingleLineEdit pos=\"80, 2, 220, 22\" name=\"navn\" stretch=\"size_x\" />")
		_T("<Button pos=\"224, 2, 265, 22\" text=\"Søg\" name=\"ok\" stretch=\"move_x\" />")
		_T("<LabelPanel pos=\"280, 0, 320, 24\" text=\"<b>&Type</b>\" stretch=\"move_x\" />")
		_T("<SingleLineEdit pos=\"320, 2, 480, 22\" name=\"type\" stretch=\"move_x size_x\" />")
		_T("<ImagePanel image=\"logo_search\" pos=\"490, 0, 555, 56\" stretch=\"move_x\" />")
		_T("<Toolbar pos=\"0, 30, 480, 53\" stretch=\"group size_x\" >")
		_T("<PaddingPanel />")
		_T("<ToolButton text=\"<i 15> Opret element\" />")
		_T("<ToolButton text=\"<i 0>\" />")
		_T("<ToolButton text=\"<i 1>\" />")
		_T("</Toolbar>")
		_T("<ListHeaderShadow pos=\"0, 53, 480, 56\" stretch=\"group size_x\" />")
		_T("</DialogLayout>")
		_T("<List name=\"list\" expanding=\"true\">")
		_T("<ListHeaderItem enabled=\"false\" width=\"30\" />")
		_T("<ListHeaderItem text=\"Navn\" width=\"140\" />")
		_T("<ListHeaderItem text=\"Price\" width=\"80\" />")
		_T("<ListHeaderItem text=\"Link\" width=\"180\" />")
		_T("<ListExpandElement />")
		_T("<ListExpandElement />")
		_T("<ListExpandElement />")
		_T("</List>")
		_T("</VerticalLayout>")
		_T("</WindowCanvas>")
		_T("</VerticalLayout>")
		_T("</HorizontalLayout>")
		_T("</Dialog>");
}

void CSystemsPageWnd::Notify(TNotifyUI& msg)
{
	if( msg.sType == _T("itemexpand") ) OnExpandItem(msg.pSender);
	CStandardPageWnd::Notify(msg);
}

LPCTSTR CSystemsPageWnd::GetItemText(CControlUI* pControl, int iIndex, int iSubItem)
{
	if( iIndex == 0 && iSubItem == 1 ) return _T("Expanding Item #1");
	if( iIndex == 1 && iSubItem == 1 ) return _T("Expanding Item #2");
	if( iIndex == 2 && iSubItem == 1 ) return _T("Expanding Item #3");
	if( iIndex == 0 && iSubItem == 2 ) return _T("100.0");
	if( iIndex == 1 && iSubItem == 2 ) return _T("20.0");
	if( iIndex == 2 && iSubItem == 2 ) return _T("30.0");
	if( iIndex == 0 && iSubItem == 3 ) return _T("<a>Kunde #1</a>");
	if( iIndex == 1 && iSubItem == 3 ) return _T("");
	if( iIndex == 2 && iSubItem == 3 ) return _T("<a>Kunde #3</a>");
	return _T("");
}

int CSystemsPageWnd::CompareItem(CControlUI* pList, CControlUI* pItem1, CControlUI* pItem2)
{
	return 0;
}

void CSystemsPageWnd::OnPrepareAnimation()
{
	CListUI* pList = static_cast<CListUI*>(m_pm.FindControl(_T("list")));
	pList->SetTextCallback(this); // List will call our GetItemText()
}

void CSystemsPageWnd::OnExpandItem(CControlUI* pControl)
{
	CListExpandElementUI* pItem = static_cast<CListExpandElementUI*>(pControl);
	// Add slowly...
	CTextPanelUI* pText = new CTextPanelUI();
	CStdString sText;
	sText.Format(_T("<b>Episode:</b> Gyldendal #%p"), pControl);
	pText->SetText(sText);
	pItem->Add(pText);
	// Add quickly...
	pItem->Add((new CTextPanelUI())->ApplyAttributeList(_T("text=\"<b>Navn:</b> Anders And\"")));
	pItem->Add((new CTextPanelUI())->ApplyAttributeList(_T("text=\"<b>Tidspunkt:</b> <i 3>Juleaften\"")));
}


////////////////////////////////////////////////////////////////////////
//

LPCTSTR CReportsPageWnd::GetWindowClassName() const
{
	return _T("UIReports");
}

LPCTSTR CReportsPageWnd::GetDialogResource() const
{
	return _T("<Dialog>")
		_T("<HorizontalLayout>")
		_T("<VerticalLayout width=\"150\" >")
		_T("<Toolbar>")
		_T("<ToolGripper />")
		_T("</Toolbar>")
		_T("<NavigatorPanel>")
		_T("<PaddingPanel height=\"18\" />")
		_T("<NavigatorButton name=\"page_start\" text=\"<i 0> Start\" tooltip=\"Vis start siden\" />")
		_T("<NavigatorButton name=\"page_registers\" text=\"<i 4> Registre\" tooltip=\"Vis forskellige registre\" />")
		_T("<NavigatorButton name=\"page_systems\" text=\"<i 4> Systemer\" />")
		_T("<NavigatorButton name=\"page_configure\" text=\"<i 4> Opsætning\" />")
		_T("<NavigatorButton name=\"page_reports\" text=\"<i 4> Rapporter\" selected=\"true\" />")
		_T("</NavigatorPanel>")
		_T("</VerticalLayout>")
		_T("<VerticalLayout>")
		_T("<Toolbar>")
		_T("<LabelPanel align=\"right\" text=\"<f 6><c #fffe28>Rapporter</c></f>\" />")
		_T("</Toolbar>")
		_T("<ToolbarTitlePanel name=\"titlepanel\" text=\"<f 7>Rapporter</f>\" />")
		_T("<TitleShadow />")
		_T("<WindowCanvas>")
		_T("<TileLayout>")
		_T("<TextPanel text=\"<i 0 50><a><f 6>Kunde Rapporter</f></a>\n<h>\n<c #444540>Rapporter for kunde registeret.\" />")
		_T("<TextPanel text=\"<i 1 50><a><f 6>Vogn Rapporter</f></a>\n<h>\n<c #444540>Rapporter for vogn and vognmands-registeret.\" />")
		_T("<TextPanel text=\"<i 2 50><a><f 6>Chauffør Rapporter</f></a>\n<h>\n<c #444540>Rapporter for chauffører registeret.\" />")
		_T("<TextPanel text=\"<i 3 50><a><f 6>Bestilling Rapporter</f></a>\n<h>\n<c #444540>Rapporter over bestillinger.\" />")
		_T("</TileLayout>")
		_T("</WindowCanvas>")
		_T("</VerticalLayout>")
		_T("</HorizontalLayout>")
		_T("</Dialog>");
}

void CReportsPageWnd::OnPrepareAnimation()
{
	const RECT rcCtrl = m_pm.FindControl(_T("titlepanel"))->GetPos();
	m_pm.AddAnimJob(CAnimJobUI(UIANIMTYPE_FLAT, 0, 300, CLR_INVALID, CLR_INVALID, rcCtrl, 0, 0, -2, -200, 0.0f));
}


////////////////////////////////////////////////////////////////////////
//

LPCTSTR CSearchPageWnd::GetWindowClassName() const
{
	return _T("UISearch");
}

void CSearchPageWnd::Init()
{
	m_pm.SetMinMaxInfo(640,480);
}

void CSearchPageWnd::Notify(TNotifyUI& msg)
{
	if( msg.sType == _T("click") )
	{
		if( msg.pSender->GetName() == _T("ok") ) {
			CStandardPageWnd* pWindow = new CEditPageWnd;
			pWindow->Create(m_hWnd, NULL, UI_WNDSTYLE_FRAME, 0L);
		}
		if( msg.pSender->GetName() == _T("cancel") ) Close();
	}
	CStandardPageWnd::Notify(msg);
}

LPCTSTR CSearchPageWnd::GetDialogResource() const
{
	return _T("<Dialog caption=\"Search Page\" >")
		_T("<VerticalLayout>")
		_T("<ToolbarTitlePanel text=\"<f 6>Søg efter en vej.</f><p><x 10>Indtast søgekriterier og søg efter vejen.\" />")
		_T("<DialogCanvas>")
		_T("<VerticalLayout>")
		_T("<DialogLayout>")
		_T("<LabelPanel pos=\"0, 10, 60, 34\" text=\"Type\" stretch=\"group\" />")
		_T("<DropDown pos=\"60, 12, 340, 32\" name=\"navn\" stretch=\"size_x\" >")
		_T("<ListLabelElement text=\"<i 2> Navn\" selected=\"true\" />")
		_T("<ListLabelElement text=\"<i 5> Kontakter\" />")
		_T("<ListLabelElement text=\"<i 8> E-mail grupper\" />")
		_T("<ListLabelElement text=\"<i 8> Kunde grupper\" />")
		_T("</DropDown>")
		_T("<LabelPanel pos=\"0, 36, 60, 60\" text=\"Søg\" stretch=\"group\" />")
		_T("<SingleLineEdit pos=\"60, 38, 250, 58\" name=\"search\" text=\"\" stretch=\"size_x\" />")
		_T("<Button pos=\"260, 38, 340, 58\" name=\"ok\" text=\"&Søg\" stretch=\"move_x\" />")
		_T("<SeparatorLine pos=\"0, 68, 340, 78\" stretch=\"group size_x\" />")
		_T("<LabelPanel pos=\"0, 78, 340, 98\" text=\"Valgbare veje\" />")
		_T("<PaddingPanel pos=\"0, 98, 340, 100\" />")
		_T("</DialogLayout>")
		_T("<List name=\"list\">")
		_T("<ListHeaderItem text=\"Navn\" width=\"140\" />")
		_T("<ListHeaderItem text=\"Position\" width=\"80\" />")
		_T("</List>")
		_T("<DialogLayout>")
		_T("<PaddingPanel pos=\"0, 0, 340, 4\" />")
		_T("<SeparatorLine pos=\"0, 4, 340, 18\" stretch=\"group size_x\" />")
		_T("<PaddingPanel pos=\"0, 18, 160, 38\" stretch=\"group size_x\" />")
		_T("<Button pos=\"160, 18, 246, 38\" text=\"OK\" name=\"ok\" stretch=\"move_x\" />")
		_T("<Button pos=\"250, 18, 340, 38\" text=\"Annuller\" name=\"cancel\" stretch=\"move_x\" />")
		_T("<PaddingPanel pos=\"0, 38, 340, 48\" />")
		_T("</DialogLayout>")
		_T("</VerticalLayout>")
		_T("</DialogCanvas>")
		_T("</VerticalLayout>")
		_T("</Dialog>");
}


////////////////////////////////////////////////////////////////////////
//

LPCTSTR CEditPageWnd::GetWindowClassName() const
{
	return _T("UIEdit");
}

void CEditPageWnd::Init()
{
	ResizeClient(640, 480);
	m_pm.SetMinMaxInfo(640,480);
}

void CEditPageWnd::Notify(TNotifyUI& msg)
{
	if( msg.sType == _T("click") && msg.pSender->GetName() == _T("cancel") ) Close();
	if( msg.sType == _T("link") && msg.pSender->GetName() == _T("warning") ) {
		CPopupWnd* pPopup = new CPopupWnd;
		pPopup->Create(m_hWnd, _T(""), UI_WNDSTYLE_DIALOG, UI_WNDSTYLE_EX_DIALOG, 0, 0, 0, 0, NULL);
		pPopup->ShowModal();
	}
	CStandardPageWnd::Notify(msg);
}

LPCTSTR CEditPageWnd::GetDialogResource() const
{
	return _T("<Dialog caption=\"Rediger Person\" >")
		_T("<VerticalLayout>")
		_T("<Toolbar>")
		_T("<ToolGripper />")
		_T("<ToolButton text=\"<i 0> Luk\" name=\"cancel\" />")
		_T("<ToolButton text=\"<i 1>\" />")
		_T("<ToolSeparator />")
		_T("</Toolbar>")
		_T("<TitleShadow />")
		_T("<DialogCanvas>")
		_T("<VerticalLayout>")
		_T("<WarningPanel name=\"warning\" type=\"warning\" text=\"<i 7>You have not specified an e-mail address.\nTry entering one. Click <a>here</a> to get more help.\" />")
		_T("<TabFolder>")
		_T("<TabPage text=\"Generelt\" >")
		_T("<DialogLayout scrollbar=\"true\" >")
		_T("<LabelPanel pos=\"0, 0, 110, 24\" text=\"&Navn\" stretch=\"group\" />")
		_T("<SingleLineEdit pos=\"110, 2, 240, 22\" name=\"navn\" text=\"\" stretch=\"size_x\" />")
		_T("<LabelPanel pos=\"260, 0, 370, 24\" text=\"Telefon 1\" stretch=\"move_x\" />")
		_T("<SingleLineEdit pos=\"370, 2, 510, 22\" text=\"+45 12345678\" stretch=\"move_x size_x\" />")

		_T("<LabelPanel pos=\"0, 30, 110, 54\" text=\"&Firma Nr\" stretch=\"group\" />")
		_T("<SingleLineEdit pos=\"110, 32, 240, 52\" text=\"\" stretch=\"size_x\" />")
		_T("<LabelPanel pos=\"260, 30, 370, 54\" text=\"Telefon 2\" stretch=\"move_x\" />")
		_T("<SingleLineEdit pos=\"370, 32, 510, 52\" text=\"+45 87654321\" enabled=\"false\" stretch=\"move_x size_x\" />")

		_T("<LabelPanel pos=\"0, 60, 110, 84\" text=\"Kontakt\" stretch=\"group\" />")
		_T("<SingleLinePick pos=\"110, 62, 240, 82\" text=\"<i 3><a>Bjarke Viksøe</a>\" stretch=\"size_x\" />")
		_T("<LabelPanel pos=\"260, 60, 370, 84\" text=\"Website\" stretch=\"move_x\" />")
		_T("<SingleLineEdit pos=\"370, 62, 510, 82\" text=\"www.viksoe.dk/code\" stretch=\"move_x size_x\" />")

		_T("<GreyTextHeader pos=\"0, 100, 510, 120\" text=\"Adresse\" stretch=\"group size_x\" />")

		_T("<LabelPanel pos=\"0, 130, 110, 154\" text=\"Vej\" stretch=\"group\" />")
		_T("<SingleLinePick pos=\"110, 132, 240, 152\" text=\"<a>Nørrebred, Vallensbæk</a>\" stretch=\"size_x\" />")
		_T("<LabelPanel pos=\"260, 130, 370, 154\" text=\"Note\" stretch=\"move_x\" />")
		_T("<MultiLineEdit pos=\"370, 132, 510, 192\" text=\"Dette er en meget lang note omkring denne person. Her følger noget mere tekst\" stretch=\"move_x size_x\" />")

		_T("<LabelPanel pos=\"0, 160, 110, 184\" text=\"Post Nr\" stretch=\"line\" />")
		_T("<DropDown pos=\"110, 162, 240, 182\" stretch=\"move_x size_x\">")
		_T("<ListLabelElement text=\"2560 Holte\" selected=\"true\" />")
		_T("<ListLabelElement text=\"2625 Vallensbæk\" />")
		_T("</DropDown>")

		_T("<Option pos=\"0, 192, 120, 212\" text=\"Husnr krævet\" selected=\"true\" />")
		_T("<Option pos=\"120, 192, 240, 212\" text=\"Ikke krævet\" />")
		_T("</DialogLayout>")
		_T("</TabPage>")
		_T("<TabPage text=\"Egenskaber\" >")
		_T("<VerticalLayout>")
		_T("<Toolbar>")
		_T("<PaddingPanel />")
		_T("<ToolButton text=\"<i 0>\" />")
		_T("<ToolButton text=\"<i 1>\" />")
		_T("</Toolbar>")
		_T("<ListHeaderShadow />")
		_T("<List name=\"list\">")
		_T("<ListHeaderItem enabled=\"false\" width=\"40\" />")
		_T("<ListHeaderItem text=\"Navn\" width=\"140\" />")
		_T("<ListHeaderItem text=\"Position\" width=\"80\" />")
		_T("</List>")
		_T("</VerticalLayout>")
		_T("</TabPage>")
		_T("</TabFolder>")
		_T("</VerticalLayout>")
		_T("</DialogCanvas>")
		_T("<Statusbar text=\"<b>Status:</b> Klar\" />")
		_T("</VerticalLayout>")
		_T("</Dialog>");
}

void CEditPageWnd::OnPrepareAnimation()
{
	const RECT rcCtrl = m_pm.FindControl(_T("warning"))->GetPos();
	m_pm.AddAnimJob(CAnimJobUI(UIANIMTYPE_FLAT, 0, 300, CLR_INVALID, CLR_INVALID, rcCtrl, 0, 0, -2, -200, 0.0f));
}


////////////////////////////////////////////////////////////////////////
//

UINT CPopupWnd::GetClassStyle() const
{
	return UI_CLASSSTYLE_DIALOG;
}

LPCTSTR CPopupWnd::GetWindowClassName() const
{
	return _T("UIPopup");
}

void CPopupWnd::Init()
{
	ResizeClient(440, 210);
	CenterWindow();
}

void CPopupWnd::Notify(TNotifyUI& msg)
{
	if( msg.sType == _T("click") ) Close();
	CStandardPageWnd::Notify(msg);
}

LPCTSTR CPopupWnd::GetDialogResource() const
{
	return _T("<Dialog>")
		_T("<VerticalLayout>")
		_T("<ToolbarTitlePanel text=\"<f 6>Er du sikker?</f><p><x 10>Er du sikker på at du har trykket på linket?\" />")
		_T("<DialogCanvas>")
		_T("<VerticalLayout>")
		_T("<TextPanel text=\"Det er ikke altid godt at trykke på linket. Du kan fortryde dit klik ved at vælge Nej knappen.\" />")
		_T("<PaddingPanel />")
		_T("<DialogLayout>")
		_T("<PaddingPanel pos=\"0, 0, 340, 4\" />")
		_T("<SeparatorLine pos=\"0, 4, 340, 18\" stretch=\"group size_x\" />")
		_T("<PaddingPanel pos=\"0, 18, 160, 38\" stretch=\"group size_x\" />")
		_T("<Button pos=\"180, 18, 256, 38\" text=\"Ja\" name=\"ok\" stretch=\"move_x\" />")
		_T("<Button pos=\"260, 18, 340, 38\" text=\"Nej\" name=\"cancel\" stretch=\"move_x\" />")
		_T("<PaddingPanel pos=\"0, 38, 340, 48\" />")
		_T("</DialogLayout>")
		_T("</VerticalLayout>")
		_T("</DialogCanvas>")
		_T("</VerticalLayout>")
		_T("</Dialog>");
}
