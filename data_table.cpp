#include "data_table.h"

DataTable::DataTable(wxWindow *parent, wxWindowID id)
    : wxListCtrl(parent, id, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_VIRTUAL | wxLC_HRULES | wxLC_VRULES) {

    InsertColumn(0, wxT("Endereço"), wxLIST_FORMAT_RIGHT, wxLIST_AUTOSIZE);
    InsertColumn(1, wxT("Valor"), wxLIST_FORMAT_RIGHT, wxLIST_AUTOSIZE);

    data.reserve(MEM_SIZE);
    std::fill(begin(data), end(data), 0);
    SetItemCount(MEM_SIZE);
}


wxString DataTable::OnGetItemText(long item, long col) const {
    wxString buffer;
    if (col == 0) {
        buffer.Printf("%ld", item);
    }
    else {
        buffer.Printf("%d", data[item]);
    }
    return buffer;
}


void DataTable::SetItem(long item, long col, Byte value) {
    data[item] = value;
}
