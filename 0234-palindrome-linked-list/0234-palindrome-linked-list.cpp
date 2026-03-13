class Solution {
public:

    ListNode* Reverse(ListNode* h){
        ListNode* curr = h;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        ListNode* h = Reverse(mid);

        ListNode* temp = head;

        while(h != NULL){
            if(temp->val != h->val){
                return false;
            }

            temp = temp->next;
            h = h->next;
        }

        return true;
    }
};