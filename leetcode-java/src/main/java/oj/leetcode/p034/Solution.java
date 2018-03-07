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
        int[] res = new int[]{-1,-1};
        res[0] = searchLowerMatchIndex(nums, target);
        res[1] = searchUpperMatchIndex(nums, target);
        return res;
    }


    //比target小的数中最大的值得索引，如果target不存在，则返回-1
    private int searchLowerMatchIndex(int[] nums, int target) {
        int lo = 0;
        int hi = nums.length-1;

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] > target) hi = mid-1;
            else if (nums[mid] < target) lo = mid+1;
            else {
                if (mid == 0 || nums[mid-1] != target)
                    return mid;
                else
                    hi = mid-1;
            }
        }

        return -1;
    }

    private int searchUpperMatchIndex(int[] nums, int target) {
        int lo = 0;
        int hi = nums.length-1;

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] > target) hi = mid-1;
            else if (nums[mid] < target) lo = mid+1;
            else {
                if (mid == nums.length-1 || nums[mid+1] != target)
                    return mid;
                else
                    lo = mid+1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] given = new int[]{5, 7, 7, 8, 8, 10};
        Solution solution = new Solution();
        int[] res = solution.searchRange(given, 8);
        for (int n : res) {
            System.out.println(n);
        }
    }
}
