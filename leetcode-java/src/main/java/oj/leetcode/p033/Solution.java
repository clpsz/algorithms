package oj.leetcode.p033;

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
 */
/**
 * Created by Administrator on 2016/9/16.
 */
public class Solution {
    //总有一半是顺序正确的，根据顺序正确的那一半来判断
    public int search(int[] nums, int target) {
        int lo = 0;
        int hi = nums.length - 1;

        //循环终止的时候，lo+1=hi，lo=hi的情况除外
        while (lo+1 < hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] == target) return mid;
            else if (nums[lo] < nums[mid]) {
                if (target >= nums[lo] &&  target < nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        if (nums[lo] == target) return lo;
        else if (nums[hi] == target) return hi;

        return -1;
    }

    public static void main(String[] args) {
        int[] given = new int[]{3,1};
        Solution solution = new Solution();
        int res = solution.search(given, 1);
        System.out.println(res);
    }
}
