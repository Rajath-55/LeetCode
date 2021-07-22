class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        int i=0, n=path.length();
        while(i<n){
            string temp;
            while(path[i]=='/' && i<n) i++;
            while(path[i]!='/' && i<n) temp+=path[i++];
            if(temp==".." && !st.empty()) st.pop_back();
            else if(temp=="." || temp=="") continue;
            else if(temp!="..") st.push_back(temp);               
        }
        string res;
        for(string s:st) res+= "/" + s;
        return res.empty() ? "/":res;
    }
};
