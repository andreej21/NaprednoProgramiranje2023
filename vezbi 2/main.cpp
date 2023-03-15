#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
using namespace std;


//ANDREJ STOMNAROSKI INKI938

const int DECK_SIZE = 54;
const int SUIT_SIZE = 15;

string suits[4] = {"Hearts","Diamonds","Clubs","Spades"};
string ranks[SUIT_SIZE] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King","Joker A","Joker B"};

void shuffleDeck(string deck[],int Size)
{
    for(int i=0;i<Size;i++)
    {
        int j = rand()%Size;
        string temp = deck[i];
        deck[i] = deck[j];
        deck[j]=temp;
    }
}


int main()
{
    bool isVisitedA = true;
    bool isVisitedB=true;;
    string deck[DECK_SIZE];
    int index = 0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<SUIT_SIZE;j++)
        {
            if(ranks[j] == "Joker A" && !isVisitedA)
                continue;
            else if(ranks[j] == "Joker B" && !isVisitedB)
                continue;
            else if(ranks[j] == "Joker A" && isVisitedA)
            {
                deck[index] = ranks[j];
                index++;
                isVisitedA=false;
            }
            else if(ranks[j] == "Joker B" && isVisitedB)
            {
                deck[index] = ranks[j];
                index++;
                isVisitedB=false;
            }
            else{
                deck[index]=ranks[j] + " of " + suits[i];
                index++;
            }
        }
    }
    srand(time(NULL));
    shuffleDeck(deck,DECK_SIZE);

    for(int i=0;i<DECK_SIZE;i++)
    {
        cout<<deck[i]<<endl;
    }

    return 0;
}
