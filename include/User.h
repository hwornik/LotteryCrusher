#ifndef USER_H
#define USER_H

#include <wx/string.h>

class User
{
    public:
        User();
        wxString getVName();
        void setVName(wxString vname);
        wxString getNName();
        void setNName(wxString nname);
        wxString getOrderNr();
        void setOrderNr(wxString ordernr);
        virtual ~User();
    protected:
    private:
        wxString vname;
        wxString nname;
        wxString ordernr;
};

#endif // USER_H
