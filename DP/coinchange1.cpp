#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int coinchange1(int coin[], int sum, int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j == 0) t[i][j] = 1;
            else if(i == 0) t[i][j] = 0;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coin[i-1]<=j){
                t[i][j] = t[i][j-coin[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}

int main()
{
    int sum=5,n=3;
    int coin[n]={1,2,3};
    int k = coinchange1(coin,sum,n);
    cout<<k<<endl;
    return 0;
}