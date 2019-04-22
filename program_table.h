#ifndef __PROGRAM_TABLE_H__
#define __PROGRAM_TABLE_H__

#include "common.h"

#include <vector>
#include <wx/listctrl.h>

class ProgramTable : public wxListCtrl {

private:
    //std::vector<Byte> data;
    Byte *data;
    size_t size;
    bool show_decimal;

public:
    ProgramTable(wxWindow *parent, wxWindowID id);
    virtual wxString OnGetItemText(long item, long col) const;
    Byte *GetData();
    void SetData(Byte *data, size_t size);
    void SetItem(long item, long col, Byte value);
    void Refresh();
    void ResizeCols();
};

#endif // __PROGRAM_TABLE_H__
