#include <iostream>

using namespace std;

//ANDREJ STOMNAROSKI INKI938

void changeString(string* str, char c1, char c2, char c3, char c4) {
    (*str)[0] = c1;
    (*str)[1] = c2;
    (*str)[2] = c3;
    (*str)[3] = c4;
}


void printString(string str) {
    cout << str << endl;
}

int main() {

    string ime = "Andrej";
    string prezime = "Stomnaroski";


    changeString(&ime ,'$', '^', '&','%');


    changeString(&prezime, '^', '%', '&', '$');

    printString(ime);
    printString(prezime);

    return 0;
}
