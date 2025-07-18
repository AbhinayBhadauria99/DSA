class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<vector<int>> sortedarr;
        for(int i=0;i<tasks.size();i++){
            sortedarr.push_back({tasks[i][0],tasks[i][1],i}); //created a sorted arr and sorted on basis of starttime/enqueuetime of each task because the enqueue time will not always come in  sorted manner and stored index 
        }
        sort(sortedarr.begin(),sortedarr.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
        int idx=0; //idx to take elements from sortedarr
        long long currtime=0;
        vector<int> res;
        while(!pq.empty() || idx<n){
            if(pq.empty() && currtime<sortedarr[idx][0]){ 
                currtime=sortedarr[idx][0]; //if cpu is idle then increase curr time to next task in sortedarr

            }
            while(idx<n && sortedarr[idx][0]<=currtime){  //jo bhi task pq me aa sakte hai currtime tak unhe pq me daal do
                pq.push({sortedarr[idx][1],sortedarr[idx][2]});
                idx++;
            }

            auto temp=pq.top();
            pq.pop();
            currtime += temp.first;   //increae currtime
            res.push_back(temp.second);

        }
        return res;
    }
};