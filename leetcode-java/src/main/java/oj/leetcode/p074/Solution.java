package oj.leetcode.p074;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */
/**
 * Created by Administrator on 2016/9/16.
 */
public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null) return false;
        int rows = matrix.length;
        int cols = matrix[0].length;

        int rlo = 0;
        int rhi = rows - 1;

        //找到所在的行
        while (rlo <= rhi) {
            int mid = rlo + (rhi-rlo)/2;
            if (matrix[mid][0] > target) rhi = mid - 1;
            else if (matrix[mid][0] < target) rlo = mid + 1;
            else return true;
        }
        if (rlo > rhi && rhi >= 0) rlo = rhi;

        int clo = 0;
        int chi = cols - 1;
        while (clo <= chi) {
            int mid = clo + (chi-clo)/2;
            if (matrix[rlo][mid] > target) chi = mid - 1;
            else if (matrix[rlo][mid] < target) clo = mid + 1;
            else return true;
        }

        return false;
    }

    public static void main(String[] args) {
        int [][]given = new int[][]{
                {1}
        };
//        int [][]given = new int[][]{
//                {1,   3,  5,  7},
//                {10, 11, 16, 20},
//                {23, 30, 34, 50}
//        };

        Solution solution = new Solution();
        boolean res = solution.searchMatrix(given, 0);
        System.out.println(res);
    }
}
