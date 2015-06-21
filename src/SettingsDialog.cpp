#include "../include/SettingsDialog.h"

SettingsDialog::SettingsDialog(wxWindow* parent,
        wxWindowID id,
        const wxString& title)
    : wxDialog(parent, id, title,
            wxDefaultPosition, wxSize(400, 200))
{
    settingscontrol = new Settings();
    act = new Activation();
    wxString dirdat= settingscontrol->getVName();
    wxString dirdat2= settingscontrol->getNName();
    wxString dirdat3= settingscontrol->getOrderNr();
    panel = new wxPanel(this, wxID_ANY);
    vorname = new wxTextCtrl(panel,wxID_ANY,dirdat,wxDefaultPosition, wxSize(150,20));
    nachname = new wxTextCtrl(panel,wxID_ANY,dirdat2,wxDefaultPosition, wxSize(150,20));
    serialnumber = new wxTextCtrl(panel, wxID_ANY, dirdat3,wxDefaultPosition, wxSize(150,20));
    this->setInactive(!act->isActivated());
    cancelButton = new wxButton(panel, wxID_ANY, "Cancel");
    okButton = new wxButton(panel, wxID_ANY, "Ok");
    sizer = new wxGridSizer(2, 5, 5);
    sizer->Add(new wxStaticText(panel, wxID_ANY, "First name:"), 0,
            wxALL, 15);
    sizer->Add(vorname, 0,
            wxALL, 15);
    //sizer->AddStretchSpacer(1);
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Family name:"), 0,
            wxALL, 15);
    sizer->Add(nachname, 0,
            wxALL, 15);
    //sizer->AddStretchSpacer(1);
    sizer->Add(new wxStaticText(panel, wxID_ANY, "Invoice number:"), 0,
            wxALL, 15);
    sizer->Add(serialnumber, 0,
            wxALL, 15);
    sizer->AddStretchSpacer(1);
    sizer->AddStretchSpacer(1);
    sizer->Add(okButton, 0,
            wxALL | wxALIGN_RIGHT | wxALIGN_BOTTOM, 10);
    sizer->Add(cancelButton, 0,
            wxALL | wxALIGN_RIGHT | wxALIGN_BOTTOM, 10);
    panel->SetSizer(sizer);
    Center();
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &SettingsDialog::onCancel,
            this, cancelButton->GetId());
    Bind(wxEVT_COMMAND_BUTTON_CLICKED, &SettingsDialog::onOk,
            this, okButton->GetId());
}

void SettingsDialog::onCancel(wxCommandEvent& pEvent)
{
    this->Destroy();
}

void SettingsDialog::onOk(wxCommandEvent& pEvent)
{
    settingscontrol->setVName(vorname->GetLineText(0));
    settingscontrol->setNName(nachname->GetLineText(0));
    settingscontrol->setOrderNr(serialnumber->GetLineText(0));
    settingscontrol->writeSettings();
    this->Destroy();
}

void SettingsDialog::setInactive(bool deactive)
{
    vorname->SetEditable(deactive);
    nachname->SetEditable(deactive);
    serialnumber->SetEditable(deactive);
}
SettingsDialog::~SettingsDialog()
{
    //dtor
}
