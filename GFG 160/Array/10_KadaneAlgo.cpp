/*
Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:
Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
*/


#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    // Your code here
    int n = arr.size();
    int ans = arr[0];
    int mx = arr[0];
    for(int i=1; i<n; i++){
        mx = max(mx+arr[i], arr[i]);
        ans = max(ans, mx);
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr) << endl;
    return 0;
}

/* Output: 11
Explanation: The maximum sum of a subarray is 11, which is the sum of the subarray [7, -1, 2, 3].


Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(1)



Approach:
1. Initialize two variables, ans and mx, to the first element of the array.
2. Iterate through the array from the second element to the last element.
   For each element arr[i], update mx to be the maximum of mx + arr[i] and arr[i]. 
   This step checks whether to include the current element in the existing subarray 
   or start a new subarray with the current element.
3. Update ans to be the maximum of ans and mx. This step keeps track of the maximum sum 
   encountered so far.
4. After iterating through the entire array, return ans as the maximum sum of a subarray.
*/