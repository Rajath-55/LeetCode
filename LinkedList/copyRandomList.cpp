class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
			return head;
        unordered_map<Node *, Node *> visited;
        Node *copied;
        queue<Node *> Q;
        Q.push(head);
        visited[head] = copied = new Node(head->val);
        while (Q.size()) {
            Node *curr = Q.front(); Q.pop();
            if (curr->next && visited.count(curr->next) == 0) {
                Q.push(curr->next);
                visited[curr->next] = new Node(curr->next->val);
            }
            if (curr->random && visited.count(curr->random) == 0) {
                Q.push(curr->random);
                visited[curr->random] = new Node(curr->random->val);
            }
            visited[curr]->next = visited[curr->next];
            visited[curr]->random = visited[curr->random];
        }
        
        return copied;
    }
};

class Solution {
    /**
    1: we made dummy nodes of every nodes in between the nodes like : 1---dummy---2
    2: then we set the random pointer thats why we made dummy node in b/w the nodes
    3: then we seprate both the linked list
    
    */
public:
    Node* copyRandomList(Node* head) {
        if(!head )return NULL;
        Node* curr=head;
        Node* temp=head;
        while(curr)
        {
            temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            curr=temp;
        }
        curr=head;
        while(curr){
            curr->next->random = curr->random? curr->random->next : curr->random;
            curr=curr->next ? curr->next->next : curr->next;
        }
        Node* ans =head->next;
        Node* traverse=ans;
        while(head and traverse){
            head->next=head->next ? head->next->next : head->next;
            traverse->next = traverse->next ? traverse->next->next : traverse->next;
            head=head->next;
            traverse=traverse->next;
        }
        return ans;
    }
};
