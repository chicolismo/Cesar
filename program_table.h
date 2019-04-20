#ifndef __PROGRAM_TABLE_H__
#define __PROGRAM_TABLE_H__

#include "common.h"

#include <vector>
#include <wx/listctrl.h>

class ProgramTable : public wxListCtrl {

private:
    std::vector<Byte> data;

public:
    ProgramTable(wxWindow *parent, wxWindowID id);
    virtual wxString OnGetItemText(long item, long col) const;
    void SetItem(long item, long col, Byte value);
};

#endif // __PROGRAM_TABLE_H__
