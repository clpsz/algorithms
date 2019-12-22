package oj.leetcode.p347;


import java.util.*;

public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> res = new ArrayList<>();
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int n : nums) {
                countMap.put(n, countMap.getOrDefault(n, 0) + 1);
        }

        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((o1, o2) -> o2.getValue() - o1.getValue());
        pq.addAll(countMap.entrySet());

        for (int i = 0; i < k; i++) {
            res.add(pq.poll().getKey());
        }

        return res;
    }

    public List<Integer> topKFrequentOpt(int[] nums, int k) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int n : nums) {
            countMap.put(n, countMap.getOrDefault(n, 0) + 1);
        }

        List<Integer>[] bucket = new List[nums.length + 1];
        for (Integer key : countMap.keySet()) {
            int frequency = countMap.get(key);
            if (bucket[frequency] == null) {
                bucket[frequency] = new ArrayList<>();
            }
            bucket[frequency].add(key);
        }

        ArrayList<Integer> res = new ArrayList<>();
        for (int i = nums.length; i >= 0 && res.size() < k; i--) {
            if (bucket[i] != null) {
                res.addAll(bucket[i]);
            }
        }

        return res.subList(0, k);
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        int[] nums = new int[]{1,1,1,2,3,3,3,3};

        List<Integer> res = s.topKFrequentOpt(nums, 3);

        for (Integer n : res) {
            System.out.println(n);
        }
    }
}
