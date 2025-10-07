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
        if(!head){
            return NULL;
        }

        
        int size = 0;

        ListNode* curr = head;

        while(curr){
            size++;
            curr = curr -> next;
        }


        if (n == size) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
        }

        if(size == 1 && n == 1){
            return NULL;
        }

        int nodeskips = size - n;

        curr = head;
        ListNode* prev = NULL;

        while(nodeskips){
            nodeskips--;
            prev = curr;
            if(curr -> next) curr = curr -> next;
        }

        prev -> next = curr -> next;

        return head;
    }
};