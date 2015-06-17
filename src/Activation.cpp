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
   hwinfoCPUType=wxString::Format(wxT("%u"),siSysInfo.wProcessorLevel);
   hwinfoCores=wxString::Format(wxT("%u"),siSysInfo.dwNumberOfProcessors);
   puffer=wxString::Format(wxT("%1x"),siSysInfo.wProcessorRevision);
   hwinfoStepping=puffer[3];
#elif defined(__WXMAC__)

#elif defined(__UNIX__)
    DataIO *readHW= new DataIO();
    wxArrayString hwarray;
    wxStringTokenizer tokens;
    wxString line;
    hwarray=readHW->readHWInfo();
    line=hwarray.Item(0);
    tokens.SetString(line,":");
    tokens.GetNextToken();
    hwinfoCPUType=tokens.GetNextToken();
    hwinfoCPUType=hwinfoCPUType.Trim(false);
    line=hwarray.Item(2);
    tokens.SetString(line,":");
    tokens.GetNextToken();
    hwinfoCores=tokens.GetNextToken();
    hwinfoCores=hwinfoCores.Trim(false);
    line=hwarray.Item(1);
    tokens.SetString(line,":");
    tokens.GetNextToken();
    hwinfoStepping=tokens.GetNextToken();
    hwinfoStepping=hwinfoStepping.Trim(false);
#endif
}

wxString Activation::gethwinfo()
{
    return hwinfoCPUType+"-"+hwinfoCores+"-"+hwinfoStepping;
}
Activation::~Activation()
{
    //dtor
}
