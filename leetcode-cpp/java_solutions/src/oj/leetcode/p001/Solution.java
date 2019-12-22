package oj.leetcode.p001;

import java.util.HashMap;
import java.util.Map;

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
 */
/**
 * Created by clpsz on 2016/9/12.
 */
public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[]{0, 0};
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            int sup_target = target - n;
            if (map.containsKey(sup_target)) {
                res[0] = i;
                res[1] = map.get(sup_target);
                break;
            } else {
                map.put(n, i);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] given = new int[]{7, 11, 15, 2};
        int[] res = solution.twoSum(given, 9);

        for (int n : res) {
            System.out.println(n);
        }
    }
}
