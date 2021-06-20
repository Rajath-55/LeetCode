class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>letters;
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";
        vector<string>res,ans;
        
        for(auto x : digits){
            if(res.empty()){
                for(auto c : letters[x - '0']) ans.push_back(string(1,c));
            }else{
                for(auto y : res){
                    for(auto z : letters[x - '0']){
                        ans.push_back(y + z);
                    }
                }
            }
            swap(ans,res);
            ans.clear();
        }
        
       
        return res;
       
            
    }
    
    
};
