class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy heads
        ListNode* lessDummy = new ListNode(0);
        ListNode* greaterDummy = new ListNode(0);

        ListNode* less = lessDummy;
        ListNode* greater = greaterDummy;

        // Traverse original list
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Important: terminate greater list
        greater->next = nullptr;

        // Connect less and greater lists
        less->next = greaterDummy->next;

        return lessDummy->next;
    }
};
