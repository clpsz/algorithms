package oj.leetcode.p058;
/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
 */
/**
 * Created by clpsz on 2016/9/7.
 */
public class Solution {
    public int lengthOfLastWord(String s) {
        int count = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ') {
                if (count > 0) {
                    break;
                }
            } else {
                count++;
            }
        }

        return count;
    }


    public int lengthOfLastWordMy(String s) {
        int count = 0;
        int length = s.length();

        int end = length - 1;
        //remove appending space
        for (int i = end; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                end = i;
                break;
            }
        }

        for (int i = end; i >= 0; i--) {
            if (s.charAt(i) == ' ') break;

            count++;
        }

        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.lengthOfLastWord("aaaaaifoefiaw jfoaj   "));
    }
}
