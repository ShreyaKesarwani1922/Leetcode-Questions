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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases easily (e.g., removing the head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Advance fast pointer n + 1 steps so that slow stops right before the target node
        for (int i = 0; i <= n; i++) {
            if (fast == nullptr) return head; // Safety check if n is greater than list length
            fast = fast->next;
        }

        // Move both fast and slow until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the target node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Free memory (good practice, optional for LeetCode)
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up dummy node to prevent memory leaks
        
        return newHead;
    }
};