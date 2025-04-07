/*
Given an array prices[] of length n, representing the prices of the stocks on different days. 
The task is to find the maximum profit possible by buying and selling the stocks on different 
days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. 
If it is not possible to make a profit then return 0.

Note: Stock must be bought before being sold.

Examples:
Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
Output: 8
*/ 

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    int mn = prices[0];
    int ans = 0;
    for(int i=1; i<n; i++){
        mn = min(mn, prices[i]);
        ans = max(ans, prices[i]-mn);
    }
    return ans;
}

int main() {
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    int result = maximumProfit(prices);
    cout << result << endl;
    return 0;
}

/* Output: 8
Explanation: The maximum profit can be obtained by buying on day 2 (price = 1) and selling on
day 5 (price = 9), which gives a total profit of (9 - 1) = 8.



Complexity Analysis:   
Time Complexity: O(N), where N is the number of days. We are traversing the array once.
Space Complexity: O(1), as we are using only a constant amount of space.


Approach:
1. Initialize a variable mn to the first price and ans to 0.
2. Traverse the prices array from the second day to the last day (i=1 to n-1).
3. For each day, update mn to the minimum of mn and prices[i].
4. Calculate the profit for the current day as prices[i] - mn.
5. Update ans to the maximum of ans and the current profit.
6. Return ans as the maximum profit.
7. The maximum profit is the maximum difference between the current price and the minimum price
   seen so far.
8. The final result is the maximum profit we can make by buying and selling on the optimal days.
9. If no profit can be made, the result will be 0.

*/