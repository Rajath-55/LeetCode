class Solution {
public:
    string getHint(string secret, string guess) {
       
        unordered_map<char,int>mp1,mp2;
        int cows = 0, bulls = 0;
        for(int i = 0; i < secret.size(); ++i ){
            if(secret[i] == guess[i]){
                bulls++;
                continue;
            }
            mp1[secret[i]]++;
            mp2[guess[i]]++;
        }
        for(char i = '0'; i <= '9'; ++i){
            cows+=min(mp1[i], mp2[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
        
    }
};
