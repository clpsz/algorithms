package oj.leetcode.p338;


public class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num+1];

        int step = 1;
        for (int i = 0; i <= num; i++) {
            if (i == step*2) {
                step *= 2;
            }

            if (i == 0) {
                res[i] = 0;
                continue;
            }
            res[i] = res[i - step] + 1;
        }
        return res;
    }

    //这么简洁的代码惊的我下巴都要掉下来了
    public int[] countBitsOpt(int num) {
        int[] f = new int[num + 1];
        for (int i=1; i<=num; i++) f[i] = f[i >> 1] + (i & 1);
        return f;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] res = s.countBits(10);

        for (int n : res) {
            System.out.println(n);
        }
    }
}