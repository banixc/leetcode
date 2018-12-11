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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* new_head = head;
        head = head -> next;
        new_head->next = NULL;
        while(head != NULL) {
            ListNode* now_insert = head;
            head = head->next;
            now_insert -> next = NULL;
            ListNode* new_pos = new_head;
            ListNode* last_pos = NULL;            
            bool flag = false;
            while(new_pos != NULL) {
                if(new_pos->val > now_insert->val) {
                    now_insert->next = new_pos;
                    if(last_pos!=NULL) {
                        last_pos->next = now_insert;
                    } else {
                        new_head = now_insert;
                    }
                    flag = true;
                    break;
                }
                last_pos = new_pos;
                new_pos = new_pos->next;
            }
            if(!flag){
                last_pos->next = now_insert;
                now_insert->next = NULL;
            }
        }
        return new_head;
    }
};