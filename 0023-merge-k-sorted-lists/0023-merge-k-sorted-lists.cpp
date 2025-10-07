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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* merge = dummyHead;

        while(list1 && list2){

            if(list1 != NULL && list2 != NULL){
                if(list1 -> val <= list2 -> val){
                    merge -> next = list1;
                    merge = list1;
                    list1 = list1 -> next;
                }

                else{
                    merge -> next = list2;
                    merge = list2;
                    list2 = list2 -> next;
                }

                //merge = merge -> next;
            }

        }

        if(list1 != NULL){
            merge -> next = list1;
        }

        if(list2 != NULL){
            merge -> next = list2;
        }

        return dummyHead -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();
        for(int i = 1; i < n; i++){
            lists[0] = mergeTwoLists(lists[0] , lists[i]);
        }

        return lists[0];
    }
};