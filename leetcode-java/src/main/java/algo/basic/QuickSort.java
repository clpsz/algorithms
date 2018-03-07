package algo.basic;

/**
 * 超级简洁的快速排序算法，我第一次看到的时候惊呆了
 * Created by clpsz on 2016/9/14.
 */
public class QuickSort {
    public void sort(int[] nums) {
        sort(nums, 0, nums.length-1);
    }

    private void sort(int[] nums, int lo, int hi) {
        if (lo >= hi) return;
        int p = partition(nums, lo, hi);
        sort(nums, lo, p-1);
        sort(nums, p+1, hi);
    }

    private int partition(int[] nums, int lo, int hi) {
        if (lo >= hi) return -1;

        int i = lo+1;
        int j = lo+1;

        while (j <= hi) {
            if (nums[j] < nums[lo]) {
                swap(nums, j, i);
                i++;
            }

            j++;
        }
        swap(nums, lo, i-1);

        return i-1;
    }

    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public static void main(String[] args) {
        int[] given = new int[]{3,2,1,5,6,4};

        QuickSort quickSort = new QuickSort();
        quickSort.sort(given);

        for (int n : given) {
            System.out.println(n);
        }
    }
}
