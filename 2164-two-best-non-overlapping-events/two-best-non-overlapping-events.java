import java.util.*;

class Solution {
    public int maxTwoEvents(int[][] events) {
        int n = events.length;
        // Sort the events array based on the start time
        Arrays.sort(events, Comparator.comparingInt(a -> a[0]));
        
        int[] mx = new int[n];
        // Initialize mx array with the last event's value
        mx[n - 1] = events[n - 1][2];
        
        // Populate mx array with the maximum value for each event from the end
        for (int i = n - 2; i >= 0; i--) {
            mx[i] = Math.max(events[i][2], mx[i + 1]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int end = events[i][1];
            int value = events[i][2];
            
            // Binary search to find the first event whose start time is greater than `end`
            int indx = upperBound(events, end);
            
            // Calculate the maximum sum
            ans = Math.max(ans, value + (indx < n ? mx[indx] : 0));
        }
        
        return ans;
    }
    
    // Helper method to implement the upper_bound functionality in Java
    private int upperBound(int[][] events, int target) {
        int low = 0, high = events.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (events[mid][0] > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
