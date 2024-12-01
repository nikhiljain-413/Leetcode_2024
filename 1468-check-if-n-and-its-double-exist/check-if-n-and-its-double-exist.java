class Solution {
    public boolean checkIfExist(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int it: arr){
            mp.put(it, mp.getOrDefault(it, 0)+1);
        }
        for(int it: arr){
            if(it==2*it && mp.getOrDefault(it,0)>1) return true;
            if(it!=2*it && mp.getOrDefault(2*it,0)>=1) return true;

        }
        return false;
    }
}