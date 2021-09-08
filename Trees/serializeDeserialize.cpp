/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int getHeight(TreeNode *root){
        if(not root) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1 + max(left, right);
    }

    void bfs(string &s, TreeNode *root){
        queue<TreeNode*>q;
        int height = getHeight(root);
        int depth = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            depth++;
            for(int i = 0; i< size; ++i){
                auto front = q.front();
                q.pop();
                if(not front) s+="null,";
                else s+= to_string(front->val) + ",";
                
                if(front) q.push(front->left);
                if(front) q.push(front->right);
                        
            }
        }
       
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(not root) return "null";
        bfs(res, root);
        cout<<res<<"\n";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        if(data=="null") return NULL;
        string temp;
        vector<string>vals;
        while(getline(ss, temp, ',')) vals.push_back(temp);
        queue<TreeNode*>q;
        TreeNode *root = new TreeNode(stoi(vals[0]));
        q.push(root);
        int startIdx = 0;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int left = startIdx + 1;
            int right = startIdx + 2;
            if(left <= vals.size() - 1 and vals[left] != "null"){
                front->left = new TreeNode(stoi(vals[left]));
                q.push(front->left);
            }
             if(right <= vals.size() - 1 and vals[right] != "null"){
                front->right = new TreeNode(stoi(vals[right]));
                q.push(front->right);
            }
            startIdx +=2;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// bfs with stringstream and edge cases elemyi
