#include "data_table.h"

DataTable::DataTable(wxWindow *parent, wxWindowID id)
    : wxListCtrl(parent, id, wxDefaultPosition, wxSize(210, 500), wxLC_REPORT | wxLC_VIRTUAL | wxLC_HRULES | wxLC_VRULES) {

#ifdef _WIN32
    int font_size = 10;
    long list_style = wxLIST_FORMAT_LEFT;
#else
    int font_size = 12;
    long list_style = wxLIST_FORMAT_RIGHT;
#endif

    SetFont(wxFont(font_size, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("")));
    InsertColumn(0, wxT("Endereço"), list_style, wxLIST_AUTOSIZE);
    InsertColumn(1, wxT("Valor"), list_style, wxLIST_AUTOSIZE);

    SetScrollbar(wxHORIZONTAL, 0, 0, 0);

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


void DataTable::ResizeCols() {
    double width = static_cast<double>(GetSize().GetWidth());
    SetColumnWidth(0, std::ceil(width / 2));
    SetColumnWidth(1, std::ceil(width / 2));
}
