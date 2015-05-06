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
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    wxMenu* lottoMenu = new wxMenu(_T(""));
    fileMenu->AppendSubMenu(lottoMenu, _("&Lottery"));
    // Lotterien anfang
    lottoMenu->Append(idMenuEuro, _("&Euromillions\tAlt-e"), _("Play Euromillions"));
    lottoMenu->Append(idMenuAustria, _("&Austria\tAlt-a"), _("6 of 45"));
    lottoMenu->Append(idMenuFrance, _("&France\tAlt-f"), _("6 of 49"));
    lottoMenu->Append(idMenuGermany, _("&Germany\tAlt-g"), _("6 of 49"));
    lottoMenu->Append(idMenuHungary, _("&Hungary\tAlt-h"), _("6 of 45"));
    lottoMenu->Append(idMenuItaly, _("&Italy\tAlt-i"), _("6 of 90"));
    lottoMenu->Append(idMenuSpainI, _("&SpainI\tAlt-s"), _("6 of 49"));
    lottoMenu->Append(idMenuSpainB, _("&SpainB\tAlt-b"), _("6 of 49"));
    //Lotterien ende
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
    graphMenu->Append(idMenu2DPlot, _("2d Plot"), _("Show 2DPlot of the winning numbers"));
    graphMenu->Append(idMenu3DPlot, _("23 Plot"), _("Show 3DPlot of the winning numbers"));
    mbar->Append(graphMenu, _("Plots"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Program not activated"),0);
    SetStatusText(wxbuildinfo(short_f), 1);

#endif // wxUSE_STATUSBAR
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
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void LotteryCrusherFrame::OnAktivateProgram(wxCommandEvent& event)
{

}

void LotteryCrusherFrame::OnSettings(wxCommandEvent& event)
{

}

void LotteryCrusherFrame::OnEuromillionen(wxCommandEvent& event)
{

}

void LotteryCrusherFrame::OnAustria(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnFrance(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnGermany(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnHungary(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnItaly(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnSpainB(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnSpainI(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnCompute(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnComputeWithN(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnWinNew(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnWinCorr(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::On2DPlot(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::On3DPlot(wxCommandEvent& event)
{
}

void LotteryCrusherFrame::OnPaint(wxPaintEvent & evt)
{

    wxPaintDC dc(this);
    this->draw(dc);
}

void LotteryCrusherFrame::draw(wxDC& dc)
{
    int x,y;
    this->SetBackgroundColour( wxColour( 220, 230, 250 ) );

    //dc.SetBrush(*wxGREEN_BRUSH);
    wxFont font(20,wxFONTFAMILY_SWISS,wxNORMAL,wxNORMAL);
    dc.SetFont(font);
    dc.SetBackgroundMode(wxTRANSPARENT);
    dc.SetTextForeground(*wxBLUE);

    wxSize sz= this->GetSize();

    wxString str="Welcome";
    wxCoord w,h;
    dc.GetTextExtent(str, &w, &h);
    x = wxMax(0,(sz.x-w)/2);
    y = wxMax(0, (sz.y -h)/2);
    dc.DrawText(str,x,y-180);
    str="to";
    dc.GetTextExtent(str, &w, &h);
    x = wxMax(0,(sz.x-w)/2);
    y = wxMax(0, (sz.y -h)/2);
    dc.DrawText(str,x,y-130);
    str="Lottery Crusher";
    dc.GetTextExtent(str, &w, &h);
    x = wxMax(0,(sz.x-w)/2);
    y = wxMax(0, (sz.y -h)/2);
    dc.DrawText(str,x,y-80);
    str="for Euromillions, Austria,";
    dc.GetTextExtent(str, &w, &h);
    x = wxMax(0,(sz.x-w)/2);
    y = wxMax(0, (sz.y -h)/2);
    dc.DrawText(str,x,y-30);
    str="Germany, France, Hungary,";
    dc.GetTextExtent(str, &w, &h);
    x = wxMax(0,(sz.x-w)/2);
    y = wxMax(0, (sz.y -h)/2);
    dc.DrawText(str,x,y+20);
    str="and the Spain Lottery";
    dc.GetTextExtent(str, &w, &h);
    x = wxMax(0,(sz.x-w)/2);
    y = wxMax(0, (sz.y -h)/2);
    dc.DrawText(str,x,y+70);


}

