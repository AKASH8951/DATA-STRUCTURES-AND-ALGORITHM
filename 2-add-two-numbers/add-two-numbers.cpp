class Solution {
public:
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {

        ListNode *curr1 = first, *curr2 = second;

        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        int sum = 0, carry = 0;

        while (curr1 && curr2) {
            sum = curr1->val + curr2->val + carry;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            carry = sum / 10;

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while (curr1) {
            sum = curr1->val + carry;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            carry = sum / 10;

            curr1 = curr1->next;
        }

        while (curr2) {
            sum = curr2->val + carry;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            carry = sum / 10;

            curr2 = curr2->next;
        }

        if (carry) {
            tail->next = new ListNode(carry);
        }

        return head->next;
    }
};