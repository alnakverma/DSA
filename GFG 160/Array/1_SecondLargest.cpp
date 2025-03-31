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

/* Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.


Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(1)


Approach:
1. Initialize two variables lar and ans to -1. lar will store the largest element and ans will 
    store the second largest element.
2. Traverse the array and find the largest element lar.
3. Traverse the array again and find the second largest element ans which is not equal to lar.
4. Return ans as the second largest element.
5. If the second largest element doesn't exist, return -1. 
*/