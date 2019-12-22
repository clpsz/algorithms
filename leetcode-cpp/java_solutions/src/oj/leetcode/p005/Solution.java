package oj.leetcode.p005;

/**
 * Created by clpsz on 2016/9/4.
 */
public class Solution {
    public String longestPalindrome(String s) {
        String lp = null;

        int sLength = s.length();
        for (int i = 0; i < sLength; i++) {
            String longest1 = longestPalindromeFrom(s, i, i);
            lp = getLongestBetween(lp, longest1);
        }

        for (int i = 0; i < sLength - 1; i++) {
            String longest1 = longestPalindromeFrom(s, i, i+1);
            lp = getLongestBetween(lp, longest1);
        }

        return lp;
    }

    private String getLongestBetween(String cur, String newStr) {
        if (cur == null) {
            return newStr;
        }

        if (newStr == null) {
            return cur;
        }

        if (cur.length() >= newStr.length()) {
            return cur;
        }

        return newStr;
    }

    private String longestPalindromeFrom(String s, int left, int right) {
        int sLength = s.length();
        int i, j;
        for (i = left, j = right; i >= 0 && j < sLength; i--, j++) {
            if (s.charAt(i) != s.charAt(j)) {
                break;
            }
        }
        if (i >= 0 && j < sLength && s.charAt(i) == s.charAt(j)) {
            return s.substring(i, j+1);
        }

        i++;
        j--;

        if (i > j) {
            return null;
        } else {
            return s.substring(i, j+1);
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.longestPalindrome("abccbad"));
    }
}
