#include <bits/stdc++.h>
using namespace std;

void index(int *a, int n, int m){
    if (n == -1) return;

    if (a[n] == m) cout << n;
    else index(a, n-1, m);
}

int main() {
    int n, m;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    index(a, n, m);
    return 0;
}