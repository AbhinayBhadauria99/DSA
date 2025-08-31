class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        int counter=0;
        for(auto it:t){
            mpp[it]++;
            counter++;
        }
        int i=0,j=0;
        int start_i=0;
        int minwindowsize=INT_MAX;
        while(j<s.length()){
            if(mpp[s[j]]>0){
                counter--;
            }
            mpp[s[j]]--;
            while(counter==0){
                int windowsize=j-i+1;
                if(minwindowsize>windowsize){
                    minwindowsize=windowsize;
                    start_i=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0){
                   counter++;
                }
                i++;
            }
            j++;
        }
    return minwindowsize==INT_MAX?"":s.substr(start_i,minwindowsize);
        
    }
};