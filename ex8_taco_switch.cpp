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
// local function prototypes
//------------------------------------------------------------------------------
void startup();
char get_menu_option();
void display_fish_filling();
void display_salsa_filling();
void display_pico_filling();
void display_lettuce_filling();
void display_avocado_filling();
void display_error();
void display_taco_price(int);

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
int number_of_fillings = 0;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    startup();

    bool quit = false;
    while (!quit) {

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
            quit = true;
            break;
        default:
            display_error();
        }
    }

    display_taco_price(number_of_fillings);

    return 0;
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
// add fish to taco order
//------------------------------------------------------------------------------
void display_fish_filling() {

    number_of_fillings++;
    cout << "Adding freshly caught mahi-mahi\n";
}

//------------------------------------------------------------------------------
// add salsa to taco order
//------------------------------------------------------------------------------
void display_salsa_filling() {

    number_of_fillings++;
    cout << "Adding HOT homemade salsa\n";
}

//------------------------------------------------------------------------------
// add pico de gallo to taco order
//------------------------------------------------------------------------------
void display_pico_filling() {

    number_of_fillings++;
    cout << "Adding diced tomato, onion, and chopped cilantro\n";
}

//------------------------------------------------------------------------------
// add shredded lettuce to taco order
//------------------------------------------------------------------------------
void display_lettuce_filling() {

    number_of_fillings++;
    cout << "Adding crisp, shredded iceberg lettuce\n";
}

//------------------------------------------------------------------------------
// add sliced avocado to taco order
//------------------------------------------------------------------------------
void display_avocado_filling() {

    number_of_fillings++;
    cout << "Adding creamy avocado slices\n";
}

//------------------------------------------------------------------------------
// menu option not offered
//------------------------------------------------------------------------------
void display_error() {

    number_of_fillings++;
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
