#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int countsubsetsum(int arr[], int sum, int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j == 0) t[i][j] = true;
            else if(i == 0) t[i][j] = false;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
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
    int sum=13,n=59;
    int arr[n]={0, 2, 3, 1, 4, 5, 2, 3, 1, 2, 2, 5, 5, 0, 8, 2, 7, 6, 6, 9, 8, 8, 9, 1, 5, 6, 2, 2 ,5 ,9 ,1 ,5 ,0 ,4 ,6 ,3 ,9 ,6 ,9, 7, 6, 3, 3, 9, 7, 2, 9, 9, 2, 6, 1, 3, 4, 7, 4, 6, 6, 2, 6};
    cout<<countsubsetsum(arr,sum,n)<<endl;
    return 0;
}

