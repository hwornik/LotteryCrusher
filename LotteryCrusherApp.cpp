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
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "LotteryCrusherApp.h"
#include "LotteryCrusherMain.h"

IMPLEMENT_APP(LotteryCrusherApp);

bool LotteryCrusherApp::OnInit()
{
    LotteryCrusherFrame* frame = new LotteryCrusherFrame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}
