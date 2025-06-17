class Solution {
public:
    string intToRoman(int num) {
        vector<string> romans={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> rVal={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        //explicitly mention about numbers starting from 9,4 as they contains smaller char before larger
        string res="";
        for(int i=0;i<romans.size();++i){
            while(num>=rVal[i]){
                num-=rVal[i];
                res+=romans[i];
            }
        }
        return res;
    }
};