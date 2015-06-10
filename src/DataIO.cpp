#include "../include/DataIO.h"

DataIO::DataIO()
{
    //ctor
#if defined(__WXMSW__)
    seperator="\\";
    datadir= wxStandardPaths::Get().GetUserLocalDataDir();

#else
    seperator="/";
    datadir= wxStandardPaths::Get().GetUserLocalDataDir();

#endif
    filelicence="LCrusher.lic";
    filesettings="LCrusher.dat";
    if(!wxFileName::DirExists(datadir))
        wxFileName::Mkdir(datadir);
}

bool DataIO::readSettingsData(wxString *vorname, wxString *nachname, wxString serialnumber)
{
    if(wxFileName::FileExists(datadir+seperator+filesettings))
    {
        return true;
    }
    else
        return false;
}

unsigned char *DataIO::readLicense()
{
    unsigned char *zeigerchar;
    unsigned char code[256] ;
    register int i;
    for(i=0;i<255;i+=2)
    {
            code[i]='0';
            code[i+1]='f';
    }
    zeigerchar= code;
    if(wxFileName::FileExists(datadir+filelicence))
    {
        return zeigerchar;
    }
    else
        return zeigerchar;
}

DataIO::~DataIO()
{
    //dtor
}
