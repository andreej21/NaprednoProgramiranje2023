#include <bits/stdc++.h>

using namespace std;

double sobiranje (int a , int b)
{
    return a+b;
}

double odzemanje (int a , int b)
{
    return a-b;
}

double delenje (int a, int b)
{
    return a/b;
}

double stepenuvanje(int a, int b)
{
    return pow(a,b);
}

void calculate(int a, int b, int (*operation)(int, int)) {
    cout << "Result: " << (double)operation(a, b) <<endl;
}

int main()
{
    int a = (int)'S';
    int b = (int)'A';

    double (*op)(int, int) = &sobiranje;

    void* void_op = reinterpret_cast<void*>(op);

    calculate(a, b, reinterpret_cast<int (*)(int, int)>(op));

    op = &odzemanje;
    calculate(a, b, reinterpret_cast<int (*)(int, int)>(op));

    op = &delenje;
    calculate(a, b, reinterpret_cast<int (*)(int, int)>(op));

    op = &stepenuvanje;
    calculate(a, b, reinterpret_cast<int (*)(int, int)>(op));



    return 0;
}
