#ifndef DATAIO_H
#define DATAIO_H

#include <wx/stdpaths.h>
#include <wx/filename.h>

static const wxString programname="LotteryCrusher";

class DataIO
{
    public:
        DataIO();
        bool readSettingsData(wxString *vorname, wxString *nachname, wxString serialnumber);
        unsigned char *readLicense();
        virtual ~DataIO();
    protected:
    private:
        wxString  datadir;
        wxString  seperator;
        wxString  filesettings;
        wxString  filelicence;

};

#endif // DATAIO_H
