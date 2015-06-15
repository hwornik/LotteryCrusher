#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <wx/string.h>
#include <stdio.h>

#if defined(__WXMSW__)
        #include <Windows.h>
#elif defined(__WXMAC__)

#elif defined(__UNIX__)
    #include <cpuid.h>
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
    inline void native_cpuid(unsigned int *eax, unsigned int *ebx,
                                unsigned int *ecx, unsigned int *edx);
        void ComputeHardewareInfos();
        wxString hwinfoOEM;
        wxString hwinfoType;
        wxString hwinfoCores;
};

#endif // ACTIVATION_H
