class Solution {
    public boolean checkIfExist(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();

        for(int it: arr){
            if(mp.getOrDefault(2*it,0)>=1 || (it%2==0 && mp.getOrDefault(it/2,0)>=1)) return true;
            mp.put(it, mp.getOrDefault(it,0)+1);
        }
        return false;
    }
}