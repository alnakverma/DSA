
#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int knapsack(int wt[], int val[], int w, int n){
    if(w==0 || n==0) return 0;
    if(t[n][w] != -1) return t[n][w];
    
    if(wt[n-1] <= w){
        t[n][w] = max(val[n-1] + knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1));
    }
    else{
        t[n][w] = knapsack(wt, val, w, n-1);
    }
    return t[n][w];
}

int main()
{
    memset(t, -1, sizeof(t));
    int w=10,n=5;
    int wt[n]={4,5,2,7,1};
    int val[n]={4,8,2,9,7};
    int k = knapsack(wt,val,w,n);
    cout<<k<<endl;
    return 0;
}