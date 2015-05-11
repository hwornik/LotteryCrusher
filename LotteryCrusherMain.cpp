/***************************************************************
 * Name:      LotteryCrusherMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Hans Wornik (hans@wornik.eu)
 * Created:   2015-05-04
 * Copyright: Hans Wornik (www.wornik.eu)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include <wx/sizer.h>
#include "LotteryCrusherMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(LotteryCrusherFrame, wxFrame)
    EVT_CLOSE(LotteryCrusherFrame::OnClose)
    EVT_MENU(idMenuQuit, LotteryCrusherFrame::OnQuit)
    EVT_MENU(idMenuAbout, LotteryCrusherFrame::OnAbout)
    EVT_MENU(idMenuAktivate, LotteryCrusherFrame::OnAktivateProgram)
    EVT_MENU(idMenuSettings, LotteryCrusherFrame::OnSettings)
    EVT_MENU(idMenuEuro, LotteryCrusherFrame::OnEuromillionen)
    EVT_MENU(idMenuAustria, LotteryCrusherFrame::OnAustria)
    EVT_MENU(idMenuFrance, LotteryCrusherFrame::OnFrance)
    EVT_MENU(idMenuGermany, LotteryCrusherFrame::OnGermany)
    EVT_MENU(idMenuHungary, LotteryCrusherFrame::OnHungary)
    EVT_MENU(idMenuItaly, LotteryCrusherFrame::OnItaly)
    EVT_MENU(idMenuSpainI, LotteryCrusherFrame::OnSpainB)
    EVT_MENU(idMenuSpainB, LotteryCrusherFrame::OnSpainI)
    EVT_MENU(idMenuCompute, LotteryCrusherFrame::OnCompute)
    EVT_MENU(idMenuCompWithN, LotteryCrusherFrame::OnComputeWithN)
    EVT_MENU(idMenuWinNew, LotteryCrusherFrame::OnWinNew)
    EVT_MENU(idMenuWinCorr, LotteryCrusherFrame::OnWinCorr)
    EVT_MENU(idMenu2DPlot, LotteryCrusherFrame::On2DPlot)
    EVT_MENU(idMenu3DPlot, LotteryCrusherFrame::On3DPlot)
    EVT_PAINT(LotteryCrusherFrame::OnPaint)
END_EVENT_TABLE()

LotteryCrusherFrame::LotteryCrusherFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
    activated=this->activateStartup();
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    wxMenu* lottoMenu = new wxMenu(_T(""));
    fileMenu->AppendSubMenu(lottoMenu, _("&Lottery"));
    // Lotterien anfang
    lottoMenu->Append(idMenuEuro, _("&Euromillions\tAlt-e"), _("Play Euromillions"));
    lottoMenu->Append(idMenuAustria, _("&Austria\tAlt-a"), _("6 of 45"));
    lottoMenu->Append(idMenuFrance, _("F&rance\tAlt-r"), _("6 of 49"));
    lottoMenu->Append(idMenuGermany, _("&Germany\tAlt-g"), _("6 of 49"));
    lottoMenu->Append(idMenuHungary, _("&Hungary\tAlt-h"), _("6 of 45"));
    lottoMenu->Append(idMenuItaly, _("&Italy\tAlt-i"), _("6 of 90"));
    lottoMenu->Append(idMenuSpainI, _("&SpainI\tAlt-s"), _("6 of 49"));
    lottoMenu->Append(idMenuSpainB, _("&SpainB\tAlt-b"), _("6 of 49"));
    //Lotterien ende
    if(!this->isactiveted())
        fileMenu->Append(idMenuAktivate, _("Activation"), _("Aktivate the program"));
    fileMenu->Append(idMenuSettings, _("Settings"), _("Modify Settings"));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* tipMenu = new wxMenu(_T(""));
    tipMenu->Append(idMenuCompute, _("Compute tips"), _("Compute tips for your lottery"));
    tipMenu->Append(idMenuCompWithN, _("Compute tips with prefered numbers"), _("Compute tips with fixed numbers for your lottery"));
    mbar->Append(tipMenu, _("&Tips"));

    wxMenu* winningMenu = new wxMenu(_T(""));
    winningMenu->Append(idMenuWinNew, _("&Input the winning numbers "), _("Input the choosen numbers"));
    winningMenu->Append(idMenuWinCorr, _("&Show the winning numbers "), _("Correct the choosen numbers"));
    mbar->Append(winningMenu, _("&Winning numbers"));

    wxMenu* graphMenu = new wxMenu(_T(""));
    graphMenu->Append(idMenu2DPlot, _("2D Plot"), _("Show 2DPlot of the winning numbers"));
    graphMenu->Append(idMenu3DPlot, _("3D Plot"), _("Show 3DPlot of the winning numbers"));
    mbar->Append(graphMenu, _("Plots"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS
    lotto = new Lotto();
#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    if(!this->isactiveted())
    {
        SetStatusText(_("Program not activated"),0);
    }
    else
    {
        SetStatusText(_("Program activated"),0);
    }
    SetStatusText(lotto->askName(), 1);

#endif // wxUSE_STATUSBAR
    aktion=0;
    this->fenster= new Welcome(this->lotto,this);
    wxSize fsize;
    fsize.x=400;
    fsize.y=500;
    this->SetMinSize(fsize);
    this->SetSize(fsize);
    firstpaint=false;
}


LotteryCrusherFrame::~LotteryCrusherFrame()
{
}

void LotteryCrusherFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void LotteryCrusherFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void LotteryCrusherFrame::OnAbout(wxCommandEvent &event)
{
#if defined(__WXMSW__)
        wxString msg = "build on Code::Blocks 13.12\r"+wxbuildinfo(long_f )+" with\rgcc version 4.8.3 20141208 [gcc-4_8-branch revision 218481]";
#elif defined(__WXMAC__)
    wxString msg = "build on Code::Blocks 13.12\r"+wxbuildinfo(long_f )+" with\rgcc version 4.8.3 20141208 [gcc-4_8-branch revision 218481]";
#elif defined(__UNIX__)
    wxString msg = "build on Code::Blocks 13.12\r"+wxbuildinfo(long_f )+" with\rgcc version 4.8.3 20141208 [gcc-4_8-branch revision 218481]";
#endif
    wxMessageBox(msg, _("Welcome to Lottery Crusher"));
}

void LotteryCrusherFrame::OnAktivateProgram(wxCommandEvent& event)
{
    if(!this->isactiveted())
    {
        this->dialogs= new ActivationDialog(this,wxID_ANY,"Activation");
        this->dialogs->ShowModal();
    }
}

void LotteryCrusherFrame::OnSettings(wxCommandEvent& event)
{
    this->dialogs= new SettingsDialog(this,wxID_ANY,"Activation");
    this->dialogs->ShowModal();
}

void LotteryCrusherFrame::OnEuromillionen(wxCommandEvent& event)
{
    firstpaint=true;
    lotto->setLotto(1);
    SetStatusText(lotto->askName()+" "+lotto->askSystemof(), 1);
    this->Refresh();
    //this->SetFocus();
    //this->Refresh();
    //this->Maximize();
}

void LotteryCrusherFrame::OnAustria(wxCommandEvent& event)
{
    firstpaint=true;
    lotto->setLotto(2);
    SetStatusText(lotto->askName()+" "+lotto->askSystemof(), 1);
    this->Refresh();
}

void LotteryCrusherFrame::OnFrance(wxCommandEvent& event)
{
    firstpaint=true;
    lotto->setLotto(3);
    SetStatusText(lotto->askName()+" "+lotto->askSystemof(), 1);
    this->Refresh();
}

void LotteryCrusherFrame::OnGermany(wxCommandEvent& event)
{
    lotto->setLotto(4);
    SetStatusText(lotto->askName()+" "+lotto->askSystemof(), 1);
    this->Refresh();
}

void LotteryCrusherFrame::OnHungary(wxCommandEvent& event)
{
    firstpaint=true;
    lotto->setLotto(5);
    SetStatusText(lotto->askName()+" "+lotto->askSystemof(), 1);
    this->Refresh();
}
void LotteryCrusherFrame::OnItaly(wxCommandEvent& event)
{
    firstpaint=true;
    lotto->setLotto(6);
    SetStatusText(lotto->askName()+" "+lotto->askSystemof(), 1);
    this->Refresh();
}

void LotteryCrusherFrame::OnSpainB(wxCommandEvent& event)
{
    firstpaint=true;
    lotto->setLotto(7);
    SetStatusText(lotto->askName()+" "+lotto->askSystemof(), 1);
    this->Refresh();
}

void LotteryCrusherFrame::OnSpainI(wxCommandEvent& event)
{
    firstpaint=true;
    lotto->setLotto(8);
    SetStatusText(lotto->askName()+" "+lotto->askSystemof(), 1);
    this->Refresh();
}

void LotteryCrusherFrame::OnCompute(wxCommandEvent& event)
{
    aktion=201;
}

void LotteryCrusherFrame::OnComputeWithN(wxCommandEvent& event)
{
    aktion=202;
}

void LotteryCrusherFrame::OnWinNew(wxCommandEvent& event)
{
    aktion=301;
}

void LotteryCrusherFrame::OnWinCorr(wxCommandEvent& event)
{
    aktion=302;
}

void LotteryCrusherFrame::On2DPlot(wxCommandEvent& event)
{
    aktion=401;
}

void LotteryCrusherFrame::On3DPlot(wxCommandEvent& event)
{
    aktion=402;
}

void LotteryCrusherFrame::OnPaint(wxPaintEvent & evt)
{
    if(firstpaint)
    {
        wxPaintDC dc(this);
        firstpaint=false;
        this->fenster->drawBack(dc);
        this->fenster->draw(dc);
    }
    else
    {
        wxClientDC dc(this);
        this->fenster->drawBack(dc);
        this->fenster->draw(dc);
    }


}

bool LotteryCrusherFrame::activateStartup()
{
    activated=false;
    return activated;
}

bool LotteryCrusherFrame::isactiveted()
{
    return activated;
}
