#include<bits/stdc++.h>
using namespace std;

/*
    Andrej Stomnaroski INKI938

    Odd-Even Sort algoritmot raboti slicno na Bubble sortot no razlikata e sto
    sortiranjeto e podeleno vo dve fazi.
    Prvata faza e sortiranje na elementite koi se naogjaat na neparni indeksi
    ,a vtorata faza e sortiranje na elementite koi se naogjaat na parni indeksi.
    Sortiranjeto raboti taka sto dokolku elementot na momentalnata lokacija(indeks) e
    pogolem od sledniot element (indeks+1) togas nivnite mesta se zamenuvaat.
    Se dodeka nizata ne e sortirana ovoj algoritam se povtoruva.
    Otkako ke se sortira nizata so pomosnata funkcija printArray ja pecatime nizata.

*/
void oddEvenSort(int arr[], int n)
{
    bool isSorted = false;

    while (!isSorted)
    {
        isSorted = true;
        for (int i=1; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
             {
                swap(arr[i], arr[i+1]);
                isSorted = false;
              }
        }


        for (int i=0; i<=n-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }

    return;
}


void printArray(int arr[], int n)
{
   for (int i=0; i < n; i++)
       cout << arr[i] << " "; // -9 2 10 34
   cout << "\n";
}

int main()
{
    int arr[] = {34, 2, 10, -9};
    int n = sizeof(arr)/sizeof(arr[0]);

    oddEvenSort(arr, n);
    printArray(arr, n); // -9 2 10 34

    return (0);
}
