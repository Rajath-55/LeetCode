class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>countChars;
        for(auto x :words){
            for(auto y : x){
                countChars[y]++;
            }
        }
        for(auto x: countChars){
            if(x.second%words.size())
                return false;
        }
        return true;
            
    }
};
