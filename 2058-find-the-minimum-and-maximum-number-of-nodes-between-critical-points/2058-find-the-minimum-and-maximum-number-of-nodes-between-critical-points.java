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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
          int []ans =new int[2];
          Arrays.fill(ans,-1);
          if(head==null||head.next==null||head.next.next==null)
          {
              return ans;
          }
          int count=1;        
          ListNode prev=null;
          ListNode ptr=head;
          int min1=Integer.MAX_VALUE;
          int max1=Integer.MIN_VALUE;
          int prevDist=-1;
          int minDist=Integer.MAX_VALUE;
          while(ptr.next!=null)
          {
              if(prev!=null)
              {
                  if((ptr.val>prev.val)&&(ptr.val>ptr.next.val))
                  {
                      if(prevDist==-1)
                      {
                         prevDist=count;   
                      }
                      else
                      {
                         minDist=Math.min(minDist,(count-prevDist));  
                         prevDist=count; 
                      }
                      min1=Math.min(min1,count);
                      max1=Math.max(max1,count);                      
                  }
                  else if((ptr.val<prev.val)&&(ptr.val<ptr.next.val))
                  {
                      if(prevDist==-1)
                      {
                          prevDist=count;   
                      }
                      else
                      {
                          minDist=Math.min(minDist,(count-prevDist)); 
                          prevDist=count;
                      }
                      min1=Math.min(min1,count);                      
                      max1=Math.max(max1,count);                      
                  }                  
              }
              prev=ptr;
              ptr=ptr.next;
              count++;
          }
          if(min1==Integer.MAX_VALUE||max1==Integer.MIN_VALUE||min1==max1)
          {
              return new int[]{-1,-1};
          }
          System.out.println(min1+"   "+max1);
          int maxDist=(max1-min1);          
          ans[0]=minDist;
          ans[1]=maxDist;        
          return ans;
    }
}