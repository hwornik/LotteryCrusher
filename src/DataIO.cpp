#include "../include/DataIO.h"

DataIO::DataIO()
{
    //ctor
    datadir= wxStandardPaths::Get().GetUserLocalDataDir();
    #if defined(__WXMSW__)
        seperator="\\";
    #else
        seperator="/";
    #endif
    filelicence="LCrusher.lic";
    filesettings="LCrusher.dat";
}

DataIO::~DataIO()
{
    //dtor
}
