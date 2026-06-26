/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        //without using map
        Node* t=head;
        Node* t2=new Node(head->val);
        Node* head2=t2;
        t=t->next;
        //step 1
        while(t!=NULL){
            t2->next=new Node(t->val);
            t2=t2->next;
            t=t->next;
        }
        //step 2 
        t=head;
        Node* tnext=NULL;
        t2=head2;
        Node* t2next=NULL;
        while(t!=NULL){
            tnext=t->next;
            t2next=t2->next;
            t->next=t2;
            t2->next=tnext;
            t=tnext;
            t2=t2next;
        }
        //step3
        t2=head2;
        t=head;
        while(t!=NULL){
            if(t->random)t2->random=t->random->next;
            else t2->random=NULL;
            t=t->next->next;
            if(t2->next)t2=t2->next->next;
        }
        //reseting next pointers
        t=head;
        t2=head2;
        while(t!=NULL){
            t->next=t2->next;
            if(t->next)t2->next=t->next->next;
            
            t=t->next;
            t2=t2->next;
        }


        return head2;
        

    }
};