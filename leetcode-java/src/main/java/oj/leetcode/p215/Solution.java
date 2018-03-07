package oj.leetcode.p215;

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */
/**
 * Created by clpsz on 2016/9/13.
 */
public class Solution {
    //注意这里是 largest
    public int findKthLargest(int[] nums, int k) {
        return findKthNum(nums, 0, nums.length-1, nums.length-k);
    }

    /*
        k begins from 0
     */
    public int findKthNum(int[] nums, int lo, int hi, int k) {
        int pivotIndex = partition(nums, lo, hi);
        if (pivotIndex == k) {
            return nums[pivotIndex];
        } else if (pivotIndex > k) {
            return findKthNum(nums, lo, pivotIndex-1, k);
        } else {
            return findKthNum(nums, pivotIndex+1, hi, k);
        }
    }

    public int partition(int[] nums, int lo, int hi) {
        int pivot = nums[lo];
        int i = lo+1;
        int j = lo+1;
        while (j <= hi) {
            if (nums[j] <= pivot) {
                swap(nums, i, j);
                i++;
            }

            j++;
        }
        swap(nums, i-1, lo);

        return i-1;
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }



    public static void main(String[] args) {
        int[] given = new int[]{2,1};

        Solution solution = new Solution();
        int res = solution.findKthLargest(given, 1);


        System.out.println(res);
    }
}
