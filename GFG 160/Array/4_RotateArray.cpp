/*
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, 
where d is a positive integer. Do the mentioned change in the array in place.
Note: Consider the array as circular.
Examples :
Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
*/

#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;
    reverse(arr.begin(), arr.begin() + d); 
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;
    rotateArray(arr, d);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* Output: [3, 4, 5, 1, 2]
Explanation: The array is rotated to the left by 2 steps.


Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(1)


Approach:   
1. Calculate the effective number of rotations needed by taking d modulo n (d = d % n).
2. Reverse the first d elements of the array.
3. Reverse the remaining n - d elements of the array.
4. Reverse the entire array.
5. The array will be rotated to the left by d steps.
6. The elements at indices 0 to d-1 will be the last d elements of the original array, 
   and the elements at indices d to n-1 will be the first n - d elements of the original array.
7. The final array will be the rotated version of the original array.
8. The array is modified in place, meaning the original array is changed and no extra space 
    is used for another array.
*/