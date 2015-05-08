#include "../include/Welcome.h"

Welcome::Welcome(Lotto *lotto, wxFrame *those) : Hauptfenster()
{
    this->lotto=lotto;
    this->those=those;
}

void Welcome::draw(wxDC& dc)
{
    int x,y;
    //this->SetBackgroundColour( wxColour( 220, 230, 250 ) );

    //dc.SetBrush(*wxGREEN_BRUSH);
    wxFont font(20,wxFONTFAMILY_SWISS,wxNORMAL,wxNORMAL);
    dc.SetFont(font);
    dc.SetBackgroundMode(wxTRANSPARENT);
    dc.SetTextForeground(*wxBLUE);

    wxSize sz= those->GetSize();

    wxString str="Welcome";
    wxCoord w,h;
    dc.GetTextExtent(str, &w, &h);
    x = wxMax(0,(sz.x-w)/2);
    y = wxMax(0, (sz.y -h)/2);
    if(x>0 && x< sz.x && y-190>0 && y-170<sz.y)
    dc.DrawText(str,x,y-180);
    str="to";
    dc.GetTextExtent(str, &w, &h);
    x = wxMax(0,(sz.x-w)/2);
    y = wxMax(0, (sz.y -h)/2);
    if(x>0 && x< sz.x && y-140>0 && y-120<sz.y)
    dc.DrawText(str,x,y-130);
    str="Lottery Crusher";
    dc.GetTextExtent(str, &w, &h);
    x = wxMax(0,(sz.x-w)/2);
    y = wxMax(0, (sz.y -h)/2);
    if(x>0 && x< sz.x && y-90>0 && y-70<sz.y)
    dc.DrawText(str,x,y-80);
    if(lotto->askNameint()==0)
    {
        str="for Euromillions, Austria,";
        dc.GetTextExtent(str, &w, &h);
        x = wxMax(0,(sz.x-w)/2);
        y = wxMax(0, (sz.y -h)/2);
        if(x>0 && x< sz.x && y-40>0 && y-20<sz.y)
        dc.DrawText(str,x,y-30);
        str="Germany, France, Hungary,";
        dc.GetTextExtent(str, &w, &h);
        x = wxMax(0,(sz.x-w)/2);
        y = wxMax(0, (sz.y -h)/2);
        if(x>0 && x< sz.x && y+10>0 && y+30<sz.y)
        dc.DrawText(str,x,y+20);
        str="and the Spain Lottery";
        dc.GetTextExtent(str, &w, &h);
        x = wxMax(0,(sz.x-w)/2);
        y = wxMax(0, (sz.y -h)/2);
        if(x>0 && x< sz.x && y+60>0 && y+80<sz.y)
        dc.DrawText(str,x,y+70);
    }
    else
    {
        str="for "+this->lotto->askName();
        dc.GetTextExtent(str, &w, &h);
        x = wxMax(0,(sz.x-w)/2);
        y = wxMax(0, (sz.y -h)/2);
        if(x>0 && x< sz.x && y-40>0 && y-20<sz.y)
        dc.DrawText(str,x,y-30);
        str=this->lotto->askSystemof();
        dc.GetTextExtent(str, &w, &h);
        x = wxMax(0,(sz.x-w)/2);
        y = wxMax(0, (sz.y -h)/2);
        if(x>0 && x< sz.x && y+10>0 && y+30<sz.y)
        dc.DrawText(str,x,y+20);
    }
}

void Welcome::drawBack(wxDC& dc)
{
    wxSize sz= those->GetSize();
    dc.SetBrush(*wxLIGHT_GREY);
    dc.SetPen(*wxLIGHT_GREY);
    dc.DrawRectangle(0,0,sz.x,sz.y);
}

Welcome::~Welcome()
{
    //dtor
}
