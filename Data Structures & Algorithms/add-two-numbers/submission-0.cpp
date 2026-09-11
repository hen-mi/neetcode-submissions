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
        
        ListNode* newList = new ListNode(0);
        ListNode* newcurr = newList;
        ListNode* currl1 = l1;
        ListNode* currl2 = l2;
        
        int carry = 0;
        int sum = 0;
        while(currl1 || currl2 || carry) {

            int digit1 = currl1 ? currl1->val : 0;
            int digit2 = currl2 ? currl2->val : 0;

            sum = digit1 + digit2 + carry;

            newcurr->val = sum % 10;

            carry = sum / 10;

            currl1 = currl1 ? currl1->next : nullptr;
            currl2 = currl2 ? currl2->next : nullptr;

            if (currl1 || currl2 || carry) {
                newcurr->next = new ListNode(0);
                newcurr = newcurr->next;
            }

        }   

        return newList;
    }
};
