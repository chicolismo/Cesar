#include "tool_bar.h"
//#include "open.xpm"
//#include "save.xpm"

ToolBar::ToolBar(wxWindow *parent, wxWindowID id)
    : wxToolBar(parent, id, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL) {

    //wxBitmap button_open(open_xpm);
    //wxBitmap button_save(save_xpm);

    //AddTool(wxID_OPEN, button_open, wxT("Abrir"));
    //AddTool(wxID_SAVE, button_save, wxT("Salvar"));
    //AddSeparator();
    //Realize();
}
