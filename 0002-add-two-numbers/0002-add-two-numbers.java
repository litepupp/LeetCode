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
        ListNode result = new ListNode();
        ListNode temp = result;
        
        int remainder = 0;
        int value = 0;
        int sum = 0;

        while (l1 != null && l2 != null) {
            value = 0;
            sum = l1.val + l2.val + remainder;
            
            if (sum >= 10) {
                remainder = 1;
                value = sum % 10;
            }
            else {
                remainder = 0;
                value = sum;
            }

            temp.val = value;
            if (l1.next != null || l2.next != null) {
                temp.next = new ListNode();
                temp = temp.next;
            }

            l1 = l1.next;
            l2 = l2.next;
        }

        while (l1 != null) {
            value = 0;
            sum = l1.val + remainder;
            if (sum >= 10) {
                remainder = 1;
                value = sum % 10;
            }
            else {
                remainder = 0;
                value = sum;
            }
            temp.val = value;
            if (l1.next != null) {
                temp.next = new ListNode();
                temp = temp.next;
            }
            l1 = l1.next;
        }

        while (l2 != null) {
            value = 0;
            sum = l2.val + remainder;
            if (sum >= 10) {
                remainder = 1;
                value = sum % 10;
            }
            else {
                remainder = 0;
                value = sum;
            }
            temp.val = value;
            if (l2.next != null) {
                temp.next = new ListNode();
                temp = temp.next;
            }
            l2 = l2.next;
        }

        if (remainder != 0) {
            temp.next = new ListNode(remainder);
        }

        return result;
    }
}
