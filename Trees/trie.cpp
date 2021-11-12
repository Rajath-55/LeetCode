struct Node{
    bool isWord;
    Node *next[26];
    Node(){
        isWord = false;
        for(int i = 0; i < 26; ++i){
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node *root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = root;
        for(auto x : word){
            if(not curr->next[x - 'a']){
                curr->next[x-'a'] = new Node();
            }
            curr = curr->next[x - 'a'];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        for(auto x : word){
            if(not curr->next[x - 'a']){
                return false;
            }
            curr = curr->next[x - 'a'];
        }
        return curr->isWord;  
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *curr = root;
        for(auto x : prefix){
            if(not curr->next[x - 'a']){
                return false;
            }
            curr = curr->next[x - 'a'];
        }
        return true; 
    }
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
