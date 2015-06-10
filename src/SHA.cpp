#include "../include/SHA.h"

SHA::SHA()
{
    //ctor
}





unsigned char *SHA::get512Hash(wxString basis)
{
    register int i;
    for(i=0;i<255;i+=2)
    {
        ergebnis[i]='f';
        ergebnis[i+1]='0';
    }
    return ergebnis;
}

SHA::~SHA()
{
    //dtor
}
