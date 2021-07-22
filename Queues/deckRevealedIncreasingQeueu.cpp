class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>ans(n);
       
        queue<int>q;
        for(int i = 0; i < n; ++i) q.push(i);
        sort(deck.begin(), deck.end());
        for(int i = 0; i < n; ++i){
            ans[q.front()] = deck[i];
            q.pop();
            if(!q.empty()){
                int t = q.front();
                q.pop();
                q.push(t);
            }
        }
        return ans;
    }
};
/*
Tis a BFS question

queue = -
17 13 11 2 3 5 7

sort the elements and then add 

queue = stores indices;


*/
