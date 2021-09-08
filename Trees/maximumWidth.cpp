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
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        
        int maxWidth = 0;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            int qLen = q.size();
            unsigned long long minIdx = ULLONG_MAX, maxIdx = 0;
            
            for (int i = 0; i < qLen; ++i) {
                TreeNode *node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();
                
                minIdx = min(minIdx, index);
                maxIdx = max(maxIdx, index);
                
                if (node->left != nullptr) {
                    q.push(make_pair(node->left, 2 * index));
                }
                if (node->right != nullptr) {
                    q.push(make_pair(node->right, 2 * index + 1));
                }
            } // end of for-loop
            
            maxWidth = max(maxWidth, static_cast<int>(maxIdx - minIdx + 1));
        } // end while-loop
        
        return maxWidth;
    }
     
  
};
/*
This question is difficult because of certain edge cases which make some feasible solutions not be accepted. For example, BFS with adding NULL nodes will give TLE. This suggests that we need to take a different approach.

So instead of counting the nodes we can give heap labelling to the elements during BFS so that all the elements on the same level have consecutive positions. By heap labelling, the meaning is that the root node is assigned a position pos = 1, and then its left child is assigned a position of pos * 2 and its right child is assigned a position of pos * 2 + 1 and this is repeated for left and right subtrees with their own starting positions.

Now even if an element is NULL its numbering is covered without it having to be inserted. So, before starting to empty elements from BFS queue one can use the difference between the positions of the first and last element in the queue as the next width candidate. To store the positions along with the nodes, in C++ pair of a node and an integer can be used for BFS.

However there is also a test case which gives an error due to a large depth leading to 2 * pos going out of bounds for some nodes in the tree.

To resolve this in C++,

unsigned long long int must be used to store the position (common technique)
If at some point the queue has only a single element, the numbering should be restarted from 1 (hack from most upvoted answers)
Only with both of these together do all test cases pass on LC. However, such cases should probably not be there in an interview situation, since they require hacks and not a particular way of thinking. Moreover the hack does not work when say the tree is very deep with lots of 2-wide levels.


*/
