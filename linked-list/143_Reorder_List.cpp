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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;

        while (curr != nullptr) {
            nextNode = curr->next;  // 1. Save the next node
            curr->next = prev;      // 2. Reverse the current node's pointer
            prev = curr;            // 3. Move prev one step forward
            curr = nextNode;        // 4. Move curr one step forward
        }

        return prev;  // prev becomes the new head of the reversed list
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* head2 = slow->next;
        slow->next = nullptr;
        head2 = reverseList(head2);


        ListNode* head1 = head;
        while (head2) {
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;

            head1->next = head2;
            head2->next = next1;

            head1 = next1;
            head2 = next2;                 
        }
    }
};
