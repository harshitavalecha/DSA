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
//  middle 
ListNode* findmiddle(ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;
ListNode* slow=head;
ListNode*fast=head->next;
while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
}
return slow;
}
//  merge two list
// ListNode* mergetwolist(ListNode* t1,ListNode* t2){
//     ListNode* dummynode= new ListNode(-1);
//     ListNode* temp=dummynode;
//    while(t1!=NULL && t2!=NULL){
//     if(t1->val<t2->val){
        
//         temp->next=t1;
//         t1=t1->next;
//     }
//     else{
        
//         temp=temp->next;
//         t2=t2->next;
//     }
//     temp=temp->next;
//    }
//     if(t1!=NULL){
//         temp->next=t1;

//     }
//     else{
//         temp->next=t2;
//     }
   
//    return dummynode->next;
// }
    ListNode* mergetwolist(ListNode* t1, ListNode* t2) {
    ListNode* dummynode = new ListNode(-1);
    ListNode* temp = dummynode;

    while (t1 != NULL && t2 != NULL) {
        if (t1->val < t2->val) {
            temp->next = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;   // ✅ MISSING LINE
            t2 = t2->next;
        }
        temp = temp->next;     // ✅ move temp AFTER linking
    }

    // attach remaining nodes
    if (t1 != NULL)
        temp->next = t1;
    else
        temp->next = t2;

    return dummynode->next;
}

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
         ListNode*middle=findmiddle(head);
        ListNode*right=middle->next;
        middle->next=NULL;
        ListNode*left=head;
        left=sortList(left);
        right=sortList(right);
        return mergetwolist(left,right);
  
    }
};