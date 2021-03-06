// Popup menu using callbacks -erco
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu.H>
#include <Fl_Input.H>
#include <stdio.h>
// Callback invoked when menu item selected
void handle_menu(Fl_Widget *w, void *v) {
    if(!w || !v) return;
    // switch((int)v) {
    //     case 1: fl_choice("Thing 1 happened", "OK", NULL, NULL); break;
    //     case 2: fl_choice("Thing 2 happened", "OK", NULL, NULL); break;
    //     case 3: fl_choice("Thing 3 happened", "OK", NULL, NULL); break;
    // }
}
// Callback invoked when button pushed
void push_cb(Fl_Widget *w, void*) {
    Fl_Menu_Item rclick_menu[] = {
        { "Do Thing 1",  0, handle_menu, (void*)1 },
        { "Do Thing 2",  0, handle_menu, (void*)2 },
        { "Do Thing 3",  0, handle_menu, (void*)3 },
        { 0 }
    };
    const Fl_Menu_Item *m = rclick_menu->popup(Fl::event_x(), Fl::event_y(), 0, 0, 0);
    if ( m ) m->do_callback(w, m->user_data());
    return;
}
int main() {
    Fl_Window win(800,600,"Simple Popup Menu (using callbacks)");
    //Fl_Button butt(10,10,120,25,"Push For Menu");
    //butt.callback(push_cb);
    win.show();
    return(Fl::run());
}
