class Solution {
public:
    int removePalindromeSub(string s) {
        string temp =s;
        reverse(temp.begin(), temp.end());
        if(s==temp) return 1;
        if(s=="") return 0;
        return 2;
        
    }
};


/*

ababbb


*/
