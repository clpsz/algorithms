package oj.leetcode.p044;

/**
 * Created by clpsz on 2016/9/5.
 */
/*
    需要考虑这样的一个便利条件
    1，如果pattern是以*起始的，那么可以丢掉string里面前面的任意长度的字符，
       即只要pattern里面*后面的字符串能匹配string的任意一个后缀，则match
    2，如果pattern里面有多个*，那么对于第二个*前的部分，只要配置string里面最短的字符串即可，
       因为如果可以匹配，那么第二个*及其后面的部分一定可以匹配到string后一个后缀，
       且第二个*前面的部分一定可以匹配到string的一个前缀，
       那么在前缀跟后缀蹭加任意个字符，因为第二个*可以吃掉任意个数的字符
    3，连续多个*可以合并为一个处理
 */
public class Solution {
    public boolean isMatch(String s, String p) {
        int sLen = s.length();
        int pLen = p.length();

        int si = 0;
        int pi = 0;
        int pStar = -1;
        int sStar = 0;
        while (si < sLen) {
            if (pi < pLen && (s.charAt(si) == p.charAt(pi) || p.charAt(pi) == '?')) {
                si++;
                pi++;
            } else if (pi < pLen && p.charAt(pi) == '*') {
                pStar = pi;
                sStar = si;
                pi++;
            } else if (pStar != -1) {
                pi = pStar + 1;
                sStar++;
                si = sStar;
            } else {
                return false;
            }
        }

        while (pi < pLen && p.charAt(pi) == '*') {
            pi++;
        }

        return pi == pLen;
    }


//
//    public boolean isMatch(String s, String p) {
//        return comparePosition(s, 0, p, 0);
//    }
//
//    private boolean isAllAster(String p) {
//        if (p == null || p.length() == 0) return false;
//
//        for (int i = 0; i < p.length(); i++) {
//            if (p.charAt(i) != '*') return false;
//        }
//
//        return true;
//    }
//
//    private boolean comparePosition(String s, int sp, String p, int pp) {
//        if (sp == s.length() || pp == p.length()) {
//            if (sp == s.length() && pp == p.length())
//                return true;
//            else if (isAllAster(p.substring(pp, p.length())))
//                return true;
//            else
//                return false;
//        }
//
//        if (p.charAt(pp) == '*') {
//            while (p.charAt(pp) == '*') {
//                pp++;
//                if (pp == p.length()) return true;
//            }
//
//            while (sp < s.length() && !comparePosition(s, sp, p, pp)) {
//                sp++;
//            }
//
//            //如果sp < s.length() 表示是因为 comparePosition(s, sp, p, pp) 为true而退出循环的，即找到了匹配的字符串
//            return sp < s.length();
//        } else if (p.charAt(pp) == '?') {
//            return comparePosition(s, sp+1, p, pp+1);
//        } else if (s.charAt(sp) == p.charAt(pp)) {
//            return comparePosition(s, sp+1, p, pp+1);
//        } else {
//            return false;
//        }
//    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isMatch("ho", "ho**"));
    }
}


