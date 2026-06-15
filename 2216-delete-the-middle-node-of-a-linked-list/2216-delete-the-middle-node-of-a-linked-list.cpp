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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            return NULL;
        }
        int n=0;
        ListNode* ptr=head;
        while(ptr!=NULL){
            ptr=ptr->next;
            n++;
        }
        int mid=n/2;
        
        ListNode* point=head;
        mid--;
        while(mid!=0){
            point=point->next;
            mid--;
        }
        ListNode* temp=point->next;
        point->next=temp->next;

        return head;;
    }
};