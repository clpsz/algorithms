package oj.leetcode.p080;

/**
 * Created by clpsz on 2016/9/12.
 */
public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length <= 2) {
            return nums.length;
        }
        boolean twoSame = false;

        int lastUniq = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[lastUniq]) {
                nums[++lastUniq] = nums[i];
                twoSame = false;
            } else if (!twoSame) {
                nums[++lastUniq] = nums[i];
                twoSame = true;
            }
        }

        return lastUniq + 1;
    }


    public static void main(String[] args) {
        int[] given = new int[]{1,1,1,2,2,2,3};

        Solution solution = new Solution();
        int res = solution.removeDuplicates(given);
        System.out.println(res);
    }
}
