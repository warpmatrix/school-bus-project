#include <iostream>
#include <windows.h>
#include "init.cpp"
#include "passenger.cpp"
#include "controller.cpp"

int main(int argc, char const *argv[]) {
    BusStation busStation[STATIONNUMBER];
    SchoolBus schoolBus[BUSNUMBER];
    init(busStation, schoolBus);
    // std::cout << "Produced by nonoli and warpMatrix" << '\n';
    // Sleep(3000);
    // system("cls");
    while(1) {
        std::cout << "Hello, Please Choose your user mode?(Just enter number is OK)" << '\n';
        std::cout << "1.Passenger mode  2.Controller mode" << '\n';
        char input = legalInput(1, 2);
        if(input == '1')
          queryMode(busStation, schoolBus);
        else {
            while (1) {
                if(signIn() ) {
                    std::cout << "Signing in..." << '\n';
                    std::cout << '\n';
                    controllerMode(busStation, schoolBus);
                }
                else {
                    std::cout << '\n' << "Sorry to say that your account or password is wrong." << '\n';
                    std::cout << "You will return to the main menu if you enter 'Esc'..." << '\n';
                    std::cout << "Or enter any other key to return to the sign in menu" << '\n';
                    char input = getch();
                    system("cls");
                    if(input == 27) break;
                }
            }

        }
    }
    return 0;
}
