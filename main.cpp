#ifdef WX_PRECOMP
#include <wx/wxprec.h>
#else
#include <wx/wx.h>
#include <wx/image.h>
#endif

#include "main_frame.h"

class Application : public wxApp {
public:
    bool OnInit() override;
};


bool Application::OnInit() {
    wxInitAllImageHandlers();
    MainFrame *frame = new MainFrame(nullptr, wxID_ANY, wxT("Cesar"));
    SetTopWindow(frame);
    frame->Show(true);
    return true;
}

IMPLEMENT_APP(Application)
