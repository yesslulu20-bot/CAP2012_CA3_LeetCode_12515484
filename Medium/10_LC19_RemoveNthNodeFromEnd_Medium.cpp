
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Create a dummy node
        ListNode dummy(0);
        dummy.next = head;

        // Create two pointers
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move fast pointer ahead by n + 1 positions
        for (int i = 0; i <=n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the required node
        ListNode* temp = slow->next;
        slow->next =temp->next;

        // Return the updated linked list
        return dummy.next;
    }
};

