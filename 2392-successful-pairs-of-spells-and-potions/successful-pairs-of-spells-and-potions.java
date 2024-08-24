   import java.util.*;
class Solution {


public int[] successfulPairs(int[] spells, int[] potions, long success) {
    Arrays.sort(potions);
    int n = spells.length;
    int m = potions.length;
    int[] ans = new int[n];

    for (int i = 0; i < n; i++) {
        long mn = (success + spells[i] - 1) / spells[i];
        int indx = binarySearch(potions, mn);
        ans[i] = m - indx;
    }

    return ans;
}

// Custom binary search to find the lower bound index
private int binarySearch(int[] potions, long value) {
    int left = 0, right = potions.length;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (potions[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}


}