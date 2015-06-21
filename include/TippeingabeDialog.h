#ifndef TIPPEINGABEDIALOG_H
#define TIPPEINGABEDIALOG_H

#include <wx/wx.h>


class TippeingabeDialog : public wxDialog
{
    public:
        TippeingabeDialog(wxWindow* parent, wxWindowID id,
                const wxString& title);
        virtual ~TippeingabeDialog();
    protected:
    private:
};

#endif // TIPPEINGABEDIALOG_H
