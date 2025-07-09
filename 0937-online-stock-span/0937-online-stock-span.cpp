class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int temp=1;
        while(!st.empty() && st.top().first<=price){
            temp+=st.top().second; //count those elements also that has been poped since there value is stored in last largest entry of stack in temp. Pop karne ke baad wo price future me kisi aur ke liye kabhi bhi useful nahi hoga
            st.pop();
        }
        st.push({price,temp});   
        return temp;   
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */