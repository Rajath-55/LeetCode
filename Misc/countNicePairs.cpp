class Solution {
public:
    int rev(int x){
        string temp = to_string(x);
        reverse(temp.begin(), temp.end());
        return stoi(temp);
    }
    const int mod = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int>mp;
        long long int count = 0;
        for(auto x : nums){
            int temp = x - rev(x);
            count = (count + mp[temp])%mod;
            mp[temp]++;
        }
        return count%mod;
        
    }
};


/*


42 11 1 97

42 + rev(x) = 24 + x
42 - 24 = x - rev(x)

rev(x)




*/
