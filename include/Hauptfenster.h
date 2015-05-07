#ifndef HAUPTFENSTER_H
#define HAUPTFENSTER_H

#include <wx/dcbuffer.h>
#include <wx/frame.h>
#include <wx/dc.h>

#include "Lotto.h"


class Hauptfenster
{
    public:
        explicit Hauptfenster();
        virtual void draw(wxDC& dc)=0;
        virtual void drawBack(wxDC& dc)=0;
        ~Hauptfenster();
    protected:
        Lotto *lotto;
        wxFrame *those;
    private:
};

#endif // HAUPTFENSTER_H
