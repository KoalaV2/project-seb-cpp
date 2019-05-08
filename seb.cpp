#include <ctime>
#include <iostream>
int main() {
    std::string name;
    std::string use;
    std::cout << "Hello user! What's your name? \n :";
    std::cin >> name;
    std::cout << "Welcome " << name << "! What do you want to do today? \n :";
    std::cin >> use;
    if ( name == "Theo" ) {
        if ( use == "open_calculator") {
            float first_number;
            float second_number;
            char calc;
            std::cout << "Please enter your first number! \n :";
            std::cin >> first_number;
            std::cout << "Please enter your second number! \n :";
            std::cin >> second_number;
            std::cout << "Please enter how you want to calculate it! \n :";
            std::cin >> calc;
            std::cout << "\n";
            switch(calc) {
            case '+':
                std::cout << '=' << first_number + second_number << "\n\n";
                break;
            case '-':
                std::cout << '=' << first_number - second_number << "\n\n";
                break;
            case '*':
                std::cout << '=' << first_number * second_number << "\n\n";
                break;
            case '/':
                std::cout << '=' << first_number / second_number << "\n\n";
                break;
            default:
                std::cout << "Error, wrong input!";
            }

        }
        else if ( use == "ssh_info" ) {
            system("/bin/bash -c ./ssh.sh");
        }
        else if ( use == "time" ) {
		time_t tt;
		struct tm * ti;
		time(&tt);
		ti = localtime(&tt);
		std::cout << "The current time is :" << asctime(ti);
        }
        else {
            std::cout << "Acces denied.";
        }
    }
}
