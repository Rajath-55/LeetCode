class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict;
        for(auto x : wordList) {
            dict.insert(x);
        }
        if(dict.count(endWord) == 0 ) return 0;
        queue<string>q;
        int depth = 0;
        int lsize = 1;
        q.push(beginWord);
        
        while(!q.empty()){
            depth++;
            int size = q.size();
            for(int i = 0; i < size; ++i){
                string temp = q.front();
                q.pop();
                for(int j = 0; j < temp.length(); ++j){
                    string curr = temp;
                    for(char k = 'a'; k <= 'z'; ++k){
                        curr[j] = k;
                        if(curr == temp) continue;
                        if(curr == endWord) return depth + 1;
                        if(dict.find(curr) != dict.end()){
                            q.push(curr);
                            dict.erase(curr);
                        }
                    }
                }
            }
        }
        return 0;
        
        
    }
};

/*
Something like a BFS I think
Each word is a node, and each transformation is an edge.
Edge weights are one, and bfs gives shortest distance from souce 
to dest.

mutliple time bfs on depth only smh good stuff
n^2 time 

*/


