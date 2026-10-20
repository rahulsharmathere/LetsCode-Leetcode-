class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        second = reverse(second);

        ListNode* first = head;

        while (second != NULL) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};