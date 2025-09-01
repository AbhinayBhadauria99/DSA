class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }       
        string res="";
        while(!pq.empty()){
            int currval=pq.top().first;
            char currchar=pq.top().second;
            pq.pop();
            if(res.length()>=2 && res[res.length()-1]==currchar && res[res.length()-2]==currchar){
                if(pq.empty()) break;
                int nextval=pq.top().first;
                char nextchar=pq.top().second;
                pq.pop();
                res.push_back(nextchar);

                nextval--;
                if(nextval>0){
                    pq.push({nextval,nextchar});
                }
                
            }
            else{
                currval--;
                res.push_back(currchar);

            }
            if(currval>0){
                pq.push({currval,currchar});
            }           
        }
    return res;
    }
};