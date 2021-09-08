struct Node{
    Node *next[2];
    int val;
    Node(){
      val = 0;
      next[0] = NULL;
     next[1] = NULL;
    }
};
class Solution {
public:
    Node *root;
    void insert(int n){
        Node *curr = root;
        for(int i = 31; i >=0; --i){
            int bit = 1&(n>>i);
            if(not curr->next[bit]){
                curr->next[bit] = new Node();
            }
            curr = curr->next[bit];
        }
        curr->val = n;
    }
    int search(int n){
        Node* curr = root;
        for(int i = 31; i>=0; --i){
            int bit = 1&(n>>i);
            if(bit == 0){
                if(curr->next[1]) curr = curr->next[1];
                else curr = curr->next[0];
            }else{
                if(curr->next[0]) curr = curr->next[0];
                else curr = curr->next[1];
            }
        }
        return n^(curr->val);
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        for(auto x : nums) insert(x);
        int ans = 0;
        for(auto x : nums){
            ans = max(ans, search(x));
        }
        return ans;
        
    }
};
