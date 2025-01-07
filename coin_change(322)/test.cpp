#include <bits/stdc++.h>
using namespace std;

class solution{
private:
   int recursion(vector<int>& coins,int amount){
    if(amount==0) return 0;
    if(amount<0) return INT_MAX;  // amount get negative, return INT_MAX so that it may get eliminated in [temp!=INT_MAX] this step
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int temp=recursion(coins,amount-coins[i]);
        if(temp!=INT_MAX){
             mini=min(mini,temp+1);
        }
    }
    return mini;
   }

   int memoization(vector<int>& coins,int& amount){
   vector<int> dp(amount+1,INT_MAX);
    if(amount==0) return 0;
    if(amount<0) return INT_MAX; 
    if(dp[amount]!=INT_MAX) return dp[amount]; //memoization
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int temp=recursion(coins,amount-coins[i]);
        if(temp!=INT_MAX){
             mini=min(mini,temp+1);
        }
    }
    dp[amount]=mini;  //storing for further use
    return mini;

   }

   int tabulation(vector<int>& coins,int& amount){
     vector<int>dp(amount+1,amount+1);  //making a dp with size as amount+1 and with all the values as amount+1
     dp[0]=0;    //first index of dp as 0
     for(int i=0;i<=amount;i++){
        for(int j=0;j<coins.size();j++){
            if(coins[j]<=i){     //to check (i-coins[j]) don't get negative
               dp[i]=min(dp[i],dp[i-coins[j]]+1);  //for each index of dp check with every coin and fill with minimum (i-coins[j])
               // dp[i-coins[j]] checks if any previous index in dp has this value i.e. why we filled dp[0] as 0 .so for index 1  it will do 0+1.
            }
        }
     }
     return dp[amount]<=amount?dp[amount]:-1;  //if last index is still amount+1 the return -1.
   }

public:
  int mincoins(vector<int>& coins,int& amount){
    int minicoins=memoization(coins,amount);
    return minicoins;
  }
};

int main(){
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    // Clear the newline character left in the input buffer
    cin.ignore();
    cout << "Enter space-separated numbers: ";
    vector<int> coins;
    string input;
    getline(cin, input); // Read the entire input line

    stringstream ss(input); // Parse the input
    int num;
    while (ss >> num) {
        coins.push_back(num); // Add numbers to the vector
    }


    solution s;
    cout << "Minimum coins required: " << s.mincoins(coins, amount) << endl;
    return 0;
}