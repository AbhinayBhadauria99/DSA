#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int M= 1e9+7; //its limit
            int n=arr.size();
            vector<int> prefix(n+1,0);  //if we gonna initialize particular value to this array later then we must initalize it with its size. here its n+1 because we are making 0 index as 0 forcefully so we need take 1 size bigger to store all the sums
            prefix[0]=0;
            
            int prefix_size=prefix.size();
            //preparing prefix vector
            for(int i=1;i<prefix_size;i++){
                 prefix[i]=prefix[i-1]+arr[i-1];
            }
    
            int even=1; //because first element was entensionally made 0
            int odd=0;
            int count=0;
            for(int j=1;j<prefix_size;j++){ //first element was 0 in prefix so we need to skip that
                if(prefix[j]%2==0){ //even(current)+odd=odd
                  count=((odd+count)%M);  //updating count value 
                  even++;   //because current element was even
                }
                else{ //odd(current)+even=odd
                  count=((even+count)%M);
                  odd++; //because current element was odd
                }
            }
        return count;
        }
    };
    int main() {
        string input;
        getline(cin, input);
        
        vector<int> arr;
        stringstream ss(input); 
        int num;
        
        while (ss >> num) { 
            arr.push_back(num);
        }
    
        Solution sol;
        cout << sol.numOfSubarrays(arr) << endl;  
    
        return 0;
    }