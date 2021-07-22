class TrieNode {
    public:
    vector<TrieNode *> nodes;
    bool isEnd;
    string word;
    TrieNode() {
        nodes.resize(26, NULL);
        isEnd = false;
    }
};

class Trie {
    
    TrieNode* trieNode;
    public:
    Trie() {
        trieNode = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = trieNode;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(curr->nodes[index] == NULL) {
                curr->nodes[index] = new TrieNode();
            }
            curr = curr->nodes[index];
        }
        curr->isEnd = true;
        curr->word = word;
    }
    
    string getLongestWord() {
        string res = "";
        queue<TrieNode *> q;
        q.push(trieNode);
        while(q.empty() == false) {
            TrieNode* trie = q.front(); q.pop();
            for(int i = 25; i>=0; i--) {
                if(trie->nodes[i] != NULL && trie->nodes[i]->isEnd == true) {
                    res = trie->nodes[i]->word;
                    q.push(trie->nodes[i]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();
        for(string word: words) trie->insert(word);
        return trie->getLongestWord();
    }
};

/*
standard trie solution
*/
