#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int sumofsubset(int wt[], int val[], int w, int n){
    if(wt[n-1] <= w){
        return t[n][w] = sumofsubset(wt,val,w-wt[n-1],n-1),sumofsubset(wt,val,w,n-1);
    }
    else if(wt[n-1]>w){
        return t[n][w] = sumofsubset(wt,val,w,n-1);
    }
    return 0;
}


int main()
{
    memset(t, -1, sizeof(t));
    int w=10,n=5;
    int wt[n]={4,5,2,7,1};
    int val[n]={4,8,2,9,7};
    int k = sumofsubset(wt,val,w,n);
    cout<<k<<endl;
    return 0;
}