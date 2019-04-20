#ifndef __SIDE_PANEL_H__
#define __SIDE_PANEL_H__

#include <wx/numformatter.h>
#include "common.h"
#include "data_table.h"
#include "program_table.h"

template <class Table>
class SidePanel : public wxFrame {
    // TODO: Quando mudar o tamanho tem que perguntar o tamanho preferencial da tabela
    // e mudar de acordo. (Voltar para o tamanho "padrão")

private:
    Table table;
    long table_id;
    wxStaticText *address_label;
    wxTextCtrl *value_control;

public:
    SidePanel(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos = wxDefaultPosition,
              const wxSize &size = wxDefaultSize);
    Table GetTable() const;
    void SetTable(Table table);
    void DoLayout();

    // Events
    void OnSize(wxSizeEvent &event);
    void OnItemSelected(wxListEvent &event);
    void OnTextEnter(wxCommandEvent &event);

    wxDECLARE_EVENT_TABLE();
};

template <class Table>
SidePanel<Table>::SidePanel(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                            const wxSize &size)
    : wxFrame(parent, id, title, pos, size, wxCAPTION | wxRESIZE_BORDER | wxFRAME_TOOL_WINDOW) {

    address_label = new wxStaticText(this, wxID_ANY, wxT("0"));
    value_control = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
}


template <class Table>
void SidePanel<Table>::DoLayout() {

    wxBoxSizer *sizer       = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *input_sizer = new wxBoxSizer(wxHORIZONTAL);

    sizer->Add(table, 1, wxEXPAND | wxALL, BORDER_SIZE);

    input_sizer->Add(address_label, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, BORDER_SIZE);
    input_sizer->Add(value_control, 0, wxALIGN_CENTER_VERTICAL, 0);

    sizer->Add(input_sizer, 0, wxALIGN_RIGHT | wxALL, BORDER_SIZE);
    SetSizer(sizer);
    sizer->Fit(this);
    SetClientSize(table->GetSize());
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

//----------------------------------------------------------------------------
// Eventos
//----------------------------------------------------------------------------
template <class Table>
void SidePanel<Table>::OnSize(wxSizeEvent &event) {
    table->ResizeCols();
    event.Skip();
}

template <class Table>
void SidePanel<Table>::OnItemSelected(wxListEvent &event) {
    wxListItem item = event.GetItem();
    wxString address = wxNumberFormatter::ToString(item.GetId());
    wxString value = item.GetText();
    address_label->SetLabelText(address);
    value_control->SetValue(value);
}

template <class Table>
void SidePanel<Table>::OnTextEnter(wxCommandEvent &event) {
    wxMessageBox(wxT("Enter!!"), wxT("Texto"));
}


wxBEGIN_EVENT_TABLE_TEMPLATE1(SidePanel, wxPanel, Table)
    EVT_SIZE(SidePanel<Table>::OnSize)
    EVT_LIST_ITEM_SELECTED(wxID_ANY, SidePanel<Table>::OnItemSelected)
    EVT_TEXT_ENTER(wxID_ANY, SidePanel<Table>::OnTextEnter)
wxEND_EVENT_TABLE()

#endif // __SIDE_PANEL_H__
