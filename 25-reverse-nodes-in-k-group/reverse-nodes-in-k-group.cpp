class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* first = new ListNode(0);
        first->next = head;
        head = first;

        ListNode *second, *prev, *curr, *front;

        while(first->next) {

            // Check whether k nodes exist
            ListNode* temp = first;
            for(int i = 0; i < k; i++) {
                temp = temp->next;
                if(temp == NULL) {
                    ListNode* dummy = head;
                    head = head->next;
                    delete dummy;
                    return head;
                }
            }

            int x = k;

            second = first->next;
            prev = first;
            curr = first->next;

            while(x--) {
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }

            first->next = prev;
            second->next = curr;

            first = second;
        }

        ListNode* dummy = head;
        head = head->next;
        delete dummy;

        return head;
    }
};