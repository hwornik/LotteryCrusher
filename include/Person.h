#ifndef PERSON_H
#define PERSON_H
#include <wx/string.h>

#include "DataIO.h"

class Person
{
    public:
        Person();
        virtual ~Person();
        wxString getVName();
        void setVName(wxString vname);
        wxString getNName();
        void setNName(wxString nname);
        wxString getOrderNr();
        void setOrderNr(wxString ordernr);
        bool loadUser();
        bool storeUser();
        bool isOK();
    protected:
    private:
        wxString vname;
        wxString nname;
        wxString ordernr;
};

#endif // PERSON_H
