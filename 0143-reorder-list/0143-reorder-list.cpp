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

        if(!head){
            return;
        }

        deque<ListNode*> dq;
        ListNode* curr = head;

        while(curr){
            dq.push_back(curr);
            curr = curr -> next;
        }

        //queue is done, now we have to make a list of these.
        curr = dq.front(); 
        dq.pop_front();
        bool takefromback = true;

        while(!dq.empty()){

            if(takefromback){
            curr -> next = dq.back();
            dq.pop_back();
            }

            else{
            curr ->  next = dq.front();
            dq.pop_front();
            }

            takefromback = !takefromback;
            curr = curr -> next;
        }

        curr -> next = nullptr;
        
    }
};