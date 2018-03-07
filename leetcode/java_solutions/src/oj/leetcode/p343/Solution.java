package oj.leetcode.p343;


public class Solution {
    /*
     You're making it pretty complicated. Simplifying 2*(f-2) >= f to f >= 4
     shows that breaking any factor f >= 4 into factors 2 and f-2 won't hurt the product.
     There, done :-P

     Edit: Rephrased, maybe that's better:
     If an optimal product contains a factor f >= 4, then you can replace it with factors 2 and f-2 without losing optimality,
     as 2*(f-2) = 2f-4 >= f. So you never need a factor greater than or equal to 4,
     meaning you only need factors 1, 2 and 3 (and 1 is of course wasteful and you'd only use it for n=2 and n=3, where it's needed).

     上面这段字的大意说，任意大于4的因子，假设是n，都可以被转换为 n * (n-2) ，所以只需要 1 2 3 三个因子，1是显然不需要的，所以只需要用2和3做因子即可
     但是优先取3，因为2+2+2=3+3，但是2*2*2<3*3
     */
    public int integerBreak(int n) {
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }

        int product = 1;
        while (n > 4) {
            product *= 3;
            n -= 3;
        }

        return product * n;
    }


    /*
     还有一个优化的方案，思路是根据是3的整数倍，还是整除余1，整除余2，来判断可以分出多少个3，然后取3的这么多幕次，再乘以相应个数的2
     */

    public static void main(String[] args) {
        Solution s = new Solution();

        System.out.println(s.integerBreak(5));
    }
}
