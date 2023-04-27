#include <bits/stdc++.h>

using namespace std;


class igrac
{
public:
    string ime;
    int poeni =0;
};



void tabelaPrint(char tabela[3][3])
{
    cout <<"      |        |         "<<endl;
    cout <<"   "<<tabela[0][0]<<"  |   "<<tabela[0][1]<<"    |   "<<tabela[0][2]<<endl;
    cout <<"      |        |         "<<endl;
    cout<<"-------------------------"<<endl;
    cout <<"      |        |         "<<endl;
    cout <<"   "<<tabela[1][0]<<"  |   "<<tabela[1][1]<<"    |   "<<tabela[1][2]<<endl;
    cout <<"      |        |         "<<endl;
    cout<<"-------------------------"<<endl;
    cout <<"      |        |         "<<endl;
    cout <<"   "<<tabela[2][0]<<"  |   "<<tabela[2][1]<<"    |   "<<tabela[2][2]<<endl;
    cout <<"      |        |         "<<endl;
}

bool checkXWin(char tabela[3][3])
{
    //Proveruvame prvo po redovi

    if((tabela[0][0] == tabela[0][1] && tabela[0][1] == tabela[0][2]) && tabela[0][0]=='X')
        return true;
    if((tabela[1][0] == tabela[1][1] && tabela[1][1] == tabela[1][2]) && tabela[1][0]=='X')
        return true;
    if((tabela[2][0] == tabela[2][1] && tabela[2][1] == tabela[2][2])&& tabela[2][0]=='X')
        return true;

    //Proveruvame po koloni

    if((tabela[0][0] == tabela[1][0] && tabela[1][0] == tabela[2][0]) && tabela[0][0]=='X')
        return true;
    if((tabela[0][1] == tabela[1][1] && tabela[1][1] == tabela[2][1]) && tabela[0][1]=='X')
        return true;
    if((tabela[0][2] == tabela[1][2] && tabela[1][2] == tabela[2][2]) && tabela[0][2]=='X')
        return true;

    //Proveruvame po dijagonali
    if((tabela[0][0] == tabela[1][1] && tabela[1][1] == tabela[2][2]) && tabela[0][0]=='X')
        return true;
    if((tabela[2][0] == tabela[1][1] && tabela[1][1] == tabela[0][2])&& tabela[0][2]=='X')
        return true;

    return false;

}

bool checkOWin(char tabela[3][3])
{
    //Proveruvame prvo po redovi

    if(tabela[0][0] == tabela[0][1] && tabela[0][0] == tabela[0][2] && tabela[0][0]=='O')
        return true;
    if(tabela[1][0] == tabela[1][1] && tabela[1][0] == tabela[1][2] && tabela[1][0]=='O')
        return true;
    if(tabela[2][0] == tabela[2][1] && tabela[2][0] == tabela[2][2] && tabela[2][0]=='O')
        return true;

    //Proveruvame po koloni

    if(tabela[0][0] == tabela[1][0] && tabela[0][0] == tabela[2][0] && tabela[0][0]=='O')
        return true;
    if(tabela[0][1] == tabela[1][1] && tabela[0][1] == tabela[2][1] && tabela[0][1]=='O')
        return true;
    if(tabela[0][2] == tabela[1][2] && tabela[0][2] == tabela[2][2] && tabela[0][2]=='O')
        return true;

    //Proveruvame po dijagonali
    if(tabela[0][0] == tabela[1][1] && tabela[0][0] == tabela[2][2] && tabela[0][0]=='O')
        return true;
    if(tabela[0][2] == tabela[1][1] && tabela[0][2] == tabela[2][0] && tabela[0][2]=='O')
        return true;

    return false;

}

bool checkIfDraw(char  tabela[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(tabela[i][j] == 'X' || tabela[i][j] == 'O')
            {
                continue;
            }
            else return false;
        }
    }
    if(!checkXWin(tabela) || !checkOWin(tabela))
        return true;
    return false;
}

bool checkIfFreeAndReplace(char tabela[3][3],char pole,char znak)
{

    if(pole<='0' || pole>'9')
        return false;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(tabela[i][j]==pole)
            {
                tabela[i][j]=znak;
                return true;
            }

        }
    }
    return false;
}

void setTabela(char tabela[3][3])
{
    int br = 49;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            tabela[i][j] =br;
            br++;
        }
    }
}


void printScoreBoard(igrac igrac1, igrac igrac2)
{
    cout <<"-----------------------------"<<endl;
    cout <<"         SCOREBOARD           "<<endl;
    cout <<"-----------------------------"<<endl;
    cout <<igrac1.ime <<"   "<<igrac1.poeni <<"  |  "<<igrac2.ime <<"   "<<igrac2.poeni<<endl;
}

int main()
{
    char tabela[3][3];
    setTabela(tabela);
    cout <<"Zdravo , ova e igra X/O !"<<endl;
    cout<<"\n\n";
    igrac igrac1;
    igrac igrac2;

    cout <<"Igrac 1 vnesi ime: " <<endl;
    cin>>igrac1.ime;
    cout <<"Igrac 2 vnesi ime: "<<endl;
    cin>>igrac2.ime;


    cout <<"Prviot igrac igra so X a vtoriot so O"<<endl;
    int brojac = 1;
    while(true)
    {
        tabelaPrint(tabela);
        char igracZnak;
        if(brojac%2!=0)
            igracZnak='X';
        else igracZnak='O';
        input:
        cout <<"Igrac "<<igracZnak<<" ve molam izberete pole"<<endl;

        char pole;
        cin>>pole;

        if(!checkIfFreeAndReplace(tabela,pole,igracZnak))
        {
            cout <<"Izbravte zafateno pole , obidete se povtorno!"<<endl;
            goto input;
        }

        if(checkXWin(tabela))
        {
            system("cls");
            cout<<"Igracot " <<igrac1.ime << " Pobedi!"<<endl;
            igrac1.poeni++;
            brojac++;
            setTabela(tabela);
            printScoreBoard(igrac1,igrac2);
            cout <<"Dali sakate da prodolzite ? YES/NO"<<endl;
            string odluka;
            cin>>odluka;
            if(odluka=="YES")
                continue;
            else
            {
                cout<<"Dogledanje!"<<endl;
                break;
            }
        }
        if(checkOWin(tabela))
        {
            system("cls");
            cout<<"Igracot " <<igrac2.ime << " Pobedi!"<<endl;
            igrac2.poeni++;
            brojac++;
            setTabela(tabela);
            printScoreBoard(igrac1,igrac2);
            cout <<"Dali sakate da prodolzite ? YES/NO"<<endl;
            string odluka;
            cin>>odluka;
            if(odluka=="YES")
                continue;
            else
            {
                cout<<"Dogledanje!"<<endl;
                break;
            }

        }
        if(checkIfDraw(tabela))
        {
            system("cls");
            cout<<"NERESENO!!!"<<endl;
            setTabela(tabela);
            printScoreBoard(igrac1,igrac2);
            cout <<"Dali sakate da prodolzite ? YES/NO"<<endl;
            string odluka;
            cin>>odluka;
            if(odluka=="YES")
                continue;
            else
            {
                cout<<"Dogledanje!"<<endl;
                break;
            }
        }
        system("cls");
        brojac++;


    }

    return 0;
}
