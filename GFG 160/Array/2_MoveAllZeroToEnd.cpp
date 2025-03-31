/*
You are given an array arr[] of non-negative integers. Your task is to move all the zeros in the 
array to the right end while maintaining the relative order of the non-zero elements. 
The operation must be performed in place, meaning you should not use extra space for another array.
Examples:
Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.
*/

#include <bits/stdc++.h>
using namespace std;

void pushZerosToEnd(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    while(i<n){
        if(arr[i] != 0){ 
            swap(arr[i],arr[j]);
            j++;
        }
        i++;
    }
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.


Complexity Analysis:
Time Complexity: O(N)   
Space Complexity: O(1)


Approach:
1. Initialize two pointers i and j to 0.
2. Traverse the array using the i pointer.
3. If the current element arr[i] is not equal to 0, swap arr[i] with arr[j] and increment j.
4. Increment i in each iteration.
5. Continue this process until i reaches the end of the array.
6. The elements at indices j to n-1 will be 0, and the elements at indices 0 to j-1 will be 
   non-zero elements in their original order.
7. The final array will have all the non-zero elements at the beginning and all the zeros at the end.
*/