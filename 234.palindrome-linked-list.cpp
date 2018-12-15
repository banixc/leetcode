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
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode* now = head;
        while(now != NULL) {
            now = now->next;
            length ++;
        }
        if(length<=1) {
            return true;
        }
        now = head;
        ListNode* new_head = NULL;
        for(int i = 0; i < length; i ++) {
            if(i == length-1) {
                now->next = new_head;
                new_head = now;
            } else if(i >= length-length/2) {
                ListNode* temp = now->next;
                now->next = new_head;
                new_head = now;
                now = temp;
            } else {
                now = now->next;
            }
        }
        now = head;
        for(int i = 0; i < length/2; i ++) {
            cout << now->val << " " << new_head->val << endl;
            if(now->val != new_head->val) 
                return false;
            now = now->next;
            new_head = new_head->next;
        }
        return true;
    }
    
};