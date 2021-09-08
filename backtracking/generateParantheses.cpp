class Solution {
public:
    vector<string>ans;
    

    void backtrack(int n, int open, int closed, stack<char>&st){
        if(open == n and closed == n){
            string temp = "";
            stack<char>all = st;
            while(not all.empty()){
                temp+=all.top();
                all.pop();
            }
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        
        if(open < n){
            st.push('(');
            backtrack(n, open + 1, closed, st);
            st.pop();
        }
        if(closed < open){
            st.push(')');
            backtrack(n, open, closed + 1, st);
            st.pop();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        stack<char>st;
        backtrack(n, 0, 0,st);
        
        return ans;
    }
};
