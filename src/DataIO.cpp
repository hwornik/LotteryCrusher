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

 wxArrayString DataIO::readSettingsData()
{
    wxArrayString ergebnis;
    if(wxFileName::FileExists(datadir+seperator+filesettings))
    {
        wxTextFile txtfile(datadir+seperator+filesettings);
        txtfile.Open();
        if(!txtfile.Eof())
        ergebnis.Add(txtfile.GetFirstLine());
        if(!txtfile.Eof())
        ergebnis.Add(txtfile.GetNextLine());
        if(!txtfile.Eof())
        ergebnis.Add(txtfile.GetNextLine());
        txtfile.Close();
        return ergebnis;
    }
    else
    {
        return ergebnis;
    }
}

bool DataIO::writeSettingsData(wxString vname, wxString nname,wxString ordernr)
{

    wxTextFile txtfile(datadir+seperator+filesettings);
    if(!wxFileName::FileExists(datadir+seperator+filesettings))
    {
        txtfile.Create();
    }
    else
    {
        txtfile.Open();
        txtfile.Clear();
    }
    txtfile.AddLine(vname);
    txtfile.AddLine(nname);
    txtfile.AddLine(ordernr);
    bool written=txtfile.Write();
    txtfile.Close();
    return written;
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
    if(wxFileName::FileExists(datadir+seperator+filelicence))
    {
        wxFile binfile(datadir+seperator+filelicence);
        if(binfile.IsOpened())
        {
            binfile.Read(zeigerchar,256);
            binfile.Close();
        }
        return zeigerchar;
    }
    else
        return zeigerchar;
}

bool DataIO::writeLicense(unsigned char *code)
{
    bool written=false;
    wxFile binfile(datadir+seperator+filelicence, wxFile::write);
    binfile.Create(datadir+seperator+filelicence,true);
    if(binfile.IsOpened())
    {
        binfile.Write(code,256);
        written=true;
    }
    binfile.Close();
    return written;
}

DataIO::~DataIO()
{
    //dtor
}
