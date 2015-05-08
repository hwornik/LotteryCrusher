#include "ActivationDialog.h"

ActivationDialog::ActivationDialog(wxWindow* parent,
        wxWindowID id,
        const wxString& title)
    : wxDialog(parent, id, title,
            wxDefaultPosition, wxSize(300, 200))
{
    //ctor
}

void ActivationDialog::onCancel(wxCommandEvent& pEvent)
{
}
void ActivationDialog::onOk(wxCommandEvent& pEvent)
{
}
ActivationDialog::~ActivationDialog()
{
    //dtor
}
