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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* vhead = new ListNode(0);
        vhead->next = head;
        ListNode* point = head;
        ListNode* last = vhead;
        ListNode* end = head;
        for(int i = 0; i < n ; i ++) {
            end = end->next;
        }
        while(end != NULL) {
            last = point;
            point = point->next;
            end = end->next;
        }
        last->next = point->next;
        return vhead->next;
    }
};