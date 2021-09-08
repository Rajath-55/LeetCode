class Node{
public:
    Node* left;
    Node* right;
    
    Node(){
        left = NULL;
        right = NULL;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(int data){
        Node* temp = root;
        for(int i = 31; i >= 0; i--){
            int bit = (data >> i) & 1;
            if(bit == 0){
                if(temp->left == NULL){
                    temp->left = new Node();
                }
                temp = temp->left;
            }
            else{
                if(temp->right == NULL){
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }
    
    int max_xor_helper(int data){
        Node* temp = root;
        int max_xor_val = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (data >> i) & 1;
            if(bit == 0){
                if(temp->right != NULL){
                    max_xor_val += (1 << i);
                    temp = temp->right;
                }
                else temp = temp->left;
            }
            else{
                if(temp->left != NULL){
                    max_xor_val += (1 << i);
                    temp = temp->left;
                }
                else temp = temp->right;
            }
        }
        return max_xor_val;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* myNums = new Trie();
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            myNums->insert(nums[i]);
            res = max(res, myNums->max_xor_helper(nums[i]));
        }
        
        return res;
    }
};
