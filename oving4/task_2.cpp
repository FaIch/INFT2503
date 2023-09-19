#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box;
    Gtk::Entry entry1;
    Gtk::Entry entry2;
    Gtk::Button button;
    Gtk::Label label;
    Gtk::Label firstName;
    Gtk::Label lastName;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        button.set_label("Click here");
        firstName.set_text("First name:");
        lastName.set_text("Last name:");
        
        box.pack_start(firstName);
        box.pack_start(entry1);  // Add the widget entry to box
        box.pack_start(lastName);
        box.pack_start(entry2);  // Add the widget entry to box
        box.pack_start(button); // Add the widget button to box
        box.pack_start(label);  // Add the widget label to box

        add(box);   // Add vbox to window
        show_all(); // Show all widgets

        button.set_sensitive(false);

        entry1.signal_changed().connect([this]() {
            buttonState();
        });

        entry2.signal_changed().connect([this] () {
            buttonState();
        });

        button.signal_clicked().connect([this]() {
            label.set_text("Button clicked");
        });
    }

    void buttonState() {
        bool entriesFilled = !firstName.get_text().empty() && !lastName.get_text().empty();
        button.set_sensitive(entriesFilled);
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}


