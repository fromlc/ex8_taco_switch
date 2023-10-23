//------------------------------------------------------------------------------
// ex8_taco_switch.cpp
//
// Practice char input menu structure using switch statement
// Uses ancillary source code files
//------------------------------------------------------------------------------
#include <iomanip>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
const string MENU_STR = "F)ish, S)alsa, P)ico de gallo, L)ettuce, A)vocado Q)uit: ";
const double PRICE_PER_FILLING = 0.75;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
enum UserOptionStatus {
    OPTION_VALID,
    OPTION_INVALID,
    OPTION_QUIT,
};

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void startup();

// app loop
int process_fillings();

// menu management
char get_menu_option();
UserOptionStatus choose_fillings();

// output management
void display_error();
void display_taco_price(int);

// command handlers
UserOptionStatus handle_fish_filling();
UserOptionStatus handle_salsa_filling();
UserOptionStatus handle_pico_filling();
UserOptionStatus handle_lettuce_filling();
UserOptionStatus handle_avocado_filling();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    startup();
    display_taco_price(process_fillings());
}

//------------------------------------------------------------------------------
// display app banner and instructions
//------------------------------------------------------------------------------
void startup() {

    cout << "\nProf. Linda C's Taco Shop";
    cout << "\n\nChoose your taco fillings!\n";
}

//------------------------------------------------------------------------------
// app loop
// -gets and counts selected fillings
// -returns number of valid fillings selected
//------------------------------------------------------------------------------
int process_fillings() {

    int num_fillings = 0;

    UserOptionStatus option_status{ };
    while (true) {                  // terminates on user quit

        switch (choose_fillings()) {
        case OPTION_QUIT:
            return num_fillings;    // terminates on user quit
        case OPTION_VALID:
            num_fillings++;
            break;
        default:
            display_error();
        }
    }
}

//------------------------------------------------------------------------------
// menu management
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// display taco menu options
//------------------------------------------------------------------------------
char get_menu_option() {

    char topping;
    cout << '\n' << MENU_STR;
    cin >> topping;
    return toupper(topping);
}

//------------------------------------------------------------------------------
// - processes selected menu option
// - returns type of user response as enum: valid, invalid, or quit
//------------------------------------------------------------------------------
UserOptionStatus choose_fillings() {

    char option = get_menu_option();

    switch (option) {
    case 'F':
        return handle_fish_filling();
    case 'S':
        return handle_salsa_filling();
    case 'P':
        return handle_pico_filling();
    case 'L':
        return handle_lettuce_filling();
    case 'A':
        return handle_avocado_filling();
    case 'Q':
        return OPTION_QUIT;
    default:
        return OPTION_INVALID;
    }
}

//------------------------------------------------------------------------------
// output management
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// displays taco price based on number of fillings selected
//------------------------------------------------------------------------------
void display_taco_price(int filling_count) {

    if (filling_count > 0) {

        double price = filling_count * PRICE_PER_FILLING;
        cout << "\nThat will be "
            << setprecision(2) << fixed
            << '$' << price
            << " please.\n";
        cout << "Sounds delicious! Enjoy your taco.\n\n";
    }
    else {
        cout << "Goodbye!\n\n";
    }
}

//------------------------------------------------------------------------------
// menu option not offered
//------------------------------------------------------------------------------
void display_error() {

    cerr << "Sorry, that filling is not available.\n";
}

//------------------------------------------------------------------------------
// command handlers
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// add fish to taco order
//------------------------------------------------------------------------------
UserOptionStatus handle_fish_filling() {

    cout << "Adding freshly caught mahi-mahi\n";
    return OPTION_VALID;
}

//------------------------------------------------------------------------------
// add salsa to taco order
//------------------------------------------------------------------------------
UserOptionStatus handle_salsa_filling() {

    cout << "Adding HOT homemade salsa\n";
    return OPTION_VALID;
}

//------------------------------------------------------------------------------
// add pico de gallo to taco order
//------------------------------------------------------------------------------
UserOptionStatus handle_pico_filling() {

    cout << "Adding diced tomato, onion, and chopped cilantro\n";
    return OPTION_VALID;
}

//------------------------------------------------------------------------------
// add shredded lettuce to taco order
//------------------------------------------------------------------------------
UserOptionStatus handle_lettuce_filling() {

    cout << "Adding crisp, shredded iceberg lettuce\n";
    return OPTION_VALID;
}

//------------------------------------------------------------------------------
// add sliced avocado to taco order
//------------------------------------------------------------------------------
UserOptionStatus handle_avocado_filling() {

    cout << "Adding creamy avocado slices\n";
    return OPTION_VALID;
}
