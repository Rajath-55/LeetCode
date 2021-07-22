class Solution {
public:
    vector<vector<int>>G;
    vector<int>indigrees;
    vector<bool>visited;
    unordered_set<int>topo[102];
    
    void kahns(int n){
        queue<int>q;
        for(int i = 0; i < n; ++i){
            if(indigrees[i] == 0){
                q.push(i);
            }
        }
        while(not q.empty()){
            int val = q.front();
            q.pop();
            for(auto x : G[val]){
                for(auto y : topo[val]){
                    topo[x].insert(y);
                }
                topo[x].insert(val);
                indigrees[x]--;
                if(indigrees[x] == 0){
                    q.push(x);
                }
            }  
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        visited.resize(n + 1, false);
        indigrees.resize(n + 1, 0);
        G.resize(n+1);
        for(auto x : prerequisites){
            G[x[0]].push_back(x[1]);
            indigrees[x[1]]++;
        }
        kahns(n);
        vector<bool>ans;
        if(prerequisites.size() == 0){
            ans.resize(queries.size(), false);
            return ans;
        }
        
        for(auto x:queries){

            if(topo[x[1]].count(x[0])) ans.push_back(true);
             else ans.push_back(false);
      }
        
        return ans;
        
    }
};

/*
Kahns topological sort, wuth a set containing evefy prerequsite

*/
