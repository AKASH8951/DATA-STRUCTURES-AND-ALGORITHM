/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {t}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;

        while(temp != NULL){
            size += 1;
            temp = temp -> next;
        }
         if(size == n){
            return head->next;
        }

        ListNode* prev = head;
        for(int i = 1 ; i < (size - n); i++){
            prev = prev -> next;
        }
        prev -> next = prev -> next -> next;
        return head;
    }
    
};