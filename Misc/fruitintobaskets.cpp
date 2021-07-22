class Solution {
public:
    
#define maxN 100001
    
int totalFruit(vector<int>& fruits) {
    int s[maxN];    //Hash table
    
    for(int i = 0 ; i < maxN; i++)
        s[i] = 0;
    
    int j = 0;
    int sz = 0;     //Size of the total initialized space in hash table. 
    int mx = 0;
    
    for(int i = 0 ; i < fruits.size(); i++) {
        s[fruits[i]]++;
        if(s[fruits[i]] == 1) sz++;
        
        //if size > 2, we have more than two baskets fullfilled. Keep removing the 
        //elements from the back until we have 2 baskets again.
        
        while(sz > 2) {
            s[fruits[j]]--;
            if(s[fruits[j]] == 0)
                sz--;
            j++;
        } 
        
        //The sliding window [i...j] is our consideration.
        mx = max(mx, i-j+1);
    }
    return mx;
}
};

/*
sort of like a maximum subarray sum
sliding window must work 

0,1,2,2

start = 0, end = 1.
set.size() == 2;
then left = right;
right++;


3 3 3 1 2 1 1 2 3 3 4

3 3 3 1
1 2 1 1 2
3 3 4


*/
