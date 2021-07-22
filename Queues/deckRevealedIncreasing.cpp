class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>res(deck.size());
        queue<int>q;
        for(int i = 0; i < deck.size(); ++i){
            q.push(i);
        }
        sort(deck.begin(), deck.end());
        
        for(auto x : deck){
            res[q.front()] = x;
            q.pop();
            if(!q.empty()){
                int t = q.front();
                q.pop();
                q.push(t);
            }
        }
        
        
        
        
        
        
        
        
        return res;
    }
};


/*
17 13 11 7 5 3 2

17 13 11 2 3 5 7








*/
