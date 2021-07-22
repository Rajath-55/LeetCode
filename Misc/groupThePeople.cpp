class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>counts;
        vector<vector<int>>result;
        for(int i=0; i<groupSizes.size(); ++i){
            counts[groupSizes[i]].push_back(i);
        }
        for(auto x : counts){
            
            if(x.second.size() == x.first){
                result.push_back(x.second);
            }else{
                vector<int>temp;
                int count = 0;
            
                for(int i=0; i<x.second.size(); ++i){
                    count++;
                    if(count%x.first ==0){
                        cout<<count<<"\n";
                        temp.push_back(x.second[i]);
                        result.push_back(temp);
                        temp.clear();
                    }else{
                        temp.push_back(x.second[i]);
                    }
                }
            }
           
        }
        
        return result;
    }
};

/**
 * A better solution using maps and sets
*/
 
 class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        map<int, set<int>> m;
        for (int i = 0; i < groupSizes.size(); i++) {
            int gsize = groupSizes[i];
            m[gsize].insert(i);
            if (m[gsize].size() == gsize) {
                res.push_back({m[gsize].begin(), m[gsize].end()});
                m[gsize].clear();
            }
        }
        return res;
    }
};