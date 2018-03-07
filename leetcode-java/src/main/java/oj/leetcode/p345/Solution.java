package oj.leetcode.p345;


public class Solution {
    public String reverseVowels(String s) {
        String vowels = "AEIOUaeiou"; // use hashmap to speed up
        char [] chars = s.toCharArray();

        int i = 0;
        int j = chars.length - 1;
        while (i < j) {
            while (i < j && !vowels.contains(chars[i]+"")) {
                i++;
            }
            while (i < j && !vowels.contains(chars[j]+"")) {
                j--;
            }

            char tmp = chars[i];
            chars[i] = chars[j];
            chars[j] = tmp;
            i++;
            j--;
        }

        return new String(chars);
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        String input = "Hello";

        String output = s.reverseVowels(input);

        System.out.println(output);
    }
}
