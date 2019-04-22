#include "program_table.h"

ProgramTable::ProgramTable(wxWindow *parent, wxWindowID id)
    : wxListCtrl(parent, id, wxDefaultPosition, wxSize(380, 500),
          wxLC_REPORT | wxLC_VIRTUAL | wxLC_HRULES | wxLC_VRULES) {

    show_decimal = false;

#ifdef _WIN32
    long list_style = wxLIST_FORMAT_LEFT;
    int font_size = 10;
#else
    long list_style = wxLIST_FORMAT_RIGHT;
    int font_size = 12;
#endif

    SetBackgroundColour(wxColour("#ffffff"));
    SetFont(wxFont(font_size, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_NORMAL, 0, wxT("")));

    InsertColumn(0, wxT("PC"), list_style, wxLIST_AUTOSIZE);
    InsertColumn(1, wxT("Endereço"), list_style, wxLIST_AUTOSIZE);
    InsertColumn(2, wxT("Valor"), list_style, wxLIST_AUTOSIZE);
    InsertColumn(3, wxT("Mnemônico"), wxLIST_FORMAT_LEFT, wxLIST_AUTOSIZE);

    // Remove a barra de rolagem horizontal
    SetScrollbar(wxHORIZONTAL, 0, 0, 0, true);
    SetItemCount(0);
    ResizeCols();
}

wxString ProgramTable::OnGetItemText(long item, long col) const {
    wxString buffer;
    switch (col) {
    case 0:
        buffer.Printf(" ");
        break;
    case 1:
        buffer.Printf("%ld", item);
        break;
    case 2:
        if (show_decimal) {
            buffer.Printf("%d", 0xFF & data[item]);
        }
        else {
            buffer.Printf("%02x", 0xFF & data[item]);
        }
        break;
    case 3:
        buffer.Printf(" Não implementado");
        break;
    }
    return buffer;
}

Byte *ProgramTable::GetData() {
    return data;
}

void ProgramTable::SetData(Byte *data, size_t size) {
    this->data = data;
    this->size = size;
    SetItemCount(size);
    RefreshItems(0, size - 1);
}

void ProgramTable::SetItem(long item, long col, Byte value) {
    data[item] = value;
    RefreshItem(item);
}

void ProgramTable::Refresh() {
    RefreshItems(0, size - 1);
}

void ProgramTable::ResizeCols() {
    int scrollbar_width = 10;
    double q = (static_cast<double>(GetSize().GetWidth()) - 20.0) / 4 -
               scrollbar_width;
    SetColumnWidth(0, 20);
    SetColumnWidth(3, std::ceil(q));
    SetColumnWidth(3, std::ceil(q));
    SetColumnWidth(3, std::ceil(2 * q));

    SetScrollbar(wxHORIZONTAL, 0, 0, 0, true);
}
