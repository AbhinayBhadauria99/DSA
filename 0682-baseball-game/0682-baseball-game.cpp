class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto it: operations){
            if(it=="D"){
              int temp=st.top();
              if (!st.empty()) st.push(2*temp);
            }
            else if(it=="C"){
                if (!st.empty()) st.pop();
            }
            else if(it=="+"){
                int temp1=st.top();
                st.pop();
                int temp2=st.top();
              st.push(temp1);
              st.push(temp1+temp2);
            }
            else{
                st.push(stoi(it));
            }
        }

        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};