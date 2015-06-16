#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <wx/string.h>
#include <stdio.h>

#if defined(__WXMSW__)
        #include <Windows.h>
#elif defined(__WXMAC__)

#elif defined(__UNIX__)
    #include "DataIO.h"
    #include <wx/arrstr.h>
    #include <wx/tokenzr.h>
#endif


using namespace std;

class Activation
{
    public:
        Activation();
        wxString gethwinfo();
        ~Activation();
    protected:
    private:
        void ComputeHardewareInfos();
        wxString hwinfoOEM;
        wxString hwinfoType;
        wxString hwinfoCores;
};

#endif // ACTIVATION_H
