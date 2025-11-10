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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1)); 
        
        int startRow = 0, endRow = m - 1;
        int startCol = 0, endCol = n - 1;
        
        ListNode* temp = head;
        
        while (startRow <= endRow && startCol <= endCol && temp != NULL) {
            for (int j = startCol; j <= endCol && temp != NULL; j++) {
                ans[startRow][j] = temp->val;
                temp = temp->next;
            }
            startRow++;
            
            for (int i = startRow; i <= endRow && temp != NULL; i++) {
                ans[i][endCol] = temp->val;
                temp = temp->next;
            }
            endCol--;
            
            for (int j = endCol; j >= startCol && temp != NULL; j--) {
                ans[endRow][j] = temp->val;
                temp = temp->next;
            }
            endRow--;
            
            for (int i = endRow; i >= startRow && temp != NULL; i--) {
                ans[i][startCol] = temp->val;
                temp = temp->next;
            }
            startCol++;
        }
        
        return ans;
    }
};