class Solution {
public:
    bool isValid(string t) {
        if(t.length() <=1) return false;
        unordered_map<char,char>mp;
        unordered_set<char>s;
        s.insert('[');
        s.insert('{');
        s.insert('(');
        mp[']'] = '[';
        mp['}'] = '{';
        mp[')'] = '(';
        stack<char>st;
        for(int i =0; i < t.length(); ++i){
          
            if(s.count(t[i])){
                // cout<<t[i]<<"\n";
                st.push(t[i]);
            }else{
                if(st.empty()) return false;
                if(mp[t[i]] != st.top()) return false;
                else
                    if(not st.empty())
                    st.pop();
            }
        }
        return st.size() ? false : true;
    }
};
