 vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res; // create container for returning final result
        vector<int> temp; // temp array for containing nodes when going from root down to leaves
        DFS(root, targetSum, res,temp); //calling DFS function
        return res; //return final result
    }
    
    void DFS(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& temp){
        if(root==NULL)return; //if root is null then just end
        if(root->left==NULL&&root->right==NULL&&root->val==targetSum){
            temp.push_back(root->val); //if this is the leave we want
            res.push_back(temp);            //namely both left and right nodes are null
            temp.pop_back();                 //value equal to target value
														//push into temp first, then push temp into res, pop to do backtrack
        }
        temp.push_back(root->val);    // when a node is not desired yet, push the value to temp for now
        DFS(root->left, targetSum-root->val, res,temp); //checking current root's left and right nodes
        DFS(root->right, targetSum-root->val, res,temp);
        temp.pop_back();                  //pop to backtrack
    }
