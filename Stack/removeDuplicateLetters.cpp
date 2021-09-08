class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>found(26,0);
        stack<char>st;
        vector<int>last(26,0);
        for(int i = 0; i < s.length(); ++i) last[s[i] - 'a'] = i;
        
        for(int i = 0; i < s.length(); ++i){
            if(found[s[i] - 'a']) continue;
            while(not st.empty() and st.top() > s[i] and last[st.top() - 'a'] > i) {
                found[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            found[s[i] - 'a'] = 1;
        }
        string res = "";
        while(not st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
        
    }
};
