struct Node{
    bool isWord;
    Node *next[26];
    Node(){
        isWord = false;
        for(int i = 0; i < 26; ++i) next[i] = NULL;
    }
};



class Solution {
    void insert(Node *root, string s){
        Node *curr = root;
        
        for(auto x : s){
            if(not curr->next[x - 'a']){
                curr->next[x - 'a'] = new Node();
            } 
            curr = curr->next[x - 'a'];
        }
        curr->isWord = true;
    }
    
    void dfs(Node *root, vector<string>&temp, string &s){
        if(not root) return;
        if(temp.size() == 3) return;
        
        
        //handling multiple cases with isWord++ done.
        for(int i = 0; i < root->isWord; ++i){
            temp.push_back(s);
            if(temp.size() == 3) return;
        }
        for(int i = 0; i < 26; ++i){
            
            //try to backtrack with each letter added and removed once.
            s.push_back(i + 'a');
            dfs(root->next[i], temp, s);
            s.pop_back();
        }
    }
    vector<vector<string>>search(string searchWord, Node *root){
        Node *curr = root;
        string s = "";
        vector<vector<string>>ans;
        for(char c : searchWord){
            s.push_back(c);
            //store ans for this particular prefix now
            vector<string>temp;
            
            //curr == NULL if the letter that we added in the prefix is not present in the trie.
            if(curr != NULL){
                curr = curr->next[c - 'a'];
                dfs(curr, temp, s);
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Node* root = new Node();
        for(auto product : products){
            insert(root, product);
        }
        vector<vector<string>>ans;
        ans = search(searchWord, root);
        return ans;
        
    }
};

/*
Standard trie question we can see 
if(isPrefix) then

moment

//to handle duplicates:
make isWord an integer;
whenever you go to the end of a string make the isWord of that. = isWord + 1;

this is also a binary search question.

 
*/
