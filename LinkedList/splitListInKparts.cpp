class Solution {
public:
    //Function to get the size of the linked list
    int getsize(ListNode *root){
        int c = 0;
        ListNode *temp = root;
        while(temp!=NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }
    vector<ListNode *>res;
    
    //Function to insert k element in the vector
    void insert(ListNode *&head,int k){
        if(head==NULL){
            return;
        }
        res.push_back(head);
        ListNode *prev = NULL;
        while(k--){
            prev = head;
            head = head->next;
        }
        if(prev!=NULL){
             prev->next = NULL;
        }
       
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         int n = getsize(head);
         if(k>=n){
             vector<ListNode *>res;
                while(head!=NULL){
                    ListNode *temp = head->next;
                    head->next = NULL;
                    res.push_back(head);
                    head = temp;
                    k--;
                }
             while(k--) res.push_back(NULL);
             return res;
         }
        int d = n/k;
        int td = d;
        int r = n%k;
        if(r==0){
            while(k--){
                insert(head,td);
            }
            return res;
        }
        while(r--){
            insert(head,d+1);
            k--;
        }
        while(k--){
            insert(head,d);
        }
        return res;
    }
};
