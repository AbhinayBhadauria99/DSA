class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp; //map me frequency save ki
        for(auto it: tasks){
            mpp[it]++;
        }
        priority_queue<int> pq;  //pq me highest freq upar
        for(auto it:mpp){
            pq.push(it.second);
        }
        
        int time=0;
        while(!pq.empty()){   
            vector<int> temp;
            for(int i=1;i<=n+1;i++){   //n+1 tak loop chal kar values pq ke upar se uthao , kam karo , aur temp naam ke vector me daal do , baad me temp se utha kar vapas pq mein
                 if(!pq.empty()){
                     int tempo=pq.top();
                     pq.pop();
                     tempo--;
                     temp.push_back(tempo);
                    }
            }
            for(int i=0;i<temp.size();i++){  //vapas pq me daalo reduced values
                if(temp[i]>0){
                    pq.push(temp[i]);
                }
            }
            if(pq.empty()){   //agar pq empty hai toh temp me jitni values thi utne times hi task hue
                time+=temp.size();
            }
            else{ //otherwise poore n+1 task hue (idle included hai isme)
                time+=(n+1);
            }

        }

        return time;
    }
};