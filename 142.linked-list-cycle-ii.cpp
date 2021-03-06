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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL) return NULL;
		unordered_map<ListNode*, int> m;
		while(head != NULL) {
			if(m.find(head) != m.end()) {
				return head;
			} else {
				m[head] = 1;                
			}
			head = head -> next;
		}
		return NULL;
	}
};