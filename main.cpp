#include "controller.hpp"
int main(int, char **)
{
    string input;
    getline(cin, input);
    Controller::processUserInput(input);
}
