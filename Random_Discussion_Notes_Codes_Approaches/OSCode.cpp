#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Fcfs
{
private:
    string *pn;
    int *rq;
    int *bt;
    int n;
    int *ct;

public:
    Fcfs();
    void input();
    void sort();
    void calculate_ct();
    void calculate_T();
    void print();
};

Fcfs::Fcfs()
{
    cout << "Enter the number of processes :";
    cin >> n;

    rq = new int[n];
    bt = new int[n];
    pn = new string[n];
    ct = new int[n];
}

void Fcfs::input()
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n Enter the name of the " << (i + 1) << "th process : ";
        cin >> pn[i];
        cout << "\n Enter the arrival time of " << pn[i] << " : ";
        cin >> rq[i];
        cout << "\n Enter the burst time of " << pn[i] << " : ";
        cin >> bt[i];
    }
}

void Fcfs::sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (rq[j] < rq[i])
            {
                swap(rq[i], rq[j]);
                swap(pn[i], pn[j]);
                swap(bt[i], bt[j]);
            }
        }
    }
}

void Fcfs::calculate_ct()
{
    for (int i = 0; i < n; i++)
    {
        ct[i] = rq[0];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            ct[i] += bt[j];
        }
    }
}

void Fcfs::calculate_T()
{
    int TAT = 0, WT = 0;
    for (int i = 0; i < n; i++)
    {
        TAT += ct[i] - rq[i];
        WT += ct[i] - rq[i] - bt[i];
        cout << "Turn Around Time for " << pn[i] << " : " << ct[i] - rq[i] << endl;
        cout << "Waiting Time for " << pn[i] << " : " << ct[i] - rq[i] - bt[i] << endl;
    }
    cout << endl;
    float awt = (float)WT / n;
    float att = (float)TAT / n;
    cout << "Average Turn Around Time = " << att << endl;
    cout << "Average Waiting Time = " << awt << endl;
}

int main()
{
    Fcfs f;
    f.input();
    f.sort();
    cout << endl;
    f.calculate_ct();
    cout << endl;
    f.calculate_T();
    return 0;
}
