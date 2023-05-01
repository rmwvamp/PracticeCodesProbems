#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> make_array_non_decreasing(vector<int>& A) {
    int N = A.size();
    int M = 0;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > A[i+1]) {
            A[i] ^= A[i+1];
            A[i+1] ^= A[i];
            A[i] ^= A[i+1];
            M++;
        }
    }

    if (is_sorted(A.begin(), A.end())) {
        return vector<pair<int, int>>();
    }

    int i = 0;
    while (i < N - 1 && A[i] <= A[i+1]) {
        i++;
    }

    int j = N - 1;
    while (j > 0 && A[j] >= A[j-1]) {
        j--;
    }

    vector<pair<int, int>> operations;
    for (int k = i; k < j; k++) {
        if (A[k] > A[k+1]) {
            operations.push_back(make_pair(k+1, k));
            A[k] ^= A[k+1];
            A[k+1] ^= A[k];
            A[k] ^= A[k+1];
        }
    }
    operations.push_back(make_pair(i+1, j));

    return operations;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        vector<pair<int, int>> operations = make_array_non_decreasing(A);

        cout << operations.size() << endl;
        for (int i = 0; i < operations.size(); i++) {
            cout << operations[i].first << " " << operations[i].second << endl;
        }
    }

    return 0;
}
