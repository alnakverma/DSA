// same as count of subset with a given difference
#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int targetsum(vector<int>& arr, int target){
    int n = arr.size();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            if(j == 0) t[i][j] = true;
            else if(i == 0) t[i][j] = false;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][target];
}

int main()
{
    int diff=1, n=5;
    vector<int> arr = {1, 2, 3, 1, 2};
    int sum =0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    int target = (sum + diff)/2;
    cout<<targetsum(arr,target)<<endl;
    return 0;
}

