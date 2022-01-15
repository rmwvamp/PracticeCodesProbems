#include <bits/stdc++.h>
using namespace std;

int main()
{
    tuple<int, int, int, int> sid;
    sid = make_tuple(1, 20, 2, 5);

    cout << get<0>(sid) << " " << get<1>(sid);

    return 0;
}

k sub set array.. 
exchange arguments...

1 2 3 5 6 7 .... n

e1 e2 e3 ei.. ej.. en


e1 e2 e3 ej.. ei.. en

r>= l
speed l >= speed r


k=1 

metric= speed*efficiency
k=3

metric= speed*efficiency

 7   2 3 1   k=3
 1 2 3 4 5

_ _ _ _ _ _ _ _