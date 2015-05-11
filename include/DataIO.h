#ifndef DATAIO_H
#define DATAIO_H

#include <wx/stdpaths.h>

class DataIO
{
    public:
        DataIO();
        virtual ~DataIO();
    protected:
    private:
        wxString  datadir;
        wxString  seperator;
        wxString  filesettings;
        wxString  filelicence;
};

#endif // DATAIO_H
