#ifdef WX_PRECOMP
#include <wx/wxprec.h>
#else
#include <wx/image.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/wx.h>
#endif

#include <vector>

//============================================================================
// Constantes
//============================================================================

const int MEM_SIZE = 1 << 16;

//============================================================================
// Tipos
//============================================================================

using Byte = uint8_t;

//============================================================================
// IDs
//============================================================================

enum {
    ID_OpenFile = 1,

    ID_DataTable,
    ID_ProgramTable,

    ID_DataTextControl,
    ID_ProgramTextControl,
};

//============================================================================
// Protótipos
//============================================================================

class Application : public wxApp {
public:
    bool OnInit() override;
};


class DataTable : public wxListCtrl {
    std::vector<Byte> data;

public:
    DataTable(wxWindow *parent, wxWindowID id);
    virtual wxString OnGetItemText(long item, long col) const;
    void SetItem(long item, long col, Byte value);
};


class ProgramTable : public wxListCtrl {
    std::vector<Byte> data;

public:
    ProgramTable(wxWindow *parent, wxWindowID id);
    virtual wxString OnGetItemText(long item, long col) const;
    void SetItem(long item, long col, Byte value);
};


class MainFrame : public wxFrame {
    wxPanel *main_panel;
    wxPanel *program_panel;
    wxPanel *registers_panel;
    wxPanel *data_panel;
    wxPanel *display_panel;

    ProgramTable *program_table;
    wxStaticText *program_address_label;
    wxTextCtrl *program_text_control;

    DataTable *data_table;
    wxStaticText *data_address_label;
    wxTextCtrl *data_text_control;

public:
    MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos = wxDefaultPosition,
              const wxSize &size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE);

    // void InitMenu();
    void SetProperties();
    void DoLayout();

    // Eventos
    void OnExit(wxCommandEvent &event);
    void OnOpenFile(wxCommandEvent &event);

    wxDECLARE_EVENT_TABLE();
};


//============================================================================
// Implementação
//============================================================================

//----------------------------------------------------------------------------
// MainFrame
//----------------------------------------------------------------------------
MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                     long style)
    : wxFrame(parent, id, title, pos, size, style) {

    main_panel      = new wxPanel(this, wxID_ANY);
    program_panel   = new wxPanel(main_panel, wxID_ANY);
    registers_panel = new wxPanel(main_panel, wxID_ANY);
    data_panel      = new wxPanel(main_panel, wxID_ANY);
    display_panel   = new wxPanel(this, wxID_ANY);

    data_table = new DataTable(data_panel, ID_DataTable);
    // data_address_label = new wxStaticText(data_panel, wxID_ANY, wxT("0"));
    // data_text_control  = new wxTextCtrl(data_panel, ID_DataTextControl);

    program_table = new ProgramTable(program_panel, ID_ProgramTable);
    // program_address_label = new wxStaticText(program_panel, wxID_ANY,
    // wxT("0")); program_text_control = new wxTextCtrl(program_panel,
    // ID_ProgramTextControl);


    wxMenu *menu_file = new wxMenu();
    menu_file->Append(ID_OpenFile, "Abrir...\tCtrl-A", "Abre um arquivo de memória");
    menu_file->AppendSeparator();
    menu_file->Append(wxID_EXIT);

    wxMenuBar *menu_bar = new wxMenuBar();
    menu_bar->Append(menu_file, "Arquivo");

    SetMenuBar(menu_bar);
    SetProperties();
    DoLayout();
    Layout();
    Fit();
}

void MainFrame::SetProperties() {
    registers_panel->SetMinSize(wxSize(300, 300));
    program_panel->SetBackgroundColour(wxColour(255, 0, 0));

    registers_panel->SetBackgroundColour(wxColour(128, 128, 0));

    data_panel->SetBackgroundColour(wxColour(128, 0, 200));

    display_panel->SetMinSize(wxSize(300, 80));
    display_panel->SetBackgroundColour(wxColour(0, 128, 255));
}

void MainFrame::DoLayout() {
    int border_size = 8;

    wxBoxSizer *main_sizer = new wxBoxSizer(wxHORIZONTAL);
    main_panel->SetSizer(main_sizer);

    main_sizer->Add(program_panel, 0, wxEXPAND | wxALL, border_size);
    main_sizer->Add(registers_panel, 0, wxTOP | wxBOTTOM, border_size);
    main_sizer->Add(data_panel, 0, wxEXPAND | wxALL, border_size);

    wxBoxSizer *program_sizer = new wxBoxSizer(wxVERTICAL);
    program_panel->SetSizer(program_sizer);
    //wxStaticText *program_title = new wxStaticText(program_panel, wxID_ANY, wxT("Programa"));
    //program_sizer->Add(program_title, 0, wxALIGN_CENTER | wxALL, border_size);
    program_sizer->Add(program_table, 1, wxEXPAND, 0);

    wxBoxSizer *data_sizer = new wxBoxSizer(wxVERTICAL);
    data_panel->SetSizer(data_sizer);
    //wxStaticText *data_title = new wxStaticText(data_panel, wxID_ANY, wxT("Programa"));
    //data_sizer->Add(data_title, 0, wxALIGN_CENTER | wxALL, border_size);
    data_sizer->Add(data_table, 1, wxEXPAND, 0);

    wxBoxSizer *window_sizer = new wxBoxSizer(wxVERTICAL);
    window_sizer->Add(main_panel, 1, wxEXPAND, 0);
    window_sizer->Add(display_panel, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, border_size);

    //wxFont title_font(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT(""));
    //program_title->SetFont(title_font);
    //data_title->SetFont(title_font);

    SetSizer(window_sizer);
}

// Eventos

void MainFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void MainFrame::OnOpenFile(wxCommandEvent &event) {
    wxMessageBox("Fuck you!!");
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_OpenFile, MainFrame::OnOpenFile)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
wxEND_EVENT_TABLE()

//----------------------------------------------------------------------------
// DataTable
//----------------------------------------------------------------------------
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


//----------------------------------------------------------------------------
// ProgramTable
//----------------------------------------------------------------------------
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


//----------------------------------------------------------------------------
// Application
//----------------------------------------------------------------------------
bool Application::OnInit() {
    wxInitAllImageHandlers();
    MainFrame *frame = new MainFrame(nullptr, wxID_ANY, wxT("Cesar"));
    SetTopWindow(frame);
    frame->Show(true);
    return true;
}

IMPLEMENT_APP(Application)
