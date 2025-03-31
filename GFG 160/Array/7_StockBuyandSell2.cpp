/*
The cost of stock on each day is given in an array price[]. Each day you may decide to either 
buy or sell the stock i at price[i], you can even buy and sell the stock on the same day. 
Find the maximum profit that you can get.

Note: A stock can only be sold if it has been bought previously and multiple stocks cannot 
be held on any given day.

Examples:
Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
*/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    int ans = 0;
    for(int i=1; i<n; i++){
        if(prices[i] > prices[i-1]) 
            ans+= prices[i] - prices[i-1];
    }
    return ans;
}

int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    int result = maximumProfit(prices);
    cout << result << endl;
    return 0;
}

/* Output: 865
Explanation: The maximum profit can be obtained by buying on day 0 (price = 100) and selling
on day 3 (price = 310), then buying on day 4 (price = 40) and selling on day 6 (price = 695).
which gives a total profit of (310 - 100) + (695 - 40) = 865.


Complexity Analysis:
Time Complexity: O(N), where N is the number of days. We are traversing the array once.
Space Complexity: O(1), as we are using only a constant amount of space.


Approach:
1. Initialize a variable ans to 0 to store the maximum profit.
2. Traverse the prices array from the second day to the last day (i=1 to n-1).
3. For each day, check if the price of the current day is greater than the price of the previous day.
4. If it is, add the difference (prices[i] - prices[i-1]) to ans.
5. Return ans as the maximum profit.
6. The maximum profit is the sum of all the positive differences between consecutive days.
7. This is because we can buy and sell on the same day, so we can take advantage of every price increase.
8. The final result is the total profit we can make by buying and selling on the optimal days.
*/