/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*>mp;
    Node* dfs(Node *node){
        if(mp.count(node)) return mp[node];
        Node *deepCopy = new Node(node->val);
        mp[node] = deepCopy;
        for(auto x : node->neighbors){
            deepCopy->neighbors.push_back(dfs(x));
        }
        return deepCopy;
    }
    Node* cloneGraph(Node* node) {
        if(not node) return node;
        dfs(node);
        return mp[node];
    }
};


/*
Standard solution for a deep clone seems to be to use a map to keep track:
a map that can hold node, node
for every node, mp[node] = deep_copy
and for every deep_copy's neighbours do the same in dfs
O(N) time and space

*/
