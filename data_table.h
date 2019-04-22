#ifndef __DATA_TABLE_H__
#define __DATA_TABLE_H__

#include "common.h"

#include <vector>
#include <wx/listctrl.h>

class DataTable : public wxListCtrl {

private:
    //std::vector<Byte> data;
    //Byte data[MEM_SIZE];
    Byte *data;
    size_t size;

public:
    DataTable(wxWindow *parent, wxWindowID id);
    virtual wxString OnGetItemText(long item, long col) const;
    void SetItem(long item, long col, Byte value);
    Byte *GetData();
    void SetData(Byte *data, size_t size);
    void Refresh();
    void ResizeCols();
};

#endif // __DATA_TABLE_H__
