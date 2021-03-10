<<<<<<< HEAD
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> vals;
        while (head)
        {
            vals.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < vals.size() / 2; ++i)
        {
            if (vals[i] != vals[vals.size() - i - 1])
                return false;
            else
                continue;
        }
        return true;
    }
=======
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> vals;
        while (head)
        {
            vals.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < vals.size() / 2; ++i)
        {
            if (vals[i] != vals[vals.size() - i - 1])
                return false;
            else
                continue;
        }
        return true;
    }
>>>>>>> 673ed86091449e4adc8c32e9546b1b85b39181ad
};