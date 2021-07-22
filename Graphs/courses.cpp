class Solution {
public:
    vector<bool>visited;
    unordered_map<int, set<int>>lst;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses;++i) visited.push_back(false);
        
        for(auto x : prerequisites){
            lst[x[1]].insert(x[0]);
        }
        
        for(int i=0; i<numCourses; ++i){
            if(!check(i)) return false;
        }
        return true;
    
    }
    
    bool check(int i){
        if(visited[i]) return false;
        
        if(lst[i].empty()) return true;
        
        visited[i] = true;
        
        for(auto x : lst[i]){
            if(!check(x)) return false;
        }
        visited[i] = false;
        lst[i].clear();
        
        return true;
    }
};
