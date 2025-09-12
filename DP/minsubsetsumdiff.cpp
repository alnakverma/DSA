/*
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of 
length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each 
element of nums into one of the two arrays. Return the minimum possible absolute difference.

Example 1:
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.


Constraints:

1 <= n <= 15
nums.length == 2 * n
-10^7 <= nums[i] <= 10^7
*/




#include<bits/stdc++.h>
using namespace std;

int minsubsetsumdiff(vector<int>& arr){
    //subset sum code
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    bool t[n+1][sum+1]; 
    vector<int> temp;
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
            //storing the last row of the table in temp where the stored value is true
            //collecting all possible subset sums from the last row
            if(i==n-1 && t[i][j]==true) temp.push_back(j);
        }
    }
    //Finding the minimum subset sum difference
    int mn = INT_MAX;
    n = temp.size();
    for(int i=0; i<n; i++){
        mn = min(mn, sum-2*temp[i]);
    }
    return mn;
}

int main()
{
    vector<int> arr = {1,2,5};
    cout<<minsubsetsumdiff(arr)<<endl;
    return 0;
}

