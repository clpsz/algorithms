package oj.leetcode.p125;

/**
 * Created by clpsz on 2016/9/4.
 */
public class Solution {
    public boolean isPalindrome(String s) {
        if (s == null) {
            return false;
        }

        s = s.toLowerCase();


        int length = s.length();

        for (int i = 0, j = length-1; i < j; i++, j--) {
            while (i<j && !Character.isLetterOrDigit(s.charAt(i))) {
                i++;
            }
            while (i<j && !Character.isLetterOrDigit(s.charAt(j))) {
                j--;
            }
            if (i >= j) {
                break;
            }

            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isPalindrome("0P"));
    }
}
