#include "main_frame.h"

//#include "tool_bar.h"
#include "register_panel.h"
#include "wx/wfstream.h"

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title,
    const wxPoint &pos, const wxSize &size)
    : wxFrame(parent, id, title, pos, size,
          wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION) {

    bzero(static_cast<void *>(memory), MEM_SIZE);

    program_side_panel = new SidePanel<ProgramTable *>(
        this, wxID_ANY, wxT("Programa"), wxDefaultPosition, wxSize(380, 500));

    data_side_panel = new SidePanel<DataTable *>(
        this, wxID_ANY, wxT("Dados"), wxDefaultPosition, wxSize(160, 500));

    side_panels.push_back(program_side_panel);
    side_panels.push_back(data_side_panel);

    ProgramTable *program_table =
        new ProgramTable(program_side_panel, wxID_ANY);
    program_table->SetData(memory, MEM_SIZE);
    program_side_panel->SetTable(program_table);

    DataTable *data_table = new DataTable(data_side_panel, wxID_ANY);
    data_table->SetData(memory, MEM_SIZE);
    data_side_panel->SetTable(data_table);

    wxMenu *menu_file = new wxMenu();
    menu_file->Append(
        ID_OpenFile, "Abrir...\tCtrl-A", "Abre um arquivo de memória");
    menu_file->AppendSeparator();
    menu_file->Append(wxID_EXIT);

    wxMenuBar *menu_bar = new wxMenuBar();
    menu_bar->Append(menu_file, "Arquivo");

    SetMenuBar(menu_bar);
    DoLayout();
    Layout();
    Center();
    UpdateSidePanelsPositions();
}


void MainFrame::DoLayout() {
    RegisterPanel *r0 = new RegisterPanel(this, wxID_ANY);
    Word random = rand() % 0xFFFF;
    r0->SetValue(0xffaa);
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(r0, 1, wxEXPAND, 0);

    program_side_panel->DoLayout();
    data_side_panel->DoLayout();
    program_side_panel->Show();
    data_side_panel->Show();
}

void MainFrame::UpdateSidePanelsPositions() {
    int gap = 10;
    wxPoint pos = GetPosition();
    program_side_panel->SetPosition(
        wxPoint(pos.x - program_side_panel->GetSize().GetWidth() - gap, pos.y));
    data_side_panel->SetPosition(
        wxPoint(pos.x + this->GetSize().GetWidth() + gap, pos.y));
}

void MainFrame::UpdateTables() {
    program_side_panel->GetTable()->Refresh();
    data_side_panel->GetTable()->Refresh();
}

// Eventos

void MainFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}


void MainFrame::OnOpenFile(wxCommandEvent &WXUNUSED(event)) {
    // TODO: Testar se o conteúdo atual foi modificado.
    // Caso tenha sido, avisa antes de abrir novo arquivo.

    wxFileDialog dialog(this, wxFileSelectorPromptStr, wxEmptyString,
        wxEmptyString, "Arquivos de memória (*.mem)|*.mem",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (dialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    wxFileInputStream input_stream(dialog.GetPath());

    if (!input_stream.IsOk()) {
        wxLogError("Não foi possível abrir o arquivo '%s'", dialog.GetPath());
        return;
    }

    input_stream.ReadAll(static_cast<void *>(memory), MEM_SIZE);
    UpdateTables();
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
