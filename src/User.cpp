#include "User.h"

User::User()
{
    //ctor
}

wxString User::getVName()
{
    return vname;
}
void User::setVName(wxString vname)
{
    this->vname=vname;
}
wxString User::getNName()
{
    return nname;
}
void User::setNName(wxString nname)
{
    this->nname=nname;
}
wxString User::getOrderNr()
{
    return ordernr;
}
void User::setOrderNr(wxString ordernr)
{
    this->ordernr=ordernr;
}

User::~User()
{
    //dtor
}
