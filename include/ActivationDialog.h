#ifndef ACTIVATIONDIALOG_H
#define ACTIVATIONDIALOG_H

#include <wx/wx.h>

#include "Activation.h"

class ActivationDialog : public wxDialog
{
    public:
        ActivationDialog(wxWindow* parent, wxWindowID id,
                const wxString& title);
    void onCancel(wxCommandEvent& pEvent);
    void onOk(wxCommandEvent& pEvent);
        virtual ~ActivationDialog();
    protected:
    private:
        wxPanel* panel;
        wxTextCtrl *activationcode;
        wxButton *cancelButton, *okButton;
        wxGridSizer *sizer;
        Activation *activationscontrol;
};

#endif // ACTIVATIONDIALOG_H
