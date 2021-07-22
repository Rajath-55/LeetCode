class Solution {
public:
    vector<vector<int>>G;
    vector<bool>visited;
    int n;
    void dfs(int src){
        visited[src] = true;
        for(auto x : G[src]){
            if(not visited[x]) dfs(x);
        }
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        G.resize(n);
        visited.resize(n+1,false);
        for(int i = 0; i < n; ++i){
            if(i + arr[i] < n){
                G[i].push_back(i + arr[i]);
            }
            if(i - arr[i] >=0){
                G[i].push_back(i - arr[i]);
            }
        }
        dfs(start);
        bool flag = false;
        for(int i = 0; i < n; ++i){
            if(arr[i] == 0 and visited[i]) flag = true;
        }
        return flag;
        
    }
};
/*

looks quite a lot like dfs
so lets do that only
lmao
model the graph and do dfs no stack nonsense for me
O(n) time only


*/
// a BFS solution, apparently is much faster:
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        vector<bool>visit(arr.size(),false);
        while(!q.empty()){
            int k=q.front();
            q.pop();
            if(k+arr[k]<arr.size()&&!visit[k+arr[k]]){
                if(arr[k+arr[k]]==0)return true;
                q.push(k+arr[k]);
                visit[k+arr[k]]=true;
            }
            if(k-arr[k]>=0&&!visit[k-arr[k]]){
                if(arr[k-arr[k]]==0)return true;
                q.push(k-arr[k]);
                visit[k-arr[k]]=true;
            }
        }
        return false;
    }
};
