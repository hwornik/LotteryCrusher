#ifndef SETTINGS_H
#define SETTINGS_H

#include <wx/filename.h>
#include <wx/filefn.h>

class Settings
{
    public:
        Settings();
        bool readSettingsData(wxString *vorname, wxString *nachname, wxString serialnumber);
        virtual ~Settings();
    protected:
    private:
};

#endif // SETTINGS_H
