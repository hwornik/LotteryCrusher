#include "../include/DataIO.h"

DataIO::DataIO()
{
    //ctor
    #if defined(__WXMSW__)
        seperator="\\";
        datadir= wxStandardPaths::Get().GetUserLocalDataDir()+seperator+programname;

    #else
        seperator="/";
        datadir= wxStandardPaths::Get().GetUserLocalDataDir()+seperator+"."+programname;

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
    zeigerchar= code;
    if(wxFileName::FileExists(datadir+seperator+filelicence))
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
