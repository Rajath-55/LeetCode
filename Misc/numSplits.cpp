class Solution {
public:
    int numSplits(string s) {
        if(s.size() <=1) return 0;
        set<int>temp, temp1;
        int res = 0;
        vector<int>prefixSize(s.size(), 0), postfixSize(s.size(), 0);
        prefixSize[0] = 1;
        temp.insert(s[0]);
        temp1.insert(s[s.size() - 1]);
        postfixSize[s.size() - 1] = 1;
        for(int i = 1 ; i < s.size(); ++i){
            temp.insert(s[i]);
            prefixSize[i] = temp.size();
            
        }
        for(int i = s.size() - 2; i >=0; --i){
            temp1.insert(s[i]);
            postfixSize[i] = temp1.size();
        }
//         for(auto x : prefixSize) cout<<x<<" ";
//         cout<<"\n";
//         for(auto x : postfixSize) cout<<x<<" ";
//         cout<<"\n";
        
        for(int i = 0 ; i < s.size() - 1; ++i){
            if(prefixSize[i] == postfixSize[i+1])
                res++;
        }
        return res;
        
        
    }
};

/*
should be a dp solution i think?

state = at index i, the number of splits we can make at i

acbadbaada
mid = 0 + 9 /2 = 4

acba d baada



*/
