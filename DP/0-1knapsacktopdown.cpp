/*
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to 
put the items in the knapsack such that the sum of weights of the items <= W and the sum of values 
associated with them is maximized. 
Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is 
available in single quantity.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
*/


#include<bits/stdc++.h>
using namespace std;

int t[1001][1001]; 
int knapsack0_1(vector<int> &wt, vector<int>& val, int w){
    int n = val.size();
    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][w];
}

int main()
{
    int w=10;
    vector<int> wt = {4,5,2,7,1};
    vector<int> val = {4,8,2,9,7};
    cout<<knapsack0_1(wt, val, w);
    return 0;
}