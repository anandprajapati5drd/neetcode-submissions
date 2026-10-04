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

        ListNode* temp = head;
        int size = 0;

        while(temp){
            temp = temp->next;
            size++;
        }

        if(n == size){
            ListNode* toDelete = head;
            head = head->next;
            delete(toDelete);

            return head;
        }

        ListNode* temp1 = head;
        int idx = 1;
        while(size-idx != n){
            idx++;
            temp1 = temp1->next;
        }
        ListNode* toDelete = temp1->next;
        temp1->next = temp1->next->next;

        delete(toDelete);

        return head;
        
    }
};
