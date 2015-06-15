#include "../include/ActivationDialog.h"

ActivationDialog::ActivationDialog(wxWindow* parent,
        wxWindowID id,
        const wxString& title)
    : wxDialog(parent, id, title,
            wxDefaultPosition, wxSize(400, 120))
{
    activationscontrol= new Activation();
    panel = new wxPanel(this, wxID_ANY);
    activationcode = new wxTextCtrl(panel, wxID_ANY ,activationscontrol->gethwinfo(),wxDefaultPosition, wxSize(200,20));
    cancelButton = new wxButton(panel, wxID_ANY, "Cancel");
    okButton = new wxButton(panel, wxID_ANY, "Ok");
    sizer = new wxGridSizer(2,3, 5, 5);
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Activationcode:"), 1,
            wxALL, 15);
    //sizer->AddStretchSpacer(1);
    //sizer->AddStretchSpacer(1);
    sizer->Add(activationcode, 3,
            wxALL , 15);
    sizer->AddStretchSpacer(1);
    sizer->AddStretchSpacer(1);
    //sizer->AddStretchSpacer(1);
    sizer->Add(okButton, 0,
            wxALL | wxALIGN_RIGHT | wxALIGN_BOTTOM, 10);
    sizer->Add(cancelButton, 0,
            wxALL | wxALIGN_RIGHT | wxALIGN_BOTTOM, 10);
    panel->SetSizer(sizer);
    Center();
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &ActivationDialog::onCancel,
            this, cancelButton->GetId());
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &ActivationDialog::onOk,
            this, okButton->GetId());

}

void ActivationDialog::onCancel(wxCommandEvent& pEvent)
{
    this->Destroy();
}

void ActivationDialog::onOk(wxCommandEvent& pEvent)
{
}
ActivationDialog::~ActivationDialog()
{
    //dtor
}
