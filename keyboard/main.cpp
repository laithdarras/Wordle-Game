#include <iostream>
#include <vector>
#include <string>
#include "keyboard.h"
#define GREEN "\033[032m"
#define RESET "\033[0m"
#define GRAY "\033[090m"
#define YELLOW "\033[033m"

using namespace std;

int main(int argc, char* argv[]) {

    /*
        your code goes here
    */

    vector<int> index;
    vector<int> key;
    vector<int> current;

    while (true) {
        bool escape = true;
        while (escape) {
            current = update();
            if (current != key) {
                escape = false;
            }
        }

        for (int i = 0; i < key.size(); i++) {
            if (key[i] == GREEN) {
                index.push_back(i);
            }
        }
        system("clear");
        
        if (key[0] == "0") {
            index.clear();
            cout << "Please start the game." << endl;
        } else if (key[0] == "1") {
            cout << "Please be patient as the game is starting..." << endl;
        } else 
            displayKeyboard(key, index);
    }

    return 0;
}