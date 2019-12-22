package oj.leetcode.p015;

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by clpsz on 2016/9/12.
 */
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        int length = nums.length;
        if (length < 3) {
            return res;
        }

        Arrays.sort(nums);

        for (int i = 0; i < length - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            //只要保证最小的那个数字不同，则整个组合就不同
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int j = i + 1;
            int k = length - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));

                    ++j;
                    while (j < k && nums[j] == nums[j-1]) {
                        ++j;
                    }

                    --k;
                    while (k > j && nums[k] == nums[k+1]) {
                        --k;
                    }
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] given = new int[]{-1, 0, 1, 2, -1, -4};

        Solution solution = new Solution();
        List<List<Integer>> res = solution.threeSum(given);

        if (res == null) {
            return;
        }

        for (List<Integer> list : res) {
            for (Integer n : list) {
                System.out.println(n);
            }
            System.out.println();
        }
    }
}
