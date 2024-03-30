#include "controller.h"
int main(int, char**){
    string balls;
    getline(cin, balls);
    Controller::processUserInput(balls);
}
