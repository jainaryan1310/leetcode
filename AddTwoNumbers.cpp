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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int s=0;
		int c=0;
		ListNode* dummyHead = new ListNode();
		ListNode* curr = dummyHead;
		while(l1!=NULL || l2!=NULL || c!=0){
			s=0;
			if(l1!=NULL){
				s=l1->val;
				l1=l1->next;
			}
			if(l2!=NULL){
				s=s+l2->val;
				l2=l2->next;
			}
			if(c!=0){
				s=s+c;
			}
			c=s/10;
			s=s%10;
			ListNode* next = new ListNode(s);
			curr->next = next;
			curr = curr-> next;
		}
		return dummyHead->next;
    }
};
