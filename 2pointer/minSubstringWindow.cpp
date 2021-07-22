class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n){
            return "";
        }
                
        unordered_map<char,int> um2;
        int letters = 0;
        for(int i = 0; i < m; i++){
            um2[t[i]]++;
        }
        int i=0,j=0;
        int ans = INT_MAX;
        string ANS = "";
        
        while(j < n){
            while(j<n && letters!=m){
                if(um2.find(s[j])!=um2.end()){
                    if(um2[s[j]]>0){
                        letters++;
                    }
                    um2[s[j]]--;
                }
                j++;
            }
            
            while(i<j && letters==m){
                if(um2.find(s[i])!=um2.end()){
                    if(um2[s[i]]==0){
                        if(letters==m && ans > j-i){
                            ans = j-i;
                            ANS = s.substr(i,j-i);
                        }
                        letters--;
                    }
                    um2[s[i]]++;
                    
                }
                i++;
            }
           
        }

        return ANS;
    }
};
