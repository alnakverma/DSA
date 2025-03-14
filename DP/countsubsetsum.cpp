#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int sumofsubset(int arr[], int sum, int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j == 0) t[i][j] = true;
            else if(i == 0) t[i][j] = false;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
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
    int sum=10,n=6;
    int arr[n]={2,3,5,6,8,10};
    cout<<sumofsubset(arr,sum,n)<<endl;
    return 0;
}

