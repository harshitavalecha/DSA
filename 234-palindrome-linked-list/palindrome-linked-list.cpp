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

ListNode* reverselist(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    if(head==NULL) return NULL;
    while (curr != NULL) {
        ListNode* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
         ListNode *slow=head;
          ListNode *fast=head;
          while(fast!=NULL && fast->next!=NULL)
          {
            slow=slow->next;
            fast=fast->next->next;
          }
     
           ListNode *newhead= reverselist(slow);
            ListNode *first=head;
             ListNode *second=newhead;
             while(second!=NULL){
                if(first->val!=second->val){
                    reverselist(newhead);
                    return false;
                }
                else{
                    first=first->next;
                    second=second->next;
                    
                }
                // reverselist(newhead);
                
             }
             reverselist(newhead);
             return true;
    }
};