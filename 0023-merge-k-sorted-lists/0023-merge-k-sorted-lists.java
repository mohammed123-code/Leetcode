/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode>p=new PriorityQueue<>((a,b)->a.val-b.val);
        for(ListNode node: lists){
            if(node!=null) p.offer(node);
        }
        ListNode temp=new ListNode();
        ListNode curr=temp;
        while(!p.isEmpty()){
            ListNode node=p.poll();
            curr.next=node;
            curr=curr.next;
            if(node.next!=null) p.offer(node.next);
        }
        return temp.next;
        
    }
}