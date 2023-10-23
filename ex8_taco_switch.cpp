//------------------------------------------------------------------------------
// ex8_taco_switch.cpp
//
// Practice char input menu structure using switch statement
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
char get_menu_option();
UserOptionStatus choose_fillings();
void display_fish_filling();
void display_salsa_filling();
void display_pico_filling();
void display_lettuce_filling();
void display_avocado_filling();
void display_error();
void display_taco_price(int);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    startup();

    int num_fillings = 0;

    UserOptionStatus response { };
    while ((response = choose_fillings()) != OPTION_QUIT) {
        
        num_fillings = (response == OPTION_VALID) ? num_fillings + 1 : num_fillings;
    }

    display_taco_price(num_fillings);
}


//------------------------------------------------------------------------------
// display app banner and instructions
//------------------------------------------------------------------------------
void startup() {

    cout << "\nProf. Linda C's Taco Shop";
    cout << "\n\nChoose your taco fillings!\n";
}

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
        display_fish_filling();
        break;
    case 'S':
        display_salsa_filling();
        break;
    case 'P':
        display_pico_filling();
        break;
    case 'L':
        display_lettuce_filling();
        break;
    case 'A':
        display_avocado_filling();
        break;
    case 'Q':
        return OPTION_QUIT;
    default:
        display_error();
        return OPTION_INVALID;
    }

    return OPTION_VALID;
}

//------------------------------------------------------------------------------
// add fish to taco order
//------------------------------------------------------------------------------
void display_fish_filling() {

    cout << "Adding freshly caught mahi-mahi\n";
}

//------------------------------------------------------------------------------
// add salsa to taco order
//------------------------------------------------------------------------------
void display_salsa_filling() {

    cout << "Adding HOT homemade salsa\n";
}

//------------------------------------------------------------------------------
// add pico de gallo to taco order
//------------------------------------------------------------------------------
void display_pico_filling() {

    cout << "Adding diced tomato, onion, and chopped cilantro\n";
}

//------------------------------------------------------------------------------
// add shredded lettuce to taco order
//------------------------------------------------------------------------------
void display_lettuce_filling() {

    cout << "Adding crisp, shredded iceberg lettuce\n";
}

//------------------------------------------------------------------------------
// add sliced avocado to taco order
//------------------------------------------------------------------------------
void display_avocado_filling() {

    cout << "Adding creamy avocado slices\n";
}

//------------------------------------------------------------------------------
// menu option not offered
//------------------------------------------------------------------------------
void display_error() {

    cerr << "Sorry, that filling is not available.\n";
}


//------------------------------------------------------------------------------
// cleanup tasks
//------------------------------------------------------------------------------
void display_taco_ready() {

    cout << "Sounds delicious! Enjoy your taco.\n";
}

//------------------------------------------------------------------------------
// displays taco price based on number of fillings selected
// #TODO use global instead of parameter, or make global local to main()
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
