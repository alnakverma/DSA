/*
You are given an integer array coins representing coins of different denominations and an integer amount 
representing a total amount of money. Return the number of combinations that make up that amount. If that 
amount of money cannot be made up by any combination of the coins, return 0. You may assume that you have 
an infinite number of each kind of coin. The answer is guaranteed to fit into a signed 32-bit integer.

 
Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1


Constraints:
1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/


#include<bits/stdc++.h>
using namespace std;

unsigned long long t[301][5001]; 
int coinchange1(vector<int>& coins, int amount){
    int n = coins.size();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=amount; j++){
            if(j == 0) t[i][j] = 1;
            else if(i == 0) t[i][j] = 0;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<amount+1; j++){
            if(coins[i-1]<=j){
                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][amount];
}

int main()
{
    int amount=5;
    vector<int> coins={1,2,3};
    int k = coinchange1(coins,amount);
    cout<<k<<endl;
    return 0;
}