/***************************************************************
 * Name:      LotteryCrusherMain.h
 * Purpose:   Defines Application Frame
 * Author:    Hans Wornik (hans@wornik.eu)
 * Created:   2015-05-04
 * Copyright: Hans Wornik (www.wornik.eu)
 * License:
 **************************************************************/

#ifndef LOTTERYCRUSHERMAIN_H
#define LOTTERYCRUSHERMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "LotteryCrusherApp.h"
#include "include/Lotto.h"
#include "include/Hauptfenster.h"
#include "include/Welcome.h"
#include "include/ActivationDialog.h"
#include "include/SettingsDialog.h"
#include "include/DataIO.h"
#include "include/SHA.h"

#include <wx/dcbuffer.h>

class LotteryCrusherFrame: public wxFrame
{
    public:
        LotteryCrusherFrame(wxFrame *frame, const wxString& title);
        bool isactiveted();
        ~LotteryCrusherFrame();
    private:
        Hauptfenster* fenster;
        Lotto* lotto;
        wxDialog* dialogs;
        int aktion;
        bool firstpaint,activated;
        wxString *vname,*nname,*serialn,*code,*key,*mac1,*mac2,*mac3,*home;
        void activateStartup();
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout,
            idMenuAktivate = 1200,
            idMenuSettings = 1300,
            // Lotterien
            idMenuEuro = 1101,
            idMenuAustria = 1102,
            idMenuFrance = 1103,
            idMenuGermany = 1104,
            idMenuHungary = 1105,
            idMenuItaly = 1106,
            idMenuSpainI = 1107,
            idMenuSpainB = 1108,
            //Tipmenu
            idMenuCompute = 2100,
            idMenuCompWithN =2200,
            //winning
            idMenuWinNew = 3100,
            idMenuWinCorr = 3200,
            //graph
            idMenu2DPlot = 4100,
            idMenu3DPlot = 4200
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnAktivateProgram(wxCommandEvent& event);
        void OnSettings(wxCommandEvent& event);
        void OnEuromillionen(wxCommandEvent& event);
        void OnAustria(wxCommandEvent& event);
        void OnFrance(wxCommandEvent& event);
        void OnGermany(wxCommandEvent& event);
        void OnHungary(wxCommandEvent& event);
        void OnItaly(wxCommandEvent& event);
        void OnSpainB(wxCommandEvent& event);
        void OnSpainI(wxCommandEvent& event);
        void OnCompute(wxCommandEvent& event);
        void OnComputeWithN(wxCommandEvent& event);
        void OnWinNew(wxCommandEvent& event);
        void OnWinCorr(wxCommandEvent& event);
        void On2DPlot(wxCommandEvent& event);
        void On3DPlot(wxCommandEvent& event);
        void OnPaint(wxPaintEvent & evt);
        DECLARE_EVENT_TABLE()
};


#endif // LOTTERYCRUSHERMAIN_H
