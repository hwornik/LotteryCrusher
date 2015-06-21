#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <wx/string.h>
#include <stdio.h>
#include "DataIO.h"
#include "Person.h"
#include "SHA.h"

#if defined(__WXMSW__)
        #include <Windows.h>
#elif defined(__WXMAC__)

#elif defined(__UNIX__)
    #include "DataIO.h"
    #include <wx/arrstr.h>
    #include <wx/tokenzr.h>
#endif


using namespace std;

static bool programactivated;

class Activation
{
    public:

        Activation();
        wxString gethwinfo();
        bool test();
        bool isActivated();
        ~Activation();

    protected:
    private:
        void ComputeHardewareInfos();
        wxString hwinfoStepping;
        wxString hwinfoCPUType;
        wxString hwinfoCores;
};

#endif // ACTIVATION_H
