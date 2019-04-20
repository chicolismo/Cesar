#ifndef __DATA_TABLE_H__
#define __DATA_TABLE_H__

#include "common.h"

#include <vector>
#include <wx/listctrl.h>

class DataTable : public wxListCtrl {

private:
    std::vector<Byte> data;

public:
    DataTable(wxWindow *parent, wxWindowID id);
    virtual wxString OnGetItemText(long item, long col) const;
    void SetItem(long item, long col, Byte value);
    void ResizeCols();
};

#endif // __DATA_TABLE_H__
