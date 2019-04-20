#include "main_frame.h"

//============================================================================
// NOTE: Não remover
//============================================================================
template class SidePanel<ProgramTable *>;
template class SidePanel<DataTable *>;

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(parent, id, title, pos, size, wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX) {

    program_side_panel = new SidePanel<ProgramTable *>(this, wxID_ANY, wxT("Programa"));
    data_side_panel    = new SidePanel<DataTable *>(this, wxID_ANY, wxT("Dados"));

    side_panels.push_back(program_side_panel);
    side_panels.push_back(data_side_panel);

    ProgramTable *program_table = new ProgramTable(program_side_panel, wxID_ANY);
    program_side_panel->SetTable(program_table);

    DataTable *data_table = new DataTable(data_side_panel, wxID_ANY);
    data_side_panel->SetTable(data_table);

    wxMenu *menu_file = new wxMenu();
    menu_file->Append(ID_OpenFile, "Abrir...\tCtrl-A", "Abre um arquivo de memória");
    menu_file->AppendSeparator();
    menu_file->Append(wxID_EXIT);

    wxMenuBar *menu_bar = new wxMenuBar();
    menu_bar->Append(menu_file, "Arquivo");

    SetMenuBar(menu_bar);
    DoLayout();
    SetProperties();
    Layout();
    Center();
    UpdateSidePanelsPositions();
}

void MainFrame::SetProperties() {
    program_side_panel->SetProperties();
    data_side_panel->SetProperties();
    program_side_panel->Show();
    data_side_panel->Show();
}

void MainFrame::DoLayout() {
    program_side_panel->DoLayout();
    data_side_panel->DoLayout();
}

void MainFrame::UpdateSidePanelsPositions() {
    int gap     = 20;
    wxPoint pos = GetPosition();
    program_side_panel->SetPosition(wxPoint(pos.x - program_side_panel->GetSize().GetWidth() - gap, pos.y));
    data_side_panel->SetPosition(wxPoint(pos.x + this->GetSize().GetWidth() + gap, pos.y));
}

// Eventos

void MainFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void MainFrame::OnOpenFile(wxCommandEvent &event) {
    wxMessageBox("Fuck you!!");
}

void MainFrame::OnMove(wxMoveEvent &event) {
    UpdateSidePanelsPositions();
}

void MainFrame::OnSize(wxSizeEvent &event) {
    UpdateSidePanelsPositions();
}


void MainFrame::OnIconize(wxIconizeEvent &event) {
    bool show = !IsIconized();
    for (auto &panel : side_panels) {
        panel->Show(show);
    }
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_OpenFile, MainFrame::OnOpenFile)
    EVT_MENU(wxID_EXIT, MainFrame::OnExit)
    EVT_MOVE(MainFrame::OnMove)
    EVT_MOVING(MainFrame::OnMove)
    EVT_SIZE(MainFrame::OnSize)
    EVT_ICONIZE(MainFrame::OnIconize)
wxEND_EVENT_TABLE()


