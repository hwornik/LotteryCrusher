#ifndef DATAIO_H
#define DATAIO_H

#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/textfile.h>
#include <wx/file.h>
#include <wx/string.h>
#include <wx/arrstr.h>

static const wxString programname="LotteryCrusher";

class DataIO
{
    public:
        DataIO();
        wxArrayString readSettingsData();
        bool writeSettingsData(wxString vname, wxString nname,wxString ordernr);
        unsigned char *readLicense();
        bool writeLicense(unsigned char *code);
        virtual ~DataIO();
    protected:
    private:
        wxString  datadir;
        wxString  seperator;
        wxString  filesettings;
        wxString  filelicence;

};

#endif // DATAIO_H
