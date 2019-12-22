package oj.leetcode.p028;


/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

/**
 * Created by clpsz on 2016/9/4.
 */
public class Solution {
    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null) {
            return -1;
        }
        int haystackLength = haystack.length();
        int needleLength = needle.length();

        if (haystackLength < needleLength) {
            return -1;
        }

        for (int i = 0; i <= haystackLength - needleLength; i++) {
            String checkStr = haystack.substring(i, i+needleLength);
            if (checkStr.equals(needle)) {
                return i;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.strStr("abcdef", "def"));
    }
}
