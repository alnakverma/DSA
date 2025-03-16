#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int coinchange2(int coin[], int sum, int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i == 0) t[i][j] = INT_MAX -1;
            if(j%coin[0] == 0){
                t[i][j] = j/coin[0];
            }
            else t[i][j] = INT_MAX-1;
        }
    }
    for(int i=2; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coin[i-1]<=j){
                t[i][j] = min(t[i][j-coin[i-1]] +1, t[i-1][j]);
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
    int sum=5,n=4;
    int coin[n]={1,2,3,5};
    int k = coinchange2(coin,sum,n);
    cout<<k<<endl;
    return 0;
}