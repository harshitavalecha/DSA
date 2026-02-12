class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    //     // Dummy node before head
    //     ListNode dummy(0);
    //     dummy.next = head;

    //     ListNode* prev = &dummy;

    //     while (prev->next && prev->next->next) {
    //         // Nodes to be swapped
    //         ListNode* first = prev->next;
    //         ListNode* second = first->next;

    //         // Swapping
    //         first->next = second->next;
    //         second->next = first;
    //         prev->next = second;

    //         // Move prev forward
    //         prev = first;
    //     }

    //     return dummy.next;
    if(head==NULL || head->next==NULL) return head;
    ListNode*prev=NULL;
    ListNode*first=head;
    ListNode*second=head->next;
    while(first!=NULL && second!=NULL){
        ListNode*third=second->next;

        second->next=first;
        first->next=third;
        if(prev==NULL){
            head=second;
        }
        else{
            prev->next=second;
        }
        prev=first;
        first=third;
        if(third!=NULL){
            second=third->next;
        }
        else{
            second=NULL;
        }
    }
    return head;
    }
};
