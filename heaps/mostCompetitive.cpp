class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>res;
        if(nums.size() == 1 ) return nums;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0 ; i < nums.size() - k + 1; ++i){
            pq.push({nums[i], i});
        }
        int j = nums.size() - k + 1;
        while(k--){
            auto p = pq.top();
            pq.pop();
            res.push_back(p.first);
            while(!pq.empty() and pq.top().second < p.second){
                pq.pop();
            }
            if(j < nums.size()) pq.push({nums[j],j});
            j++;
        }
        return res;
        
        
        
        
    }
};


/*

3 5 2 6

3 5 


2 4 3 3 5 4 9 6

2 4 3 3 




*/
