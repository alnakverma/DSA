/*
You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

Note: The answer should be returned in an increasing format.

Examples:
Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findMajority(vector<int>& arr) {
    unordered_map<int, int> m;
    int n = arr.size();
    for(auto x : arr) m[x]++;
    vector<int> ans;
    for(auto i : m){
        if(i.second > n/3) ans.push_back(i.first);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int> arr = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> result = findMajority(arr);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* Output: [5, 6]
Explanation: The candidates that have votes greater than one-third of the total votes are 5 and 6.



Complexity Analysis:
Time Complexity: O(NlogN)
Space Complexity: O(N)



 Approach:
1. Create a hash map to store the frequency of each element in the array.
2. Traverse the array and update the frequency of each element in the hash map.
3. Initialize an empty vector to store the result.
4. Traverse the hash map and check if the frequency of each element is greater than n/3.
5. If it is, add the element to the result vector.
6. Sort the result vector in increasing order.
7. Return the result vector.
*/