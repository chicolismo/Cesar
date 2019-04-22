#ifndef __REGISTER_PANEL_H__
#define __REGISTER_PANEL_H__

#include "common.h"
#include <wx/brush.h>

class RegisterPanel : public wxWindow {

private:
    bool show_decimal; // Se deve exibir base 10 ou base 16;
    Word value; // O valor (de 16 bits) a ser exibido no display
    wxBitmap display_images[16];
    wxBitmap display_null;

    wxBrush *background_brush;

    //int digit_width;
    //int digit_height;

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
