#include <iostream>
#include <cstring>
#include <string>
#include <typeinfo>
using namespace std;

/* Prototypes */
void toUpperbl(char*, int);
void toLowerbl(char*, int);
char* toArray(const std::string &input);

/*------------------------------------------------------------------*/
int main(int argc, char const *argv[]) {
    std::string word = "DropTheBeat";
    int n = word.length();
    char newWord[n + 1];
    strcpy(newWord, word.c_str());

    cout << "Basiccase: " << newWord << endl;
    toUpperbl(newWord, n);
    cout << "Uppercase: " << newWord << endl;
    toLowerbl(newWord, n);
    cout << "Lowercase: " << newWord << endl;

    cout << "Spacecase: ";
    for (int i = 0; i < n; i++) {
        cout << newWord[i] << ' ';
    }
    cout << endl;

    return 0;
}

/* Definitions */
void toUpperbl(char* str, int count) {
    for (int i = 0; i < count; i++) {
        str[i] -= 32 * (str[i] >= 'a' && str[i] <= 'z');
    }
}

void toLowerbl(char* str, int count) {
    for (int i = 0; i < count; i++) {
        str[i] += 32 * (str[i] >= 'A' && str[i] <= 'Z');
    }
}
