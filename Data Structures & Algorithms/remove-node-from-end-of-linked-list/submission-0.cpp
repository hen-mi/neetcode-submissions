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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* start = head;
        ListNode* prev = nullptr;

        ListNode* size = head;
        int c = 1;
        while(size) {
            c++;
            size = size->next;
        }
        
        int count = 1;

        while(head) {

            if(c-count == n) {

                auto temp = head;
                
                head = head->next;

                if(prev){
                    prev->next = head;
                }
                else {
                    start = head;
                }


                return start;

            }

            count++;
            prev = head;
            head = head->next;
        }
        

        return start;       
    }
};
