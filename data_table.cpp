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

    SetBackgroundColour(wxColour("#ffffff"));
    SetFont(wxFont(font_size, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("")));

    InsertColumn(0, wxT("Endereço"), list_style, wxLIST_AUTOSIZE);
    InsertColumn(1, wxT("Valor"), list_style, wxLIST_AUTOSIZE);

    data.reserve(MEM_SIZE);
    std::fill(begin(data), end(data), 0);

    SetItemCount(MEM_SIZE);
    ResizeCols();
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
    int scrollbar_width = 10;
    double q = static_cast<double>(GetSize().GetWidth()) / 2 - scrollbar_width;
    SetColumnWidth(0, std::ceil(q));
    SetColumnWidth(1, std::ceil(q));

    SetScrollbar(wxHORIZONTAL, 0, 0, 0, true); }
