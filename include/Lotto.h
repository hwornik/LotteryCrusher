#ifndef LOTTO_H
#define LOTTO_H

#include <wx/string.h>

class Lotto
{
    public:
        Lotto();
        void setLotto(int lottery);
        wxString askName();
        wxString askSystemof();
        int askNameint();
        virtual ~Lotto();
    protected:
    private:
        int lottery;
        int numbers;
        int maxnumbers;
        int zusatzzahlen;
        int maxzusatzzahlen;
        wxString name;
        wxString systemof;
};

#endif // LOTTO_H
