class Solution {
public:
    static bool customCompare(const pair<int,string> &p1, const pair<int, string>&p2){
        if(p1.first != p2.first){
            return p1.first > p2.first;
        }
        return p1.second + p2.second < p2.second + p1.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>mp;
        for(auto x : words) mp[x]++;
        vector<pair<int, string>>r;
        for(auto x : mp){
            r.push_back({x.second, x.first});
        }
        sort(r.begin(), r.end(), customCompare);
        vector<string>res;
        for(int i=0; i<k;++i){
            res.push_back(r[i].second);
        }
         
        return res;
        
    }
};
