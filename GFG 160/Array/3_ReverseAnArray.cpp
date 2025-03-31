/*
You are given an array of integers arr[]. Your task is to reverse the given array.
Note: Modify the array in place.

Examples:
Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
*/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr) {
    int n = arr.size();
    int i =0, j = n-1;
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main() {
    vector<int> arr = {1, 4, 3, 2, 6, 5};
    reverseArray(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* Output: [5, 6, 2, 3, 4, 1]
Explanation: The array is reversed in place.


Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(1)


 Approach:
1. Initialize two pointers i and j to 0 and n-1 respectively.
2. While i is less than j, swap arr[i] with arr[j].
3. Increment i and decrement j in each iteration.
4. Continue this process until i is no longer less than j.
5. The array will be reversed in place without using any extra space.
 Note: The array is modified in place, meaning the original array is changed and 
  no extra space is used for another array.
6. The final array will be the reverse of the original array.
*/