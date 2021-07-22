class Solution {
public:
    int lengthOfLastWord(string s) {
        int firstIdx = 0, lastIdx = s.size()-1;
        if(s==" ") return 0;
        int countSpaces = 0;
        for(auto x : s) if(x==' ') countSpaces++;
        if(countSpaces == s.length()) return 0;
        while(s[firstIdx] == ' ') firstIdx++;
        while(s[lastIdx] == ' ') lastIdx--;
        int lastSpace=-1;
        for(int i=firstIdx; i<=lastIdx; ++i){
            if(s[i]==' ' && s[i+1]!=' ')
                lastSpace = i;
        }
        cout<<lastSpace<<" "<<lastIdx<<'\n';
        int count = 0;
        if(lastSpace == -1){
            for(int i=firstIdx;i<=lastIdx; ++i){
                if(s[i]!=' ') count++;
            }
        }else{
            for(int i=lastSpace+1; i<=lastIdx; ++i){
                cout<<s[i]<<" ";
                if(s[i]!=' ') count++;
                
            }
        }
        return count;
    }
};
