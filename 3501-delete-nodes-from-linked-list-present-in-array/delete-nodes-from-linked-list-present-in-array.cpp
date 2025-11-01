class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> mpp(nums.begin(), nums.end());

        while (head && mpp.find(head->val)!=mpp.end())
            head = head->next;

        ListNode* curr = head;
        while (curr && curr->next) {
            while (curr->next && mpp.find(curr->next->val)!=mpp.end()) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};