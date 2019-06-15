#include <ctime>
#include <iostream>
#include <string>
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
    festival_say_text("Hello user! What's your name? \n :");
    std::cin >> name;
    std::cout << "Welcome " << name;
    while(1){
        if ( name == "Theo" ) {
            std::cout << ", What do you want to do today? \n :";
            name.append(", What do you want to do today?");
            festival_say_text(name.c_str());
            std::cin.ignore();
            std::getline(std::cin, use);
            if ( use == "open calculator") {
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
            else if ( use == "ssh info" ) {
                system("/bin/bash -c ./ssh.sh");
            }
            else if ( use == "time info" ) {
                time_t tt;
                struct tm * ti;
                time(&tt);
                ti = localtime(&tt);
                std::cout << "The current time is :" << asctime(ti);
            }
            else if ( use == "tts" ) {
                std::string stuff;
                festival_say_text("What do you want me to say?");
                std::cout << "What do you want me to say?" << std::endl;
                std::cin.ignore();
                std::getline(std::cin,stuff);
                std::cout << stuff;
                festival_say_text(stuff.c_str());
            }
            else if ( use == "update") {
                festival_say_text("Updating the system now!");
                system("yay -Syu --sudoloop");
            }
            else if ( use == "weather" ) {
                system("curl -s wttr.in?format='%C:+%t'");
            }
            else {
                festival_say_text("Error, the command which is inputted has not been added yet!");
                std::cout << "ERROR, the command which is inputted has not been added yet.";
            }
        }
        else if ( name != "Theo") {
            festival_say_text("Access denied, user is not authorized");
            std::cout << "Access denied. User is not authorized!";
        }
                else {
            festival_say_text("ERROR, something went wrong!");
            std::cout << "ERROR, something went wrong!";
                }
    }
}