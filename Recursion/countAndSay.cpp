class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string res = countAndSay(n-1);
        string ans = "";
        int count = 1;
        
        for(int i = 0; i < res.size(); ++i){
            int curr = i;
        
            while(res[i+1] == res[i] and i<res.size()){
                i++;
                count++;
            }
            ans+=to_string(count);
            ans+=res[curr];
            count = 1;
            
        }
        return ans;
    }
};
