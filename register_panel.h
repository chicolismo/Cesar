#ifndef __REGISTER_PANEL_H__
#define __REGISTER_PANEL_H__

#include "common.h"

class RegisterPanel : public wxPanel {

private:
    bool show_decimal;

    Word value; // O valor (de 16 bits) a ser exibido no display

    wxBitmap display_images[16];

public:
    RegisterPanel(wxWindow *parent, wxWindowID id);

    void SetValue(Word value);
    void Render(wxDC &dc);
    void PaintNow();

    // Eventos
    void OnPaint(wxPaintEvent &e);

    wxDECLARE_EVENT_TABLE();
};

#endif // __REGISTER_PANEL_H__
