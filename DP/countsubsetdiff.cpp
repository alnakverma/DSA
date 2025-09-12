/*
Given an array arr of n integers and an integer diff, count the number of ways to partition the array 
into two subsets S1 and S2 such that:
∣S1−S2∣ = diff and S1 ≥ S2
Where |S1| and |S2| are sum of Subsets S1 and S2 respectively.

Examples:
Input: arr = [1, 1, 2, 3], diff = 1

Output: 3
Explanation: The subsets are [1, 2] and [1, 3], [1, 3] and [1, 2], [1, 1, 2] and [3].

Constraints:
1 <= n <= 200
0 <= d <= 10^4
0 <= arr[i] <= 50
*/

#include<bits/stdc++.h>
using namespace std;

 
int countsubsetdiff(vector<int>& arr, int diff){
    int n = arr.size();
    int sum =0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    if((sum+diff) % 2 != 0 || sum < diff) cout<<0<<endl;
    int k = (sum + diff)/2;

    int t[n+1][k+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(j == 0) t[i][j] = true;
            else if(i == 0) t[i][j] = false;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][k];
}

int main()
{
    int diff = 1;
    vector<int> arr={1, 2, 3, 1, 2};
    cout<<countsubsetdiff(arr,diff)<<endl;
    return 0;
}

