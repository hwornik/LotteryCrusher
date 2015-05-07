#ifndef WELCOME_H
#define WELCOME_H


#include "Hauptfenster.h"
#include "Lotto.h"
#include <wx/dc.h>
#include <wx/frame.h>

class Welcome : public Hauptfenster
{
    public:
        Welcome(Lotto *lotto, wxFrame *those);
        void draw(wxDC& dc);
        void drawBack(wxDC& dc);
        ~Welcome();
    protected:
    private:
};

#endif // WELCOME_H
