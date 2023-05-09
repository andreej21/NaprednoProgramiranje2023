#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{
    string ime ="INKI938.Andrej.Stomnaroski";
    string mail;
    cin>>mail;
    cout<<mail<<endl;
    string zaedno = ime+" "+mail;
    vector<int> zv;
    for(int i=0;i<zaedno.length();i++)
    {
        zv.push_back(zaedno[i]);
    }
    for(int i=0;i<zv.size();i++)
    {
        cout<<zv[i]<<" ";
    }

    sort(zv.begin(),zv.end());
    zv.push_back(18);
    zv.push_back(4);
    zv.push_back(3);

    for(int i=0;i<zv.size();i++)
    {
        cout<<zv[i]<<" ";
    }

    ofstream file;

    file.open("datoteka.txt");
    for(int i=0;i<zv.size();i++)
    {
        file<<zv[i]<<" ";
    }
    file.close();
    return 0;
}
