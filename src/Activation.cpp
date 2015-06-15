#include "../include/Activation.h"

Activation::Activation()
{
    this->ComputeHardewareInfos();
    //ctor
}

void Activation::ComputeHardewareInfos()
{
   SYSTEM_INFO siSysInfo;

   // Copy the hardware information to the SYSTEM_INFO structure.

   ::GetSystemInfo(&siSysInfo);

   // Display the contents of the SYSTEM_INFO structure.

   hwinfoOEM=wxString::Format(wxT("%u"),siSysInfo.wProcessorLevel);
   hwinfoCores=wxString::Format(wxT("%u"),siSysInfo.wProcessorRevision);
   hwinfoType=wxString::Format(wxT("%u"),siSysInfo.dwProcessorType);
}

wxString Activation::gethwinfo()
{
    return hwinfoOEM+"-"+hwinfoCores+"-"+hwinfoType;
}
Activation::~Activation()
{
    //dtor
}
