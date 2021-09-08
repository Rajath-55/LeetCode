struct Node{
    bool isWord;
    Node *next[26];
    
    Node(){
        isWord = false;
        for(int i = 0; i < 26; ++i) next[i] = NULL;
    }
};


class Solution {
public:
    Node *root;
    Solution(){
        root = new Node();
    }
    void addWord(string s){
        Node *curr = root;
        
        for(auto x : s){
            if(curr->next[x - 'a'] == nullptr){
                curr->next[x - 'a'] = new Node();
            }
            curr = curr->next[x - 'a'];
        }
        curr->isWord = true;
    }
    string search(string s){
        Node *curr = root;
        int n = s.length();
        string res = "";
        
        for(int i =0; i < n; ++i){
            char toFind = s[i];
            
            if(curr->next[toFind - 'a'] != nullptr){
                res += toFind;
                curr = curr->next[toFind - 'a'];
                if(curr->isWord) return res;
            }else{
                return s;
            }
        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string>words;
        stringstream ss(sentence);
        string temp;
        while(getline(ss, temp, ' ')){
            words.push_back(temp);
        }
        for(auto x : dictionary) addWord(x);
        
        for(auto &x : words){
            // cout<<x<<" "<<search(x)<<"\n";
            x = search(x);
        }
        string res = words[0];
        for(int i = 1; i < words.size(); ++i){
            res += " " + words[i];
        }
        return res;
        
    }
};
/*
Standard trie solution.
Add all dictionary words into the trie.
Then search with those words that are in the string.
If there is a smaller occurence then we can add that else the word remains as is
*/
