



class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
      priority_queue<pair<int,int>, vector<pair<int, int> >,  greater<pair<int,int> > >pq;
        int idx = 0,res=0;
        while(idx < days.size() || !pq.empty()){
            if(idx < days.size() && apples[idx] > 0){
                pq.push({days[idx] + idx, apples[idx]});
            }
            
            while(!pq.empty()){
                pair<int,int> temp = pq.top();
                pq.pop();
                if(temp.second ==0 || temp.first <= idx) continue;
                temp.second--;
                res++;
                if(temp.second){
                    pq.push({temp.first, temp.second});
                }
                break;
                
            }
            idx++;
        }
        return res;
          
    }
};
