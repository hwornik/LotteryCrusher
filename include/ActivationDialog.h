#ifndef ACTIVATIONDIALOG_H
#define ACTIVATIONDIALOG_H

#include <wx/wx.h>


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
};

#endif // ACTIVATIONDIALOG_H
