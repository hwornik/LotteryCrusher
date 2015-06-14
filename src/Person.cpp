#include "Person.h"

Person::Person()
{
    this->vname="";
    this->nname="";
    this->ordernr="";
}

wxString Person::getVName()
{
    return vname;
}
void Person::setVName(wxString vname)
{
    this->vname=vname;
}
wxString Person::getNName()
{
    return nname;
}
void Person::setNName(wxString nname)
{
    this->nname=nname;
}
wxString Person::getOrderNr()
{
    return ordernr;
}
void Person::setOrderNr(wxString ordernr)
{
    this->ordernr=ordernr;
}
bool Person::loadUser()
{
    DataIO *data= new DataIO();
    wxArrayString ergebnis;
    ergebnis=data->readSettingsData();
    if(!ergebnis.IsEmpty())
    {
        vname=ergebnis.Item(0);
        nname=ergebnis.Item(1);
        ordernr=ergebnis.Item(2);
        return true;
    }
    return false;
}

bool Person::storeUser()
{
    DataIO *data= new DataIO();
    return data->writeSettingsData(vname,nname,ordernr);
}


Person::~Person()
{
    //dtor
}
