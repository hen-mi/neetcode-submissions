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
    void reorderList(ListNode* head) {
        
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        //finds the middle of the list with slow pointer
        while(fast->next && fast->next->next) {

            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; //breaks cycle, now it is the end of the list

        while(curr) {
            
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;

        }

        ListNode* first = head;
        curr = prev;


        while(curr) {
            auto temp1 = first->next;
            auto temp2 = curr->next;

            first->next = curr;
            curr->next = temp1;

            first = temp1;
            curr = temp2;

        }

    }
};
