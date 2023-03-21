#include <iostream>

using namespace std;

//ANDREJ STOMNAROSKI INKI938

int main()
{
    char pesna[] = "Blinding Lights";

    char celaSodrzina[] = "Blinding Lights - The Weeknd";
    char *p = celaSodrzina;

    cout <<"***********************************************"<<endl;
    cout <<"Pesna : "<<pesna<<endl;
    cout <<"Cela sodrzina : "<<celaSodrzina<<endl;

    cout <<"Pocetna pozicija: "<<*p<<endl;
    cout <<"Pocetna pozicija adresa: " <<&p<<endl;
    cout <<"\n***********************************************"<<endl;
    int brPomestuvanja = 0;
    for(int i=0;i<sizeof(celaSodrzina)/sizeof(celaSodrzina[0]);i++)
    {
        if(*p=='-')
        {
            *p=celaSodrzina[i+1];
            break;
        }
        *p = celaSodrzina[i];
        brPomestuvanja++;
    }
    string izveduvac=" ";
    for(int i=brPomestuvanja;i<sizeof(celaSodrzina)/sizeof(celaSodrzina[0]);i++)
    {
        izveduvac+=celaSodrzina[i];
    }

    cout <<"\Premestuvanje do izveduvac - p+"<<brPomestuvanja<<endl;
    cout << "Sodrzina po premesten pocetok: "<<izveduvac<<endl;
    cout<<" Adresa od koja pocnuva segashna sodrzina "<<&p<<endl;

    return 0;
}
