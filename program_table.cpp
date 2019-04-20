#include "program_table.h"

ProgramTable::ProgramTable(wxWindow *parent, wxWindowID id)
    : wxListCtrl(parent, id, wxDefaultPosition, wxSize(380, 500), wxLC_REPORT | wxLC_VIRTUAL | wxLC_HRULES | wxLC_VRULES) {

#ifdef _WIN32
    long list_style = wxLIST_FORMAT_LEFT;
    int font_size = 10;
#else
    long list_style = wxLIST_FORMAT_RIGHT;
    int font_size = 12;
#endif

    SetFont(wxFont(font_size, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("")));

    InsertColumn(0, wxT("PC"), list_style, wxLIST_AUTOSIZE);
    InsertColumn(1, wxT("Endereço"), list_style, wxLIST_AUTOSIZE);
    InsertColumn(2, wxT("Valor"), list_style, wxLIST_AUTOSIZE);
    InsertColumn(3, wxT("Mnemônico"), wxLIST_FORMAT_LEFT, wxLIST_AUTOSIZE);

    // Remove a barra de rolagem horizontal
    SetScrollbar(wxHORIZONTAL, 0, 0, 0);

    SetItemCount(200);
}

wxString ProgramTable::OnGetItemText(long item, long col) const {
    wxString buffer;
    switch (col) {
        case 0: buffer.Printf(" "); break;
        case 1: buffer.Printf("%ld", item); break;
        case 2: buffer.Printf("%d", (Byte) (0xFF & item)); break;
        case 3: buffer.Printf(" MOV +(R7) R1"); break;
    }
    return buffer;
}

void ProgramTable::SetItem(long item, long col, Byte value) {
    // data[item] = value;
}

void ProgramTable::ResizeCols() {
    double q = (static_cast<double>(GetSize().GetWidth()) - 20.0) / 4;
    SetColumnWidth(0, 20);
    SetColumnWidth(3, std::ceil(q));
    SetColumnWidth(3, std::ceil(q));
    SetColumnWidth(3, std::ceil(2 * q));
}
