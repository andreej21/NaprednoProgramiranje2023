#include <iostream>
#include <time.h>

using namespace std;

//ANDREJ STOMNAROSKI INKI938

int main() {

    //Funkcijata difftime() od bibliotekata <time.h> ima dva parametri beginning i end i so neze se presmetuva razlika vo sekundi na dadenite parametri
    double seconds = difftime(213123,1000);
    cout<<seconds;
}
