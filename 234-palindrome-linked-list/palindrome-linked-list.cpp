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
    bool isPalindrome(ListNode* head) {
        vector <int> front;
        ListNode* temp = head;

        while(temp != NULL){
            front.push_back(temp -> val);
            temp = temp->next;
        }

        vector <int> back(front.begin(),front.end());
        reverse(back.begin() , back.end());
        
        
            if(front == back)
            return true;

            
        
        return false;
    }
};