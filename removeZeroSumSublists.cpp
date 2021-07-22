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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        int sumSub = 0;
        for (int i = 0; i < v.size(); i++) {
            if(v.at(i) == 0){
                continue;
            }
            sumSub = 0;
            for (int j = i; j < v.size(); j++) {
                if(v.at(j) == 0){
                    continue;
                }
                sumSub += v.at(j);
                if (sumSub == 0) {
                    for (int k = i; k <= j; k++) {
                        v.at(k) = 0;
                    }
                    break;
                }
            }
        }
        ListNode* res = new ListNode();
        ListNode* curr = new ListNode();
        res->next = curr;
        for(int l=0;l<v.size();l++){
            if(v.at(l)!=0){
                curr->next = new ListNode(v.at(l));
                curr = curr->next;
            }
        }
        return (res->next)->next;
    }
};