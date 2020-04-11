#include <iostream>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
ifstream fin("AFNlambda.in"); /// am pus * in loc de lambda
ofstream fout("AFNlambda.out");
int n;
string alf,aux;
long int m[30][30][30];
int i,j,k,l;
void afisqueue(queue<int> c)
{
    queue<int> aux=c;
    while(aux.empty()==0)
    {cout<<aux.front()<<" ";
    aux.pop();}
}

int exists(int val, queue<int> c)
{
    queue<int> aux=c;
    while(aux.empty()==0)
    {
        if(aux.front()==val)
            return 1;
        aux.pop();
    }
    return 0;
}
void inchidere(int stare, queue<int> &stari)
{
    if(exists(stare,stari)==0)
        stari.push(stare);
    queue <int> aux;
    //for(i=0; i<=n; i++)
    for(j=0; j<=n; j++)
        for(l=0; l<=n; l++)
            if(m[stare][j][l]==-6)
                if(exists(j,stari)==0)
                {
                    stari.push(j);
                    aux.push(j);
                }
    //cout<<"aux:";
    //afisqueue(aux);
    while(aux.empty()==0)
    {
        int ll=aux.front();
        aux.pop();
        for(j=0; j<=n; j++)
            for(l=0; l<=n; l++)
                if(m[ll][j][l]==-6)
                {
                    if(exists(j,stari)==0)
                    {
                        stari.push(j);
                        aux.push(j);
                    }
                    //else
                        //aux.push(l);
                }
    }
}
void caut(char s, queue <int> &c)
{
    queue <int>aux,au=c;
    for(i=0; i<=n; i++)
        while(au.empty()==0)
        {
            int k=au.front();
            au.pop();
            for(j=0; j<=n; j++)
                for(l=0; l<=n; l++)
                    if(s-m[k][j][l]==48)
                        if(exists(j,aux)==0)
                            aux.push(j);
        }
    c=aux;

}


void inchidere_stari(queue<int>&c)
{
    queue <int> aux=c,nou,aux1;
    while(aux.empty()==0)
    {
        int q=aux.front();
       // cout<<"fac inchiderea lui "<<q<<endl;
        aux.pop();
        inchidere(q,nou);
        // nou.push(q);

        //cout<<"in functie"<<endl;
        //afisqueue(nou);
    }
    c=nou;
}

int main()
{
    fin>>n;
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            for(k=0; k<=n; k++)
                m[i][j][k]=-1;
    int nr;
    char ch;

    // n - indicele maxim de stari ale automatului ie n+1 stari


    int fi[n+1];
    for(i=0; i<=n; i++)
        fin>>fi[i];
    getline(fin,aux);
    getline(fin,alf);
    // k - nr de tranzitii

    fin>>k;
    int start,stop;
//    for(i=0; i<=n; i++)
//    {
//        for(j=0; j<=n; j++)
//        {
//
//            for(l=0; l<=n; l++)
//                cout<<m[i][j][l]<<" ";
//            cout<<endl;
//        }
//        cout<<endl;
//    }

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
//    for(i=0; i<=n; i++)
//    {
//        for(j=0; j<=n; j++)
//        {
//
//            for(l=0; l<=n; l++)
//                cout<<m[i][j][l]<<" ";
//            cout<<endl;
//        }
//        cout<<endl;
//    }
    fin>>nr;
    string cuv[nr];
    string a;
    for(i=0; i<nr; i++)
    {
        fin>>a;
        cuv[i]=a;
    }
    for(int z=0; z<nr; z++)
    {
        queue <int> stari;
        inchidere(0,stari);
        string act=cuv[z];

        for(int y=0; y<act.size(); y++)
        {
            //cout<<endl;
            //cout<<endl<<"Initial: ";
            //afisqueue(stari);
            // cout<<endl;
            //cout<<endl<<"litera ";
            //cout<<act[y];
            caut(act[y],stari);
            //cout<<endl<<"Dupa cautare: ";
           // afisqueue(stari);
            //cout<<endl<<"Dupa inchidere: ";
            inchidere_stari(stari);
            //cout<<endl;
            //afisqueue(stari);
        }

        //while
        int ok=0;
        ///verific daca e vreo stare finala
        while(stari.empty()==0&&ok==0)
        {
            int h=stari.front();
            stari.pop();
            if(fi[h]==1)
                ok=1;

        }
        if(ok==0)
            { //cout<<"NUU";
             fout<<"0"<<endl;}
        else
            {//cout<<"DAA";
             fout<<"1"<<endl;}
    }
    fin.close();
    fout.close();
    return 0;
}
