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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        // finding the middle
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        // reversing the list
        //  ListNode*middle=slow;
        //   ListNode*curr=slow->next;
        //   while(curr!=NULL)
        //   {
        //    ListNode*prev=NULL;
        //    ListNode*front=curr->next;
        //    curr->next=prev;
        //    prev=curr;
        //    curr=front;
        //   }
         // 2. Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;   // split the list

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
          
//     join a linked list
    //    ListNode* temp = head;
    // while (temp->next != NULL) {
    //     temp = temp->next;
    // }

    // // Join list 2 at the end of list 1
    // temp->next = middle;
    
    // return ;
    // }
    ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};