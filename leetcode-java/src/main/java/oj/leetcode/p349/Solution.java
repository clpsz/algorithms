package oj.leetcode.p349;


import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> setRes = new HashSet<>();

        for (int num : nums1) {
            set1.add(num);
        }
        for (int num: nums2) {
            if (set1.contains(num)) {
                setRes.add(num);
            }
        }

        int[] res = new int[setRes.size()];
        int index = 0;
        for(int n : setRes) {
            res[index++] = n;
        }

        return res;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums1 = {4, 2, 3, 1};
        int[] nums2 = {2, 2, 3, 4, 4};

        int[] res = s.intersection(nums1, nums2);
        for (int n : res) {
            System.out.println(n);
        }
    }
}
