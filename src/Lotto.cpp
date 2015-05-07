#include "../include/Lotto.h"

Lotto::Lotto()
{
    this->setLotto(0);
}

void Lotto::setLotto(int lottery)
{
    this->lottery=lottery;
    switch(lottery)
    {
        case 1:
            name="Euromillions";
            systemof="6 of 50 and 2 of 11";
            numbers=5;
            maxnumbers=50;
            zusatzzahlen=2;
            maxzusatzzahlen=11;
            break;
        case 2:
            name="Austria";
            systemof="6 of 45";
            numbers=6;
            maxnumbers=45;
            zusatzzahlen=0;
            maxzusatzzahlen=0;
            break;
        case 3:
            name="France";
            systemof="6 of 49";
            numbers=6;
            maxnumbers=49;
            zusatzzahlen=0;
            maxzusatzzahlen=0;
            break;
        case 4:
            name="Germany";
            systemof="6 of 49";
            numbers=6;
            maxnumbers=49;
            zusatzzahlen=0;
            maxzusatzzahlen=0;
            break;
        case 5:
            name="Hungary";
            systemof="6 of 45";
            numbers=6;
            maxnumbers=45;
            zusatzzahlen=0;
            maxzusatzzahlen=0;
            break;
        case 6:
            name="Italy";
            systemof="6 of 90";
            numbers=6;
            maxnumbers=90;
            zusatzzahlen=0;
            maxzusatzzahlen=0;
            break;
        case 7:
            name="SpainI";
            systemof="6 of 49";
            numbers=6;
            maxnumbers=49;
            zusatzzahlen=0;
            maxzusatzzahlen=0;
            break;
        case 8:
            name="SpainB";
            systemof="6 of 49";
            numbers=6;
            maxnumbers=49;
            zusatzzahlen=0;
            maxzusatzzahlen=0;
            break;
        default:
            name="no lottery choosen";
            systemof="";
            numbers=0;
            maxnumbers=0;
            zusatzzahlen=0;
            maxzusatzzahlen=0;
            break;
    }
}

wxString Lotto::askName()
{
    return name;
}

int Lotto::askNameint()
{
    return lottery;
}

wxString Lotto::askSystemof()
{
    return systemof;
}
Lotto::~Lotto()
{
    //dtor
}
