class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>counts(26,0);
        for(auto x : words2){
            vector<int>tempCounts(26, 0);
            for(auto y : x) tempCounts[y - 'a']++;
            for(int i = 0; i < 26; ++i){
                if(counts[i] < tempCounts[i]) counts[i] = tempCounts[i];
            }
        }
        int nonzero = 0;
        for(int i = 0; i < 26; ++i) if(counts[i] > 0) nonzero++;
        for(auto x : words1){
            vector<int>temp(26,0);
            int countNonZero = 0;
            for(auto y : x) temp[y - 'a']++;
            for(int i = 0; i < 26; ++i){
                if(counts[i] > 0 and temp[i] >= counts[i]) countNonZero++;
            }
            if(countNonZero >= nonzero) ans.push_back(x);
        }
        return ans;
        
        
    }
};
