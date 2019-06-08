#include <ctime>
#include <iostream>
#include <festival/festival.h>
int main() {
    EST_Wave wave;
    int heap_size = 210000;
    int load_init_files = 1;
    festival_initialize(load_init_files, heap_size);
    std::string name;
    std::string use;
    float result;

    std::cout << "Hello user! What's your name? \n :";
    festival_say_text("Hello user! What's your name?");
    std::cin >> name;
    std::cout << "Welcome " << name << "! What do you want to do today? \n :";
    festival_say_text("What do you want to do today?");
    std::cin >> use;
    if ( name == "Theo" ) {
        if ( use == "open_calculator") {
            float first_number;
            float second_number;
            char calc;
            std::cout << "Please enter your first number! \n :";
            festival_say_text("Please enter your first number");
            std::cin >> first_number;
            std::cout << "Please enter how you want to calculate it! \n :";
            festival_say_text("please enter how you want to calculate it");
            std::cin >> calc;
            std::cout << "Please enter your second number! \n :";
            festival_say_text("Please enter your second number");
            std::cin >> second_number;
            std::cout << "\n";
            switch(calc) {
            case '+':
                result = first_number + second_number;
                break;
            case '-':
                result = first_number - second_number;
                break;
            case '*':
                result = first_number * second_number;
                break;
            case '/':
                result = first_number / second_number;
                break;
            default:
                std::cout << "Error, wrong input!";
                festival_say_text("Error, wrong input!");
            }
            std::cout << '=' << result << "\n";

        }
        else if ( use == "ssh_info" ) {
            system("/bin/bash -c ./ssh.sh");
        }
        else if ( use == "time_info" ) {
            time_t tt;
            struct tm * ti;
            time(&tt);
            ti = localtime(&tt);
            std::cout << "The current time is :" << asctime(ti);
        }
        else if ( use == "tts" ) {
            festival_say_text("Hello world!"); // Eventually adding user input.
        }
        else {
            std::cout << "ERROR, the command which is inputted has not been added yet.";
        }
    }
    else if ( name != "Theo") {
        std::cout << "Access denied. User is not authorized!";
    }
    else {
        std::cout << "ERROR, something went wrong!";
    }
}