class Solution {
public:
    vector<vector<string>>res;
    vector<string>part;
    
    void backtrack(int i, string s){
        if(i >= s.length()){
            res.push_back(part);
            return;
        }
        for(int j = i; j < s.length(); ++j){
            if(isPalindrome(s.substr(i, j - i + 1))){
                part.push_back(s.substr(i, j - i + 1));
                backtrack(j + 1, s);
                //clean up in backtrack actual idea...
                part.pop_back();
            }
        }
    }
    
    bool isPalindrome(string t){
        string k = t;
        reverse(k.begin(), k.end());
        return k == t;
    }
    vector<vector<string>> partition(string s) {
        backtrack(0, s);
        return res;
    }
};
/*
Worst case, every single character is a partition in itself

We use backtracking in this:
bounding - if not a palindrome dont continue down the dfs tree.

The tree is basically taking one char, two, three....all
then for every node, remaining ones can be added further down the nodes.

move ahead in every node iff its a palindrome itself.
         aab
       a       aa     aab x
   a      ab     b


main part of backtracking is the fact that we add a valid string, move ahead in the tree, and then pop it back so that we come back up to go to other branches in the tree, as can be seen aboe.

*/
