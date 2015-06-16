#include "../include/Activation.h"

Activation::Activation()
{
    this->ComputeHardewareInfos();
    //ctor
}

void Activation::ComputeHardewareInfos()
{
#if defined(__WXMSW__)
SYSTEM_INFO siSysInfo;

   // Copy the hardware information to the SYSTEM_INFO structure.

   ::GetSystemInfo(&siSysInfo);

   // Display the contents of the SYSTEM_INFO structure.
   wxString puffer;
   hwinfoOEM=wxString::Format(wxT("%u"),siSysInfo.wProcessorLevel);
   hwinfoCores=wxString::Format(wxT("%u"),siSysInfo.dwNumberOfProcessors);
   puffer=wxString::Format(wxT("%1x"),siSysInfo.wProcessorRevision);
   hwinfoType=puffer[3];
   #elif defined(__WXMAC__)

#elif defined(__UNIX__)
char PSN[30];
    int varEAX, varEBX, varECX, varEDX;
    char str[9];

    //%eax=1 gives most significant 32 bits in eax
    __asm__ __volatile__ ("cpuid"   : "=a" (varEAX), "=b" (varEBX), "=c" (varECX), "=d" (varEDX) : "a" (1));
    sprintf(str, "%08X", varEAX); //i.e. XXXX-XXXX-xxxx-xxxx-xxxx-xxxx
    sprintf(PSN, "%C%C%C%C-%C%C%C%C", str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7]);
    hwinfoOEM << varEAX << varEBX;
    hwinfoCores << str;
    hwinfoType << varEDX;
#endif
}

inline void Activation::native_cpuid(unsigned int *eax, unsigned int *ebx,
                                unsigned int *ecx, unsigned int *edx)
{
        /* ecx is often an input as well as an output. */
        asm volatile("cpuid"
            : "=a" (*eax),
              "=b" (*ebx),
              "=c" (*ecx),
              "=d" (*edx)
            : "0" (*eax), "2" (*ecx));
}

wxString Activation::gethwinfo()
{
    return hwinfoOEM+"-"+hwinfoCores+"-"+hwinfoType;
}
Activation::~Activation()
{
    //dtor
}
