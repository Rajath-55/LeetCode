struct Node{
    bool isWord;
    Node *next[26];

    addWord(string word){
        Node *curr = root;
        for(int i  = 0; i <word.size(); ++i ){
            if(not curr->next[word[i] - 'a']) {
                //nake a new node
            }
            go there
        }
    }
}
