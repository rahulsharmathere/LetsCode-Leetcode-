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
    ListNode* findKthNode(ListNode* head,int k){
        ListNode* temp=head;
        if(head==NULL || k<=1)return head;
        while(--k && temp){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* forw=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if( head==NULL || k<=1) return head;
        ListNode*kth=findKthNode(head,k);
        if(kth==NULL) return head;
        ListNode*nextGroup=kth->next;
        kth->next=NULL;   
        ListNode* newHead=reverse(head);
        head->next=reverseKGroup(nextGroup,k);

        return newHead;
    }
};