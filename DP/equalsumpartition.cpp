#include<bits/stdc++.h>
using namespace std;


bool equalsumpartition(int arr[], int n){
    int sum = 0;
    bool t[n+1][sum+1]; 
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    if(sum % 2 != 0) cout<<false<<endl;
    else sum = sum/2;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j == 0) t[i][j] = true;
            else if(i == 0) t[i][j] = false;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
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
    int n=5;
    int arr[n]={4,8,2,7,1};
    cout<<equalsumpartition(arr,n)<<endl;
    return 0;
}

