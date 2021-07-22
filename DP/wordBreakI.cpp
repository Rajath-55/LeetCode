class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp with state = index i needed
        // dp[i] will store if its possible tosegment the prefix till i or not,
        //basically true or false 
        // now if there is a word present after this, then the prefix till there is also solvable
        vector<bool>dp(s.size() + 1, false);
        unordered_set<string>dict;
        for(auto x : wordDict) dict.insert(x);
        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i){
            for(int j = i-1; j >= 0; --j){
                if(dp[j]){
                string temp = s.substr(j, i-j);
                if(dict.count(temp)){
                    dp[i] = true;
                    break;
                }
                }
            }
        }
        return dp[s.size()];
        
    }
};

/*
For every index, itws true if the prefix till there is segmentable
then for every index, if tis true, then tilll 0 we check tif there is a tru
then if that substring from the first true and the current index true
gives a valid word from the dictionary, then it is a proper splittable
thingy.

dp[0] = true, because 0 here means there are 0 characters;
indexing in dp is like :i = no of characters till now and not really idx


*/
