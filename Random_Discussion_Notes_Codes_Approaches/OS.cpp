#include <iostream> #include <iomanip> #include <queue> #include <algorithm>

using namespace std;

class Round_Robin
{
public:
    int *arrival_time;
    int *burst_time;
    int *burst_time_original;
    int *waiting_time;
    int *completion_time;
    int *turnaround_time;
    int n;
    int time_quantum;

    Round_Robin(int n, int time_quantum)
    {
        arrival_time = new int[n];
        burst_time = new int[n];
        burst_time_original = new int[n];
        waiting_time = new int[n];
        completion_time = new int[n];
        turnaround_time = new int[n];

        this->n = n;
        this->time_quantum = time_quantum;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter arrival time of process " << i << ": ";
            cin >> arrival_time[i];
            cout << "Enter burst time of process " << i << ": ";

            cin >> burst_time[i];
            burst_time_original[i] = burst_time[i];
        }
    }

    void calculate()
    {
        int time = 0;
        int completed = 0;
        int queued[n] = {false};

        queue<int> ready;

        while (completed != n)
        {
            for (int i = 0; i < n; i++)
            {
                if (arrival_time[i] <= time && !queued[i])
                {
                    ready.push(i);
                    queued[i] = true;
                }
            }

            if (ready.empty())
            {
                time++;
                continue;
            }

            int p = ready.front();

            ready.pop();
            if (burst_time[p] <= time_quantum)
            {
                time += burst_time[p];
                burst_time[p] = 0;

                completion_time[p] = time;
                turnaround_time[p] = time - arrival_time[p];
                waiting_time[p] = turnaround_time[p] - burst_time_original[p];
                completed++;
            }
            else
            {
                time += time_quantum;
                burst_time[p] -= time_quantum;
                ready.push(p);
            }
        }
    }

    void print()
    {
        cout << setw(5) << "AT" << setw(5) << "BT" << setw(5) << "CT" << setw(5) << "TAT"
             << setw(5) << "WT" << '\n';
        for (int i = 0; i < n; i++)
        {
            cout << setw(5) << arrival_time[i] << setw(5) << burst_time_original[i] << setw(5) << completion_time[i] << setw(5) << turnaround_time[i] << setw(5) << waiting_time[i];
            cout << '\n';
        }
    }
};

int main()
{
    int n;
    int tq;
    cout << "Enter the time quantum: ";
    cin >> tq;
    cout << "Enter the number of processses: ";
    cin >> n;

    Round_Robin r(n, tq);
    r.calculate();
    r.print();
    return 0;
}
