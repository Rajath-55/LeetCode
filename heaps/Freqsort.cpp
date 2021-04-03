class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(char c:s)
            m[c]+=1;
        priority_queue<pair<int,char>>q;
        for(auto it:m)
        {
            q.push({it.second,it.first});
        }
        string ans="";
        while(!q.empty())
        {
            int x=q.top().first;
            while(x!=0)
            {
                ans+=q.top().second;
                x-=1;
            }
            q.pop();
        }
        return ans;
    }
};
