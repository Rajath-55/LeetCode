class Solution {
public:
    // Function to generate all the nodes from current Node
    vector<string> generateNodes(string key){
        vector<string> res;
        for(int i=0;i<4;i++){
            string temp = key;
            temp[i] = (key[i] - '0' + 1)%10 + '0';
            res.push_back(temp);
            temp[i] = (key[i] - '0' - 1 + 10)%10 + '0';
            res.push_back(temp);
        }
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        unordered_set<string> dead;
        // If "0000" is a deadend return -1
        // Set will be used for checking later on such that we don't push
        // a deadend into our queue while traversing
        for(auto x : deadends){
            dead.insert(x);
            if(x == "0000"){
                return -1;
            }
        }
        queue<string> bfs;
        bfs.push("0000");
        visited.insert("0000");
        int res = 0;
        // If target is "0000" itself
        if(target == "0000"){
            return res;
        }
        while(!bfs.empty()){
            int size = bfs.size();
            while(size--){
                string currNode = bfs.front();
                bfs.pop();
                // Checking for all possible neighbours or connections
                vector<string> conn = generateNodes(currNode);
                for(auto x : conn){
                    // If found target increase result and return
                    if(x == target){
                        res++;
                        return res;
                    }
                    // If neighbour is a deadend continue
                    if(dead.find(x) != dead.end()){
                        continue;
                    }
                    // If neighbour still not visited traverse from it
                    if(visited.find(x) == visited.end()){
                        visited.insert(x);
                        bfs.push(x);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
