class Solution {
public:
    int minPartitions(string n) {
        
        int count = INT_MIN;
        for(auto x : n){
            count = max(count, x - '0');
        }
        
        return count;
    }
};

/*
12
11+1
13 = 11+1+1

322
111 + 111 + 100

82734
7*11111 + 







*/
