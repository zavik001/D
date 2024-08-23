import java.util.*;

public class Main {
    public static int removeDuplicates(int[] nums) {
        if (nums.length == 1) {
            return 1;
        }
        
        int left = 0;
        int prev = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == prev) {
                left = i;
            }
        }

        return left;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 2, 2, 3 };
        System.out.println(removeDuplicates(arr));
    }
}