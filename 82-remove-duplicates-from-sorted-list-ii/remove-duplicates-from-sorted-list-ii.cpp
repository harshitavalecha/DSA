class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;   // last node before current block
        ListNode* curr = head;

        while (curr) {
            // check if current value is duplicated
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;

                // skip all nodes with this duplicate value
                while (curr && curr->val == dupVal) {
                    curr = curr->next;
                }

                // connect prev to the next non-duplicate node
                prev->next = curr;
            } else {
                // current node is unique
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
