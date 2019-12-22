package oj.leetcode.p027;

/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
 */
/**
 * Created by clpsz on 2016/9/7.
 */
public class Solution {
    public int removeElement(int[] nums, int val) {
        int length = nums.length;

        int curIndex = 0;
        for (int i = 0; i < length; i++) {
            if (nums[i] != val) {
                nums[curIndex] = nums[i];
                curIndex++;
            }
        }

        return curIndex;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = new int[]{1,2,3,4,5,5,5,5};
        int remain = solution.removeElement(nums, 5);

        System.out.println("remain: " + String.valueOf(remain));
        for (int i : nums) {
            System.out.println(i);
        }


    }
}
