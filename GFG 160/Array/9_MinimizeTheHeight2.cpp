/*
Given an array arr[] denoting heights of N towers and a positive integer K.
For each tower, you must perform exactly one of the following operations exactly once.
Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest 
towers after you have modified each tower.

Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, 
the resultant array should not contain any negative integers.
Examples :
Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
*/

#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int ans = arr[n-1] - arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] - k < 0) continue;
        int minh = min(arr[0]+k, arr[i]-k);
        int maxh = max(arr[i-1]+k, arr[n-1]-k);
        ans = min(ans, maxh-minh);
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 5, 8, 10};
    int k = 2;
    int result = getMinDiff(arr, k);
    cout << result << endl;
    return 0;
}

/* Output: 5
Explanation: The heights of the towers after performing the operations are:
Tower 1: 1 + 2 = 3
Tower 2: 5 - 2 = 3
Tower 3: 8 - 2 = 6
Tower 4: 10 - 2 = 8
The minimum height is 3 and the maximum height is 8.
The difference is 8 - 3 = 5.


Complexity Analysis:
Time Complexity: O(NlogN), where N is the number of towers. We are sorting the array and then 
    traversing it once.
Space Complexity: O(1), as we are using only a constant amount of space.


Approach:
1. Sort the array of heights in ascending order.
2. Initialize a variable ans to the difference between the maximum and minimum heights.
3. Traverse the array from the second tower to the last tower (i=1 to n-1).
4. For each tower, check if the height after decreasing by k is less than 0. 
   If it is, skip to the next tower.
5. Calculate the minimum height (minh) as the minimum of the first tower's height plus k 
   and the current tower's height minus k.
6. Calculate the maximum height (maxh) as the maximum of the previous tower's height plus k
   and the last tower's height minus k.
7. Update ans to the minimum of ans and the difference between maxh and minh.
8. Return ans as the minimum possible difference between the heights of the shortest and 
   tallest towers after modification.
9. The final result is the minimum difference we can achieve by modifying the heights of the towers.
10. If no modification is possible, the result will be the original difference between the 
    maximum and minimum heights.
*/