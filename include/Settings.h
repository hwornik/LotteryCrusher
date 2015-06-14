#ifndef SETTINGS_H
#define SETTINGS_H

#include <wx/filename.h>
#include <wx/filefn.h>
#include <wx/string.h>

#include "Person.h"
#include "DataIO.h"

class Settings
{
    public:
        Settings();
        wxString getVName();
        wxString getNName();
        wxString getOrderNr();
        void setVName(wxString vname);
        void setNName(wxString nname);
        void setOrderNr(wxString ordernr);
        void writeSettings();
        virtual ~Settings();
    protected:
    private:
        Person *user;
        DataIO *iodata;
};

#endif // SETTINGS_H
