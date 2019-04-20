#include "program_table.h"

ProgramTable::ProgramTable(wxWindow *parent, wxWindowID id)
    : wxListCtrl(parent, id, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_VIRTUAL | wxLC_HRULES | wxLC_VRULES) {

    InsertColumn(0, wxT("Endereço"), wxLIST_FORMAT_RIGHT, 100);
    InsertColumn(1, wxT("Valor"), wxLIST_FORMAT_RIGHT, 100);
    InsertColumn(2, wxT("Mnemônico"), wxLIST_FORMAT_RIGHT, 200);
    SetItemCount(0);
}


wxString ProgramTable::OnGetItemText(long item, long col) const {
    return wxString("Sendo Implementado");
}

void ProgramTable::SetItem(long item, long col, Byte value) {
    // data[item] = value;
}
