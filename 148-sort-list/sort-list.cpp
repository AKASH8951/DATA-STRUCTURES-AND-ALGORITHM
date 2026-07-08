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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast!=NULL && fast-> next !=NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = NULL; // Split the list

        return slow; // Right half
    }
    ListNode* merge(ListNode* left , ListNode *right) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while(left && right){

            if(left->val <= right->val) {
                tail -> next = left;
                left = left -> next;
            }
            else{
                tail -> next = right;
                right = right -> next;
            }
            tail = tail -> next;
        }
        if(left)
            tail -> next = left;

        if(right)
            tail -> next = right;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head){

        if(head==NULL || head -> next == NULL)
            return head;

        ListNode* rightHead = findMid(head);

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return merge(left , right);
    }
};