package oj.leetcode.p342;


public class Solution {
    public boolean isPowerOfFour(int num) {
        /*
        num & num-1 == 0
        表示num的比特位表示形式中只有位是1
        num & 0x55555555 == num
        表示在偶数位置上没有1（第0位，第2位...）
        所以肯定是4的幂次
         */
        return (num > 0 && (num & (num-1)) == 0 && (num & 0x55555555) == num);
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        System.out.println(s.isPowerOfFour(16));
    }
}
