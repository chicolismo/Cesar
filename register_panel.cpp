
#include "register_panel.h"

#include "assets/cesar_0.xpm"
#include "assets/cesar_1.xpm"
#include "assets/cesar_2.xpm"
#include "assets/cesar_3.xpm"
#include "assets/cesar_4.xpm"
#include "assets/cesar_5.xpm"
#include "assets/cesar_6.xpm"
#include "assets/cesar_7.xpm"
#include "assets/cesar_8.xpm"
#include "assets/cesar_9.xpm"
#include "assets/cesar_a.xpm"
#include "assets/cesar_b.xpm"
#include "assets/cesar_c.xpm"
#include "assets/cesar_d.xpm"
#include "assets/cesar_e.xpm"
#include "assets/cesar_f.xpm"
#include "assets/cesar_null.xpm"


// Painel é 73 x 23
// Cada número é 12 x 17
RegisterPanel::RegisterPanel(wxWindow *parent, wxWindowID id)
    : wxWindow(parent, id, wxDefaultPosition, wxSize(74, 23)) {

    value = 0;
    show_decimal = true;
    display_images[0x0] = wxBitmap(cesar_0_xpm);
    display_images[0x1] = wxBitmap(cesar_1_xpm);
    display_images[0x2] = wxBitmap(cesar_2_xpm);
    display_images[0x3] = wxBitmap(cesar_3_xpm);
    display_images[0x4] = wxBitmap(cesar_4_xpm);
    display_images[0x5] = wxBitmap(cesar_5_xpm);
    display_images[0x6] = wxBitmap(cesar_6_xpm);
    display_images[0x7] = wxBitmap(cesar_7_xpm);
    display_images[0x8] = wxBitmap(cesar_8_xpm);
    display_images[0x9] = wxBitmap(cesar_9_xpm);
    display_images[0xa] = wxBitmap(cesar_a_xpm);
    display_images[0xb] = wxBitmap(cesar_b_xpm);
    display_images[0xc] = wxBitmap(cesar_c_xpm);
    display_images[0xd] = wxBitmap(cesar_d_xpm);
    display_images[0xe] = wxBitmap(cesar_e_xpm);
    display_images[0xf] = wxBitmap(cesar_f_xpm);

    display_null = wxBitmap(cesar_null_xpm);

    background_brush = new wxBrush(wxColour(0, 0, 0));
}

void RegisterPanel::SetValue(Word value) {
    this->value = value;
}

void RegisterPanel::Render(wxDC &dc) {
    // Primeiro pintamos um retângulo preto!
    dc.SetBackground(*background_brush);
    dc.Clear();
    
    // Agora os dígitos
    int y = 3;
    int x = 59;
    int display_size = show_decimal ? 5 : 4;
    int base = show_decimal ? 10 : 16;

    int current_digit = 0;
    Word n = value;
    do {
        int digit = n % base;
        dc.DrawBitmap(display_images[digit], x, y, false);
        x -= 14;
        ++current_digit;
        n /= base;
    } while (n > 0);

    while (current_digit < display_size) {
        dc.DrawBitmap(display_null, x, y, false);
        x -= 14;
        ++current_digit;
    }
}

void RegisterPanel::PaintNow() {
    wxClientDC dc(this);
    Render(dc);
}

void RegisterPanel::OnPaint(wxPaintEvent &e) {
    wxPaintDC dc(this);
    Render(dc);
}

wxBEGIN_EVENT_TABLE(RegisterPanel, wxPanel)
    EVT_PAINT(RegisterPanel::OnPaint)
wxEND_EVENT_TABLE()
