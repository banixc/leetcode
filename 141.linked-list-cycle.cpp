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
        ListNode *first, *second;
        first = head;
        second = head;
        do {
            if(first!=NULL)
                first = first->next;
            else
                return false;
            
            if(second!=NULL&&second->next!=NULL)
                second = second->next->next;
            else
                return false;
            
        } while(first != second);
            return true;
    }
};