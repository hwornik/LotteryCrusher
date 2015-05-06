/***************************************************************
 * Name:      LotteryCrusherApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Hans Wornik (hans@wornik.eu)
 * Created:   2015-05-04
 * Copyright: Hans Wornik (www.wornik.eu)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#include "wx/sizer.h"
#include <stdio.h>
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "LotteryCrusherApp.h"
#include "LotteryCrusherMain.h"

IMPLEMENT_APP(LotteryCrusherApp);

bool LotteryCrusherApp::OnInit()
{
    LotteryCrusherFrame* frame = new LotteryCrusherFrame(0L, _("Lottery Crusher"));
    //frame->SetBackgroundColour( wxColour( 220, 230, 250 ) );
    frame->Show();
    return true;
}
