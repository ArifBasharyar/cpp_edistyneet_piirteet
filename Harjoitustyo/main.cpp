#include "fncs.h"

int main(int argc, char **argv) {
    // Muuttujat
    string arg1{}, arg2{}, arg3{};
    size_t position{};
    print_opt opt{};

    // Ei aloitus argumentteja
    if (argc == 1) {
        // Kysyt‰‰n hakuehtoja
        std::cout << "Give a string from which to search for: ";
        std::getline(std::cin, arg1);
        std::cout << "Give search string: ";
        std::getline(std::cin, arg2);

        // Tulostetaan vastaus
        if (search_within_string(&arg1, &arg2, &position)) {
            std::cout << "\"" << arg2 << "\" found in \"" << arg1 << "\" in position " << position << "\n";
        } else {
            std::cout << "\"" << arg2 << "\" NOT found in \"" << arg1 << "\"\n";
        }
        return 0;
    }

    try {
        // M‰‰ritet‰‰n argumentit
        if (argc == 4) {
            if (argv[1][0] == '-' && argv[1][1] == 'o') {
                // -olori
                arg3 = argv[1];
                // following
                arg2 = argv[2];
                // man_grep_plain_ASCII.txt
                arg1 = argv[3];
                option_switch(&arg3, &opt);
            }
            // Jos asetus on annettu ep‰m‰‰r‰isesti
            else throw 1;
        }

        // M‰‰ritet‰‰n argumentit
        if (argc == 3) {
            // following
            arg2 = argv[1];
            // man_grep_plain_ASCII.txt
            arg1 = argv[2];
        }

        // Jos argumentteja on v‰‰r‰ m‰‰r‰
        if (argc != 3 && argc != 4) throw 2;

        // Yritet‰‰n etsi‰ tiedostoa ja luetaan se
        read_file(&arg1, &arg2, &opt);

    } catch (const int &error) {
        std::cerr << "An exception occurred. Exception Nr. " << error;
        if (error == -1) 
            std::cerr << "\nCould not find out the size of file \"" << arg1 << "\"\n";
        if (error == 1) 
            std::cerr << "\nInvalid option argument. Option: " << argv[1] << "\n";
        if (error == 2) 
            std::cerr << "\nInvalid amount of arguments. Amount: " << argc << "\n";
        return error;
    }

    return 0;
}
