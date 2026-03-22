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
        //without using map 
        if(head==NULL)return NULL;
        Node* temp=head;
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            Node* forw=temp->next;
            temp->next=newNode;
            newNode->next=forw;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            if (temp->random != NULL)
                temp->next->random = temp->random->next;
            temp=temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node*copyTail=dummy;
        temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            temp->next = copyNode->next;  // restore original next
            copyTail->next = copyNode;    // build copied list
            copyTail = copyNode;
            temp = temp->next;
        }
        return dummy->next;
    }
};