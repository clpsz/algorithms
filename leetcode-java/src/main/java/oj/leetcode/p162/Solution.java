package oj.leetcode.p162;

/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 */
/**
 * Created by Administrator on 2016/9/16.
 */
public class Solution {
    //因为两边都是-∞，所以必然有一个peak
    //如果一个位置index，nums[index-1] > nums[index]，则其左边必然有一个peak
    public int findPeakElement(int[] nums) {
        int lo = 0;
        int hi = nums.length-1;

        while (lo+1 < hi) {
            int mid = lo + (hi-lo)/2;
            //相邻的数不相等
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if (nums[mid] < nums[mid-1]) hi = mid;
            else lo = mid;
        }

        return nums[lo] > nums[hi] ? lo : hi;
    }

    public static void main(String[] args) {
        int []given = new int[]{1, 2, 3, 1};

        Solution solution = new Solution();
        int res = solution.findPeakElement(given);
        System.out.println(res);
    }
}
