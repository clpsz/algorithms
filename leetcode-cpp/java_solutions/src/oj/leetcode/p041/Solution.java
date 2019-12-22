package oj.leetcode.p041;

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
 */
/**
 * Created by clpsz on 2016/9/7.
 */
public class Solution {
    public int firstMissingPositive(int[] nums) {
        int length = nums.length;

        if (length == 0) {
            return 1;
        }

        /*
         * 为了避免需要对nums[0]做特殊处理，把1放在nums[0]，2放在nums[1]
         * 即 i == nums[i - 1]
         */
        for (int i = 0; i < length; i++) {
            while (nums[i] > 0 && nums[i] <= length //在数组中有合适的位置
                    && nums[i] != i+1 && nums[i] != nums[nums[i] - 1] //需要进行交换，防止死循环
                    ) {
                int tmp = nums[i];
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
            }
        }

        for (int i = 0; i < length; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }

        return length + 1;
    }
    public int firstMissingPositive1(int[] nums) {
        if (nums.length == 0) {
            return 1;
        }

        if (nums.length == 1) {
            if (nums[0] == 1) {
                return 2;
            } else {
                return 1;
            }
        }

        /*
         *把正数放到正确的位置上 nums[i] == i
         */
        for (int i = 0; i < nums.length; i++) {
            while (nums[i] >= 0 && nums[i] != i && nums[i] < nums.length && nums[nums[i]] != nums[i]) {
                int tmp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }

        //先从1开始查看
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        //检查nums[0]
        if (nums[nums.length - 1] == nums[0] - 1) {
            return nums[0] + 1;
        }

        return (nums[nums.length-1] + 1);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = new int[]{2,1};
        System.out.println(solution.firstMissingPositive(nums));
    }
}
