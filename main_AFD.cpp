#include <iostream>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
#include <string>
using namespace std;
ifstream fin("AFD.in");
ofstream fout("AFD.out");
int main()
{
    int n;
    fin>>n;
    //char alf[1000];
    long int m[30][30][30];
    int i,j,k,l;

    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            for(k=0; k<=n; k++)
                m[i][j][k]=-1;
    int nr;
    char ch;

    // n - indicele maxim de stari ale automatului ie n+1 stari

    string alf,aux;
    int fi[n+1];
    for(i=0; i<=n; i++)
        fin>>fi[i];
    getline(fin,aux);// iau enter-ul din buffer
    getline(fin,alf);
    //cout<<alf;
    //fin>>alf;
    // k - nr de tranzitii
    fin>>k;
    int start,stop;
    for(i=0; i<k; i++)
    {
        int ok=0;
        fin>>ch;
        fin>>start>>stop;
        if(start>n || start<0 || stop>n|| stop<0)
        {
            fout<<"EROARE - stare invalida";
            return 0;
        }
        for(l=0; l<=n&&ok==0; l++)
            if(m[start][stop][l]==-1)
            {
                m[start][stop][l]=ch-48;
                ok=1;
            }

    }

    fin>>nr;
    string cuv[nr];
    string a;
    for(i=0; i<nr; i++)
    {
        fin>>a;
        cuv[i]=a;
    }
    int conditie;
    for(j=0; j<nr; j++)
    {
        string cuvact=cuv[j];
        int index=0;
        for(i=0; i<cuvact.size(); i++)
        {
            char l=cuvact[i];
            conditie=0;

            for(int a=0; a<=n&&conditie==0; a++)
                for(int b=0; b<=n; b++)
                {
                    if(l-m[index][a][b]==48)
                    {
                        conditie=1;
                        index=a;
                        break;}

            }
            if(conditie==0)
            {
                fout<<"NU"<<endl;
                break;
            }
        }
        if(conditie==1&& fi[index]==1)
            {fout<<"DA"<<endl; }
        else
            if(conditie==1)
            fout<<"NU"<<endl;

    }
    fin.close();
    fout.close();
    return 0;
}
