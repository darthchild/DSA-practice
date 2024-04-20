/*
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given
stock on the ith day.
You want to maximize your profit by choosing a single day to buy 
one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/


#include <bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>& a) {
    
    int minm = a[0];
    int profit = 0;

    for(int i=0; i<a.size(); i++){

        int cost = a[i] - minm;
        profit = max(profit,cost);
        minm = min(minm,a[i]); 
    }

    return profit;
}


int main(){
    vector<int> arr = {7,1,5,3,6,4};
    cout << maxProfit(arr);
}
