#include <iostream> #include <iomanip>

using namespace std; class SRTF {
 
public:
int *arrival_time; int *burst_time;
int *burst_time_original; int *waiting_time;
int *completion_time; int *turnaround_time; int n;

SRTF(int n) { arrival_time = new int[n]; burst_time = new int[n];
burst_time_original = new int[n]; waiting_time = new int[n]; completion_time = new int[n]; turnaround_time = new int[n];

this->n = n;

for(int i = 0; i< n; i++) {
cout << "Enter arrival time of process " << i << ": "; cin >> arrival_time[i];
cout << "Enter burst time of process " << i << ": "; cin >> burst_time[i];
burst_time_original[i] = burst_time[i];
}
}



void calculate() { int time = 0;
int completed_processes = 0;

while(1) {
int min_process_idx = -1;
int min_burst_time = INT_MAX; for(int i = 0; i<n; i++) {
if(arrival_time[i] <= time && burst_time[i] < min_burst_time && burst_time[i] != 0) { min_process_idx = i;
min_burst_time = burst_time[i];
}
}

// Breaking condition if(completed_processes == n){ break;
 
}

// Execute min burst time process for 1 second time++;
if(min_burst_time != 0){ burst_time[min_process_idx]--;


if(burst_time[min_process_idx] == 0){ completion_time[min_process_idx] = time;
turnaround_time[min_process_idx] = time - arrival_time[min_process_idx]; waiting_time[min_process_idx] = turnaround_time[min_process_idx] - burst_time_original[min_process_idx];
completed_processes++;
}
}

}
}

void print() {
cout << "hello" << '\n';
cout<< setw(5) << "AT" << setw(5) << "BT" << setw(5) << "CT" << setw(5) << "TAT" << setw(5) << "WT" << '\n';
for(int i = 0; i<n; i++) {
cout<< setw(5) << arrival_time[i] << setw(5) << burst_time_original[i] << setw(5) << completion_time[i]<< setw(5) << turnaround_time[i] << setw(5) << waiting_time[i]; cout << '\n';
}
}
};

int main() { int n;
cout << "Enter the number of processses: "; cin >> n;

// int a[n] = {0,1,2,4};
// int b[n] = {5,3,4,1};

SRTF s(n);
s.calculate(); s.print();
return 0;
}
