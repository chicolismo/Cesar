#ifndef __SIDE_PANEL_H__
#define __SIDE_PANEL_H__

#include "common.h"
#include "program_table.h"
#include "data_table.h"

template <class Table>
class SidePanel : public wxFrame {
    // TODO: Incluir tabela de eventos.

private:
    Table table;
    wxStaticText *address_label;
    wxTextCtrl *value_control;

public:
    SidePanel(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos = wxDefaultPosition,
              const wxSize &size = wxDefaultSize);
    Table GetTable() const;
    void SetTable(Table table);
    void SetProperties();
    void DoLayout();
};


template <class Table>
SidePanel<Table>::SidePanel(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(parent, id, title, pos, size, wxCAPTION | wxRESIZE_BORDER | wxFRAME_TOOL_WINDOW) {

    address_label = new wxStaticText(this, wxID_ANY, wxT("0"));
    value_control = new wxTextCtrl(this, wxID_ANY);
}

template <class Table>
void SidePanel<Table>::SetProperties() {}

template <class Table>
void SidePanel<Table>::DoLayout() {

    wxBoxSizer *sizer       = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *input_sizer = new wxBoxSizer(wxHORIZONTAL);

    sizer->Add(table, 1, wxEXPAND | wxALL, BORDER_SIZE);

    input_sizer->Add(address_label, 0, wxALIGN_CENTER | wxALIGN_RIGHT | wxRIGHT, BORDER_SIZE);
    input_sizer->Add(value_control, 0, wxALIGN_CENTER | wxALIGN_RIGHT, 0);

    sizer->Add(input_sizer, 0, wxALIGN_CENTER | wxALIGN_RIGHT | wxALL, BORDER_SIZE);
    SetSizer(sizer);
    sizer->Fit(this);
    Layout();
}

template <class Table>
void SidePanel<Table>::SetTable(Table table) {
    this->table = table;
}

template <class Table>
Table SidePanel<Table>::GetTable() const {
    return table;
}
#endif // __SIDE_PANEL_H__
