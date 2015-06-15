#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <wx/string.h>
#include <Windows.h>
#include <stdio.h>



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
