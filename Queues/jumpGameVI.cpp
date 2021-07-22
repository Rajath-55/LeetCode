class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        q.push_back({0,nums[0]});
        for(int i=1;i<nums.size();++i) {
            while(q.front().first+k<i) {
                q.pop_front();
            }
            auto curr = q.front().second+nums[i];
            while(!q.empty() && q.back().second<curr) {
                q.pop_back();
            }
            q.push_back({i,curr});
        }
        return q.back().second;
    }
};
/*
Seems to me like dfs-bfs only with some extra constraints on edges 
or 
dequeue it seems
lmao


keep it in ascending order or non negative order 



*/
