class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reversing second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr != NULL){

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        slow = prev;

        int maxi = 0;

        ListNode* temp = head;

        while(slow != NULL){

            int sum = slow->val + temp->val;

            maxi = max(maxi, sum);

            slow = slow->next;
            temp = temp->next;
        }

        return maxi;
    }
};