class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue(Collections.reverseOrder());
        for(int h: happiness){
            pq.add(h);
        }
        long ans = 0;
        long i = 0;
        while(!pq.isEmpty() && k>0){
            if(pq.peek()-i>0){
                ans += pq.peek()-i;
                i++;k--;
            }else break;
            pq.poll();
        }
        return ans;
    }
}