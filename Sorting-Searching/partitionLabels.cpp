class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>>positions;
        vector<pair<int,int>>pos;
        for(int i = 0; i < s.length(); ++i){
            if(positions.count(s[i])){
                positions[s[i]].second = i;
            }else{
                positions[s[i]] = {i,i};
            }
        }
        for(auto x : positions) pos.push_back(x.second);
        sort(pos.begin(), pos.end());
        vector<pair<int,int>>res;
        res.push_back(pos[0]);
        for(int i = 1; i < pos.size(); ++i){
            if(res[res.size() -1].second >= pos[i].first ){
                if(pos[i].second > res[res.size() -1].second)
                    res[res.size() - 1].second = pos[i].second;
            }else{
                res.push_back(pos[i]);
            }
        }
        vector<int>ans;
        for(auto x : res){
            ans.push_back(x.second - x.first + 1); 
        }
        
        return ans;
    }
};


/*


ababcbacadefegdehijhklij

ababcbaca, defgde, hijhklij

a : start : 0, end : 8
b : start : 1 end : 5
c : start : 1, end : 7
d : start : 9, end : 14






*/
