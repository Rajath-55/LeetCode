class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *temp = head;
        ListNode *res = new ListNode(head->val);
        ListNode *t_1 = res;
        while(temp && temp->next && temp->next->next != NULL){
            t_1->next = new ListNode(temp->next->next->val);
            t_1 = t_1->next;
            temp = temp->next->next;
        }
        temp = head->next;
        t_1->next = new ListNode(temp->val);
        t_1 = t_1->next;
        while(temp && temp->next && temp->next->next != NULL){
            t_1->next = new ListNode(temp->next->next->val);
            t_1 = t_1->next;
            temp = temp->next->next;
        }
        t_1->next = NULL;
        return res;
    }
};
