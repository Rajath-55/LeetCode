struct Node{
    bool isWord;
    Node* next[26];
    
    Node(){
        isWord = false;
        for(int i =0; i < 26; ++i){
            next[i] = NULL;
        }
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node *root;
    WordDictionary() {
       root = new Node();
    }
    
    void addWord(string word) {
        Node *curr = root;
        for(auto x : word){
            if(curr->next[x - 'a'] == nullptr){
                curr->next[x - 'a'] = new Node();
            }
            curr = curr->next[x - 'a'];
        }
        curr->isWord = true;
    }
    bool search(string word, Node *tempRoot = NULL) {
        Node *cur = NULL;
        if(!tempRoot) cur = root;
        else cur = tempRoot;
        
        for(int i=0; i<word.size(); ++i){
            char ch = word[i];
            if(ch=='.'){
                for(int j=0; j<26; ++j){
                    if(cur->next[j] && search(word.substr(i+1, word.size()-i), cur->next[j])) return true;
                }
                return false;
            }else{
                int idx = ch-'a';
                if(cur->next[idx]==NULL) return false;
                cur=cur->next[idx];
            }
        }
        return cur->isWord;
    }
    
   
     
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 
 bad b.d
 b..
 . => search all occurences of valid alphabets 
 
 tis but a trie.
 Implement recursive search if you find a '.' otherwise its basically a trie.
 
 
 
 */
