<<<<<<< HEAD
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        map<ListNode*, bool>visited;
        while(head){
            if(visited.find(head)!=visited.end())
                return true;
            visited[head] = true;
            head = head->next;
        }
        return false;
    }
=======
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        map<ListNode*, bool>visited;
        while(head){
            if(visited.find(head)!=visited.end())
                return true;
            visited[head] = true;
            head = head->next;
        }
        return false;
    }
>>>>>>> 673ed86091449e4adc8c32e9546b1b85b39181ad
};