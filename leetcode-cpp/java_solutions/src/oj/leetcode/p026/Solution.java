package oj.leetcode.p026;

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 */
/**
 * Created by clpsz on 2016/9/12.
 */
public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0 || nums.length == 1) {
            return nums.length;
        }

        int lastUniqIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[lastUniqIndex]) {
                nums[++lastUniqIndex] = nums[i];
            }
        }
        return lastUniqIndex+1;
    }

    public static void main(String[] args) {
        int[] given = new int[]{1,1,2,2};

        Solution solution = new Solution();
        int res = solution.removeDuplicates(given);
        System.out.println(res);
    }
}
