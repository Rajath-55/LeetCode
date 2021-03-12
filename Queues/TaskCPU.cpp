#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>counts(26,0);
        for(auto x :tasks) counts[x-'A']++;
        int maxi = *max_element(counts.begin(), counts.end());
        int c = 0;
        for(auto x : counts) if(x==maxi) c++;
        int ans = (maxi-1)*(n+1) + c;
        return (int)max((int)tasks.size(), ans);
        
    }
};


/*
Queue Solution:
*/
