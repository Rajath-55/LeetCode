class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        string p = "";
        
        for(int i = 0; i < s.length(); ++i){
            if(s[i] >= '0' and s[i] <='9'){
                int nextBracket = s.find('[', i);
                string toPush = s.substr(i, nextBracket);
                st.push({p,stoi(toPush)});
                p = "";
                i = nextBracket;
                
            }else if(s[i] == ']'){
                auto top = st.top();
                st.pop();
                string toAdd = "";
                for(int j = 0; j < top.second; ++j){
                    toAdd+=p;
                }
                p = top.first + toAdd;
            }else{
                p+=s[i];
            }
        }
        return p;
    }
};
