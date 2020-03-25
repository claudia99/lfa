#include <iostream>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
ifstream fin("AFN.in");
ofstream fout("AFN.out");
int main()
{
    int n;
    fin>>n;
    string alf,aux;
    long int m[30][30][30];
    int i,j,k,l;

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
    //for(i=0; i<=n; i++)
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

    int ok;
    for(i=0; i<nr; i++)
    {
        queue <int> c;
        string act=cuv[i];
        c.push(0);
        j=0;
        c.push(-1);
        while(true)
        {
           // cout<<"suint aici";
            if(j==act.size())
            {
               // cout<<"--------IES-----------";
                break;
            }
            int b=c.front();
            c.pop();
            //cout<<"b este "<<b<<endl;
            int a;
            if(b!=-1)
            {
                //continue;
               // ok=0;
                //cout<<"J este "<<j<<" iar b este "<<b<<endl;
                //cout<<"ok inainte de actiune "<<ok<<endl;
                for(l=0; l<=n; l++)
                    for(a=0; a<=n; a++)
                    {
                        //cout<<"***"<<"j "<<j<<" act[j] "<<act[j]<<" dif "<<act[j]-m[b][l][a]<<" l ";
                        //cout<<l<<" "<<endl;
                        if(act[j]-m[b][l][a]==48)
                        {
                            //cout<<" act[j] "<<act[j]<<" dif "<<act[j]-m[b][l][a]<<" l ";
                            //cout<<l<<" "<<endl;
                            ok=1;
                            c.push(l);

                        }
                    }
               // cout<<endl<<"ok dupa actiune "<<ok<<endl;
            }
                        else
            {
                if(ok!=1)
                   {
//cout<<"???"<<endl;
                    break; }
                else
                {   //cout<<"!!!"<<endl;
                    c.push(-1);
                    ok=0;
                    j++;
                }

            }




        //cout<<"j este "<<j<<endl;
    } // end while

//    if(j<act.size())
//    {
//        //cout<<"sunt aiici si am iesit prost";
//    }
//    cout<<"ok este "<<ok<<endl;
    // if(ok==1)
    //{
    int gasit=0;
    while(c.empty()==0)
    {
        int f=c.front();

        if(fi[f]==1)
            gasit=1;
       // cout<<"VARFUL "<<f<<endl;
        c.pop();

    }
    if(gasit==1)
    {
        //cout<<"DA"<<endl;
        fout<<"DA"<<endl;
    }
    else
    {
        //cout<<"NU"<<endl;
        fout<<"NU"<<endl;
    }
    //}
    // else {cout<<"NU1"<<endl; fout<<"NU1"<<endl;}
}

fin.close();
fout.close();
return 0;
}
