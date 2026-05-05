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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        if(k==0) return head;
        ListNode* count=head;
        int size=0;
        while(count!=NULL){
            size++;
            count=count->next;
        }

        k=k%size;
        if(k==0) return head;
        int index=size-k-1;

        ListNode* temp=head;
        int i=0;
        while(i!=index){
            temp=temp->next;
            i++;
        }
        ListNode* endptr=temp;
        ListNode* headptr=temp->next;
        temp=temp->next;
        endptr->next=NULL;

        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;

        return headptr;

    }
};