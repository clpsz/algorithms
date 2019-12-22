package oj.leetcode.p357;

import java.lang.Math;

public class Solution {
    /*蛮力法，依次统计:
        最高位是1的情况下，还有多少种情况
        最高位是2的情况下，不有多少种情况
        ...
        最高位是9的情况下，还有多少种情况

        这里面有递归的概念，有计算使用了1的情况下，还有多少种情况的时候，也用同样的方法，只是1不可以再使用

        大于10位的整数一定有重复的数字
     */
    public int countNumbersWithUniqueDigits(int n) {
        int[] used = new int[10];

        if (n > 10) {
            return countNumbersWithUniqueDigits(10);
        }
        long max = (long)Math.pow(10, n);

        int count = 1; // x == 0
        for (int i = 1; i < 10; i++) {
            used[i] = 1;
            count += countWithUsed(i, max, used);
            used[i] = 0;
        }
        return count;
    }

    /*
    cur 当前统计的数
    max 最大的合法的数
    used 已经使用掉的数字
     */
    private int countWithUsed(long cur, long max, int[] used) {
        int count = 0;
        if (cur < max) {
            count++;
        } else {
            return count;
        }

        for (int i = 0; i < 10; i++) {
            if (used[i] != 1) {
                used[i] = 1;
                long next = cur * 10 + i;
                count += countWithUsed(next, max, used);
                used[i] = 0;
            }
        }

        return count;
    }

    /*
    这个其实是一个排列组合的问题
    10位以上跟10位相同
    10位以下，比如n位，就是从1位到n位长度的数的总数加起来
    1位 10
    2位 10 + 9*9 = 91
    3位 10 + 9*9 + 9*9*8 = 739
    4位 10 + 9*9 + 9*9*8 + 9*9*8*7 = ???

    每次计算最后一组数字，加起来即可，使用动态规划的思想，下一个长度的最后一组数字的计算可以依赖于上一个长度
     */
    public int countNumbersWithUniqueDigitsOpt(int n) {
        if (n == 0) {
            return 1;
        }

        int count = 10; //有一位的时候的总数
        int uniqueDigits = 9; //当前有多少个 unique number
        int available = 9; //还可以使用的数字，把可以使用的数字看作资源

        //依次算2位数字个数，3位数字个数...
        while (n-- > 1 && available > 0) {//从当前数字一直计算到1
            uniqueDigits = uniqueDigits * available;
            count += uniqueDigits;
            available--;
        }

        return count;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int res = s.countNumbersWithUniqueDigitsOpt(3);

        System.out.println(res);
    }
}
