#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
int main()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n), b(n);
    cin >> a >> b;
    int t[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = a[i] - b[i];
    }
    int k = d - c;
    ordered_set s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += s.order_of_key(t[i] + k + 1);
        s.insert(t[i]);
    }
    cout << cnt << endl;
    return 0;
}