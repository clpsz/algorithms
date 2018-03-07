package oj.leetcode.p240;

/**
 * Created by Administrator on 2016/9/16.
 */
public class Solution {
    //右上角到左下角，一次比较排除掉一行或一列，右上角到左下角一共m+n步，时间复杂度m+n
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null) return false;
        int i = 0;
        int j = matrix[0].length - 1;
        while (i <= matrix.length-1 && j >= 0) {
            System.out.println(i + " " + j);
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }

    public static void main(String[] args) {
        int [][]given = new int[][]{
                {1,   4,  7, 11, 15},
                {2,   5,  8, 12, 19},
                {3,   6,  9, 16, 22},
                {10, 13, 14, 17, 24},
                {18, 21, 23, 26, 30}
        };

        Solution solution = new Solution();
        boolean res = solution.searchMatrix(given, 20);
        System.out.println(res);
    }
}
