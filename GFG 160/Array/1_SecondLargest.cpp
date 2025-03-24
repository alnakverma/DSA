/*
Given an array of positive integers arr[], return the second largest element from the array. 
If the second largest element doesn't exist then return -1.
Note: The second largest element should not be equal to the largest element.
Example:
Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
*/

#include <bits/stdc++.h>
using namespace std;

int getSecondLargest(vector<int> &arr) {
    int n = arr.size();
    int lar = -1, ans = -1;
    for(int i=0; i<n; i++){
        if(lar < arr[i]) lar = arr[i];
    }
    for(int i=0; i<n; i++){
        if(ans < arr[i] && arr[i] != lar) ans = arr[i];
    }
    return ans;
}

int main(){
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout<<getSecondLargest(arr)<<endl;
    return 0;
}