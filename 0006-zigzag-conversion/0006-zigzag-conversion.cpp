class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n=s.length();
        string res="";
        int jump=(numRows-1)*2; //first and last element of column has there next occurence at
        for(int i=0;i<numRows;i++){
            for(int j=i;j<n;j+=jump){
                res+=s[j];
                if(i>0 && i<numRows-1 && (j+jump-(2*i))<n){
                 int temp= j+jump-(2*i);  //mid elements have some additional occurences , jump keep reducing by 2
                 res+=s[temp];
                }
            }
        }
        return res;
    }
};