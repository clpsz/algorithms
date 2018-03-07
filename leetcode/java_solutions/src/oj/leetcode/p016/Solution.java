package oj.leetcode.p016;

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

import java.util.Arrays;

/**
 * Created by clpsz on 2016/9/12.
 */
public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int length = nums.length;
        int res = nums[0] + nums[1] + nums[2];

        Arrays.sort(nums);

        for (int i = 0; i < length - 2; i++) {
            int j = i + 1;
            int k = length - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                }

                if (Math.abs(sum - target) < Math.abs(res - target)) {
                    res = sum;
                }

                if (sum > target) --k;
                else ++j;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] given = new int[]{-3,-2,-5,3,-4};

        Solution solution = new Solution();
        int res = solution.threeSumClosest(given, 1);

        System.out.println(res);
    }
}
