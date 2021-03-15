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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int s1=0,s2=0;
        ListNode temp=l1;
        while(temp!=null){
            s1++;
            temp=temp.next;
        }
        temp=l2;
        while(temp!=null){
            s2++;
            temp=temp.next;
        }
        ListNode ans=solve(l1,l2,s1,s2);
        if(ans.val>=10){
            ListNode n=new ListNode(ans.val/10,ans);
            ans.val=ans.val%10;
            return n;
        }
        return ans;
    }
    public ListNode solve(ListNode l1,ListNode l2,int s1,int s2){
        if(s1==1&&s2==1){
            l1.val+=l2.val;
            return l1;
        }
        if(s1>s2){
            ListNode inter=solve(l1.next,l2,s1-1,s2);
            int a=inter.val/10;
            int b=inter.val%10;
            inter.val=b;
            l1.val+=a;
            l1.next=inter;
            return l1;
        }
        else if(s2>s1){
            ListNode inter=solve(l1,l2.next,s1,s2-1);
            int a=inter.val/10;
            int b=inter.val%10;
            inter.val=b;
            l2.val+=a;
            l2.next=inter;
            return l2;
        }
        else{
            ListNode inter=solve(l1.next,l2.next,s1-1,s2-1);
            int a=inter.val/10;
            int b=inter.val%10;
            inter.val=b;
            l2.val=l2.val+l1.val+a;
            l2.next=inter;
            return l2;
        }
        
    }
}