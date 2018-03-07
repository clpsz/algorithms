package algo.basic;

/**
 * Created by clpsz on 2016/9/14.
 */
public class BinarySearch {
    int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) return -1;

        int length = nums.length;

        int lo = 0;
        int hi = length-1;

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) hi = mid-1;
            else lo = mid+1;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] given = new int[]{1,2,3,4,5,6,7,8,9};

        BinarySearch binarySearch = new BinarySearch();
        System.out.println(binarySearch.search(given, 12));
    }
}
