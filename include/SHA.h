#ifndef SHA_H
#define SHA_H

#include <wx/string.h>

class SHA
{
    public:
        SHA();
        unsigned char *get512Hash(wxString basis);
        virtual ~SHA();
    protected:
    private:
        wxString key;
        unsigned char ergebnis[256];
};

#endif // SHA_H
