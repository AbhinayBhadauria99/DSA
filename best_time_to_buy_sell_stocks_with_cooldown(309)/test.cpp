#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp; // memoization

int dfs(int i, bool buying, vector<int>& prices) { //buying variable will help us to check if have to do cooldown or not
    if (i >= prices.size()) {
        return 0;
    }
    
    string key = to_string(i) + "-" + to_string(buying); //we are preparing a unique key for each index that will be stored in dp
    if (dp.find(key) != dp.end()) { //if for any key corresponding value is already there in dp then use it
        return dp[key];
    }
    
    int cooldown = dfs(i + 1, buying, prices); //for every index we will always have a option of cooldown.we can visualize it by making a tree for this problem statement
    
    if (buying) {
        int buy = dfs(i + 1, false, prices) - prices[i];  //if buy something we have to reduce amount .if we have 0 rs and we buy 2rs object then current condition will be -2 rs.
        dp[key] = max(buy, cooldown);
    } else {
        int sell = dfs(i + 2, true, prices) + prices[i];  //if we sold amount we gained will be get added 
        dp[key] = max(sell, cooldown);
    }
    
    return dp[key];
}

int maxProfit(vector<int>& prices) {
    return dfs(0, true, prices);
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}
