/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TreeNode *inorderSuccessor(TreeNode *node){
        TreeNode *temp = node;
        while(temp and temp->left) temp = temp->left;
        return temp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(not root) return root;
        
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else{
            if(not root->left and not root->right){
                return NULL;
            }else if(root->left == NULL){
                TreeNode *temp = root->right;
                delete(root);
                return temp;
            }else if(root->right == NULL){
                TreeNode *temp = root->left;
                delete(root);
                return temp;
            }
            TreeNode *temp = inorderSuccessor(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};

/*

Delete a node in O(h) time
h = log2n
First search for the element in the bst, if we reacha null pointer return null
as we didnt get the value in the bst
if we do get,
there are 3 cases:
no children, 1 child or 2 children
if no children, delete the node and return null from there
if left but not right, make the root as left and delete the root;
if right but not left, make the root as right and delete the root;
if both children, we can do two things, either the inorderpredecessor or the 
inordersuccsessor.
We did the inordersuccessor and then deleted that successor.

lots of recursive shit in here check afain


*/
