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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        for(auto list : lists){

            while(list){
                values.push_back(list -> val);
                list = list -> next;
            }
        }

        sort(values.begin() , values.end());


        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int n = values.size();
        for(int i = 0; i < n; i++){

            ListNode* newnode = new ListNode(values[i]);
            curr -> next = newnode;
            curr = curr -> next;
        }

        return dummy -> next;
    }
};