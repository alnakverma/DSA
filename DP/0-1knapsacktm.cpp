#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int knapsack0_1(int wt[], int val[], int w, int n){
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][w];
}

int main()
{
    int w=10,n=5;
    int wt[n]={4,5,2,7,1};
    int val[n]={4,8,2,9,7};
    int k = knapsack0_1(wt,val,w,n);
    cout<<k<<endl;
    return 0;
}