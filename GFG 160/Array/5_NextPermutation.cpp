/*
Given an array of integers arr[] representing a permutation, implement the next permutation 
that rearranges the numbers into the lexicographically next greater permutation. If no such 
permutation exists, rearrange the numbers into the lowest possible order 
(i.e., sorted in ascending order). 

Note - A permutation of an array of integers refers to a specific arrangement of its elements 
in a sequence or linear order.

Examples:
Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
*/

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& arr) {
    int p = -1;
    int n = arr.size();
    for(int i=n-1; i>0; i--){
        if(arr[i] > arr[i-1]){ 
            p = i-1;
            break;
        }    
    }
    if(p == -1){
        reverse(arr.begin(), arr.end());
        return;
    }
    for(int i=n-1; i>p; i--){
        if(arr[i] > arr[p]){
            swap(arr[i], arr[p]);
            break;
        }
    }
    reverse(arr.begin()+p+1 , arr.end());
}

int main() {
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    nextPermutation(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is [2, 4, 5, 0, 1, 7].


Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(1)


 Approach:   
1. Initialize a pivot variable p to -1. This variable will store the index of the first element 
   from the right that is smaller than its next element.
2. Traverse the array from right to left and find the first element arr[i] that is smaller than 
   arr[i+1]. This index is stored in p.
3. If p is -1, it means the array is in descending order, and we need to reverse the entire array.
4. If p is not -1, find the smallest element in the right subarray (arr[p+1] to arr[n-1]) that is 
   greater than arr[p]. Swap this element with arr[p]. 
5. Reverse the right subarray (arr[p+1] to arr[n-1]) to get the next permutation.
6. The array is modified in place, meaning the original array is changed and no extra space 
   is used for another array.
7. The final array will be the next permutation of the original array.
8. The next permutation is the smallest lexicographically greater permutation of the array.
9. If no such permutation exists, the array is rearranged into the lowest possible order 
   (i.e., sorted in ascending order).
*/