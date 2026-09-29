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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next=head;
        head->next =NULL;
        return newhead;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode*pro=head->next;
        ListNode*noob=head;
        while(pro->next!=NULL){
            pro=pro->next;
            noob=noob->next;
            if(pro->next!=NULL){
                pro=pro->next;
            }
        }
        return noob;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        ListNode*mid=middleNode(head);//its giving one less than the middle
        ListNode*newH=mid->next;
        mid->next=NULL;
        newH=reverseList(newH);
        ListNode*t1=head->next;
        ListNode*t2=newH->next;
        while(head!=NULL && newH!=NULL){
            head->next=newH;
            newH->next=t1;
            head=t1;
            if(head!=NULL)t1=head->next;
            newH=t2;
            if(newH!=NULL)t2=newH->next;
        }

    }
};