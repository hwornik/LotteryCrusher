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

class LotteryCrusherFrame: public wxFrame
{
    public:
        LotteryCrusherFrame(wxFrame *frame, const wxString& title);
        ~LotteryCrusherFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // LOTTERYCRUSHERMAIN_H
