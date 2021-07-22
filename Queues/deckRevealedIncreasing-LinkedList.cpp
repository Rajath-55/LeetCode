class Node {
public:
    int val;
    Node* right = nullptr; 
    Node* left = nullptr;
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    
    void insert(int val) {
        Node* newTail = tail->left;
        newTail->right = nullptr;
        Node* newHead = new Node();
        newHead->val = val;
        newHead->right = tail;
        tail->left = newHead;
        tail->right = head;
        head->left = tail;
        tail = newTail;
        head = newHead;
        //return;
    }
    
    vector<int> toArray() {
        vector<int> output {};
        Node* curr = head;
        while (curr!=nullptr) {
            output.push_back(curr->val);
            curr = curr->right;
        }
        return output;
    }
};

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        if (n<=2) return deck;
        LinkedList* ll = new LinkedList();
        Node* head = new Node();
        Node* tail = new Node();
        head->val = deck[n-2]; 
        tail->val = deck[n-1];
        head->right = tail;
        tail->left = head;
        ll->head = head;
        ll->tail = tail;
        for (int i=deck.size()-3;i>=0;i--) {
            ll->insert(deck[i]);
        }
        return ll->toArray();
    }
};
