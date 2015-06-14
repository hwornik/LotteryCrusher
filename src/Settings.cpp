#include "../include/Settings.h"

Settings::Settings()
{
    iodata = new DataIO();
    user = new Person();
    user->loadUser();
    //ctor
}

wxString Settings::getVName()
{
    return user->getVName();
}
wxString Settings::getNName()
{
    return user->getNName();
}
wxString Settings::getOrderNr()
{
    return user->getOrderNr();
}

void Settings::setVName(wxString vname)
{
    user->setVName(vname);
}
void Settings::setNName(wxString nname)
{
    user->setNName(nname);
}
void Settings::setOrderNr(wxString ordernr)
{
    user->setOrderNr(ordernr);
}

void Settings::writeSettings()
{
    this->user->storeUser();
}

Settings::~Settings()
{
    //dtor
}
