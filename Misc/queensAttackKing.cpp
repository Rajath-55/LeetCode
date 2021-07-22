class Solution {
public:
    vector<pair<int,int>>dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};
   
    void helper(vector<vector<int>>&G, int kingx, int kingy, int dirx, int diry, vector<vector<int>>&res){
        while(true){
            if(kingx < 0 or kingx >=8 or kingy < 0 or kingy >=8) break;
            // cout<<kingx<<" "<<kingy<<"\n";
            if(G[kingx][kingy] == 1){
                res.push_back({kingx, kingy});
                break;
            }
            kingx+=dirx;
            kingy+=diry;
        }
    }
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int m = queens.size();
        vector<vector<int>>res;
        vector<vector<int>>G(8, vector<int>(8, 0));
        for(auto x : queens) G[x[0]][x[1]] = 1;
        
        for(auto x : dirs){
            helper(G, king[0], king[1], x.first, x.second, res);
        }
        
        return res;
    }
};

/*
A queen can move in all directions

A queen can attack the king if:
(It is in the same row and there is no queen between it and the king) OR it is in the same column OR it is in the same diagonal) etc.

dfs from each queen's position, can go left right top down etc
if there is a queen then you cannot go
if you have visited the king from each queen's dfs add that queen into the ans else no



*/
