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
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] matrix = new int[m][n];
        int value = 1;
        int startRow = 0, endRow = m - 1, startCol = 0, endCol = n - 1;
        while (startRow <= endRow && startCol <= endCol) {
            for (int i = startCol; i <= endCol; i++) {
                matrix[startRow][i] = (head != null) ? head.val : -1;
                if (head != null) head = head.next;
            }
            startRow++;
            for (int i = startRow; i <= endRow; i++) {
                matrix[i][endCol] = (head != null) ? head.val : -1;
                if (head != null) head = head.next;
            }
            endCol--;
            if (startRow <= endRow) {
                for (int i = endCol; i >= startCol; i--) {
                    matrix[endRow][i] = (head != null) ? head.val : -1;
                    if (head != null) head = head.next;
                }
                endRow--;
            }
            if (startCol <= endCol) {
                for (int i = endRow; i >= startRow; i--) {
                    matrix[i][startCol] = (head != null) ? head.val : -1;
                    if (head != null) head = head.next;
                }
                startCol++;
            }
        }

        return matrix;
    }
}