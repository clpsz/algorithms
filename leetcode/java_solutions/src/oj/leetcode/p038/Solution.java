package oj.leetcode.p038;

/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
 */
/**
 * Created by clpsz on 2016/9/7.
 */
public class Solution {
    public String countAndSay(int n) {
        String s = "1";
        String res = "1";
        while (--n > 0) {
            res = generate(s);
            s = res;
        }

        return res;
    }

    private String generate(String seq) {
        int count = 0;
        char ch = '*';


        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < seq.length(); i++) {
            if (i == 0) {
                ch = seq.charAt(i);
                count = 1;
                continue;
            }

            if (ch == seq.charAt(i)) {
                count++;
            } else {
                sb.append(count);
                sb.append(ch);
                ch = seq.charAt(i);
                count = 1;
            }
        }
        if (count != 0) {
            sb.append(count);
            sb.append(ch);
        }


        return sb.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.countAndSay(5));
    }
}
