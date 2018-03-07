package oj.leetcode.p034;

/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 */
/**
 * Created by clpsz on 2016/9/14.
 */
public class Solution {
    public int[] searchRange(int[] nums, int target) {
        return null;
    }

    private int smallestIndex(int[] nums, int target) {
        int index = find(nums, 0, nums.length, target);
        if (index == -1) return -1;

        while (index > 0 && nums[index-1] == target) {
            index = smallestIndex()
        }

        return index;
    }

    private int findSmalledIndex(int[] nums, int hi, int target) {
        return 0;
    }

    private int findTargetIndex(int[] nums, int lo, int hi, int target) {

    }

    private int find(int[] nums, int lo, int hi, int target) {
        if (lo > hi) return -1;
        if (lo == hi) {
            if (nums[lo] == target) return lo;
            else return -1;
        }

        int mid = (lo+hi) / 2;
    }

    public static void main(String[] args) {
        int[] given = new int[]{5, 7, 7, 8, 8, 10};
        Solution solution = new Solution();
        int small = solution.smallestIndex(given, 7);
        System.out.println(small);
    }
}
