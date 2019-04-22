#ifndef __MAIN_FRAME_H__
#define __MAIN_FRAME_H__

#include "common.h"
#include "data_table.h"
#include "program_table.h"
#include "side_panel.h"

#include <vector>

class MainFrame : public wxFrame {

private:
    SidePanel<ProgramTable *> *program_side_panel;
    SidePanel<DataTable *> *data_side_panel;
    //std::vector<wxDialog *> side_panels;
    std::vector<wxFrame *> side_panels;
    Byte memory[MEM_SIZE];

public:
    MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos = wxDefaultPosition,
              const wxSize &size = wxDefaultSize);
    void DoLayout();
    void UpdateSidePanelsPositions();
    void UpdateTables();

    // Eventos
    void OnExit(wxCommandEvent &event);
    void OnOpenFile(wxCommandEvent &event);
    void OnMove(wxMoveEvent &event);
    void OnSize(wxSizeEvent &event);
    void OnIconize(wxIconizeEvent &event);

    wxDECLARE_EVENT_TABLE();
};

#endif // __MAIN_FRAME_H__
