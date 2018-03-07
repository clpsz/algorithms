package oj.leetcode.p344;


import java.util.*;

public class Solution {
    public String reverseString(String s) {
        StringBuilder sb = new StringBuilder();

        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s.charAt(i);
            sb.append(ch);
        }
        return sb.toString();
    }

    public String reverseStringOpt(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        String input = "Hello";

        String output = s.reverseStringOpt(input);

        System.out.println(output);
    }
}
