class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};

        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr) {
            return result;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;
        int firstCP = -1;
        int prevCP = -1;
        int minDist = INT_MAX;

        while (curr->next != nullptr) {
            ListNode* next = curr->next;

            // Check whether curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {
                if (firstCP == -1) {
                    firstCP = pos;
                } else {
                    minDist = min(minDist, pos - prevCP);
                }

                prevCP = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        // Need at least two critical points
        if (firstCP != -1 && prevCP != firstCP) {
            result[0] = minDist;
            result[1] = prevCP - firstCP;
        }

        return result;
    }
};

