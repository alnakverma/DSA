/*
Given an vector array arr of non-negative integers and a value sum, the task is to check if there is a subset 
of the given array whose sum is equal to the given sum. 

Examples: 

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: True
Explanation: There is a subset (4, 5) with sum 9.

Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 10^4
*/



#include<bits/stdc++.h>
using namespace std;

bool t[201][10001]; 
bool sumofsubset(vector<int>& arr, int sum){
    int n = arr.size();
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
    int sum = 20;
    vector<int> arr = {4,8,2,7,1};
    cout<<sumofsubset(arr,sum)<<endl;
    return 0;
}

