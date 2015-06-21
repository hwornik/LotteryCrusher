#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <wx/wx.h>
#include <wx/stdpaths.h>

#include "Settings.h"
#include "../LotteryCrusherMain.h"
#include "Activation.h"

class SettingsDialog: public wxDialog
{
    public:
        SettingsDialog(wxWindow* parent, wxWindowID id,
                const wxString& title);
    void onCancel(wxCommandEvent& pEvent);
    void onOk(wxCommandEvent& pEvent);
    void setInactive(bool deactive);
    virtual ~SettingsDialog();
    protected:
    private:
        Activation *act;
        wxPanel* panel;
        wxTextCtrl *vorname, *nachname, *serialnumber;
        wxButton *cancelButton, *okButton;
        wxGridSizer *sizer;
        Settings *settingscontrol;
};

#endif // SETTINGSDIALOG_H
