package oj.leetcode.p350;


import java.util.ArrayList;
import java.util.HashMap;


public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hm1 = new HashMap<>();
        ArrayList<Integer> set = new ArrayList<>();

        for (int num : nums1) {
            if (hm1.containsKey(num)) {
                hm1.put(num, hm1.get(num) + 1);
            } else {
                hm1.put(num, 1);
            }
        }

        for (int num : nums2) {
            if (hm1.containsKey(num) && hm1.get(num) > 0) {
                set.add(num);
                hm1.put(num, hm1.get(num) - 1);
            }
        }

        int[] res = new int[set.size()];
        int index = 0;
        for(int n : set) {
            res[index++] = n;
        }

        return res;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums1 = {4, 4, 4, 4};
        int[] nums2 = {2, 2, 3, 4, 4};

        int[] res = s.intersect(nums1, nums2);
        for (int n : res) {
            System.out.println(n);
        }
    }
}
