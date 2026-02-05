class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
if(head==NULL) return NULL;
ListNode*slow=head;
ListNode*fast=head;
for(int i=0;i<n;i++)
{
    fast= fast->next;
}
if(fast==NULL) {
    ListNode*newhead= head->next;
    delete(head);
    return newhead;
}
while(fast->next != NULL)
{
    slow= slow->next;
    fast=fast->next;      
      }           
    ListNode*nodetodelete=slow->next;
    slow->next=slow->next->next;
    delete(nodetodelete);

   return head;
    }
  };