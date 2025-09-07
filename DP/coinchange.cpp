/*
You are given an integer array coins representing coins of different denominations and an integer amount 
representing a total amount of money. Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

 
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

#include<bits/stdc++.h>
using namespace std;

int t[13][10001]; 
int coinchange2(vector<int>& coin, int amount){
    int n = coin.size();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=amount; j++){
            if(i == 0) t[i][j] = INT_MAX -1;
            if(j%coin[0] == 0){
                t[i][j] = j/coin[0];
            }
            else t[i][j] = INT_MAX-1;
        }
    }
    for(int i=2; i<n+1; i++){
        for(int j=1; j<amount+1; j++){
            if(coin[i-1]<=j){
                t[i][j] = min(t[i][j-coin[i-1]] +1, t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][amount] >= INT_MAX-1 ? -1 : t[n][amount];
}

int main()
{
    int amount = 5;
    vector<int> coin = {6,7,8};
    int k = coinchange2(coin,amount);
    cout<<k<<endl;
    return 0;
}