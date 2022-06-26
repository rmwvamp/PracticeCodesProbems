
#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>a,int maximum_pages,int students){
    int stno=1;
    long long pages=0;
    int n= a.size();
    for(int i=0;i<n;i++){
        if(pages+a[i]<=maximum_pages){
            pages+=a[i];
        }
        else{
            stno++;
            pages=a[i];
            if(stno>students){
                return false;
            }

        }
    }
    return true;
}


int Solution::books(vector<int> &A, int B) {
    vector<int>a=A;
    int n= a.size();
    int ans=0;
    //Now we have to find the search space and the lower bound of search space will be 0 or better is the lowest element of array and upper bound of search space will be sum because each student have max all books 
    int r=0;
    int l=a[0];
    for(int i=0;i<n;i++){
        l=min(l,a[i]);
        r+=a[i];
    }
    int mid;

    while(l<=r){
        mid=(l+r)/2;
        if(ispossible(a,mid,B)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}