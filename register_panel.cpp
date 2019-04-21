#include <chrono>
#include <thread>
#include <ctime>

#include "register_panel.h"

#include "assets/display-0.xpm"
#include "assets/display-1.xpm"
#include "assets/display-2.xpm"
#include "assets/display-3.xpm"
#include "assets/display-4.xpm"
#include "assets/display-5.xpm"
#include "assets/display-6.xpm"
#include "assets/display-7.xpm"
#include "assets/display-8.xpm"
#include "assets/display-9.xpm"
#include "assets/display-a.xpm"
#include "assets/display-b.xpm"
#include "assets/display-c.xpm"
#include "assets/display-d.xpm"
#include "assets/display-e.xpm"
#include "assets/display-f.xpm"


// Cada número é 36 x 56
// São 5 números por registrador quando exibindo em base 10.
// 5 * 36 + 2*borda = 5 * 36 * 2 * 8


RegisterPanel::RegisterPanel(wxWindow *parent, wxWindowID id)
    : wxPanel(parent, id, wxDefaultPosition, wxSize(5 * 36 + 2 * BORDER_SIZE, 150)) {

        value = 0;
        //show_decimal = true;
        show_decimal = false;

        display_images[0x0] = wxBitmap(display_0_xpm);
        display_images[0x1] = wxBitmap(display_1_xpm);
        display_images[0x2] = wxBitmap(display_2_xpm);
        display_images[0x3] = wxBitmap(display_3_xpm);
        display_images[0x4] = wxBitmap(display_4_xpm);
        display_images[0x5] = wxBitmap(display_5_xpm);
        display_images[0x6] = wxBitmap(display_6_xpm);
        display_images[0x7] = wxBitmap(display_7_xpm);
        display_images[0x8] = wxBitmap(display_8_xpm);
        display_images[0x9] = wxBitmap(display_9_xpm);
        display_images[0xa] = wxBitmap(display_a_xpm);
        display_images[0xb] = wxBitmap(display_b_xpm);
        display_images[0xc] = wxBitmap(display_c_xpm);
        display_images[0xd] = wxBitmap(display_d_xpm);
        display_images[0xe] = wxBitmap(display_e_xpm);
        display_images[0xf] = wxBitmap(display_f_xpm);
}

void RegisterPanel::SetValue(Word value) {
    this->value = value;
}

void RegisterPanel::Render(wxDC &dc) {
    Word n = value;
    int display_size = 5;
    int position = 0;
    if (show_decimal) {
        do {
            int digit = n % 10;
            dc.DrawBitmap(display_images[digit], (display_size - position - 1) * 36, 0, false);
            ++position;
            n /= 10;
        } while (n > 0);
    }
    else {
        //dc.DrawBitmap(display_images[0], position * 36, 0, false);
        //++position;
        do {
            int digit = n % 0x10;
            dc.DrawBitmap(display_images[digit], (display_size - position - 1) * 36, 0, false);
            ++position;
            n /= 0x10;
        } while (n > 0);
    }
    // TODO: Preencher os dígitos que faltarem.
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
