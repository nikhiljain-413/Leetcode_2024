class Solution {
    String swap(String s, int i, int j){
        char[] chars = s.toCharArray();
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
        return new String(chars);
    }

    public int slidingPuzzle(int[][] board) {
        String target = "123450";
        int [][] directions = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();

        StringBuilder sb = new StringBuilder();
        for(int[] row: board){
            for(int num: row){
                sb.append(num);
            }
        }
        String startState = sb.toString();
        visited.add(startState);
        queue.add(startState);
        int moves = 0;
        while(!queue.isEmpty()){
            int size = queue.size();
            while(size-->0){
                String current = queue.poll();
                if(current.equals(target)) return moves;
                int zeroPos = current.indexOf('0');
                for(int newZeroPos : directions[zeroPos]){
                    String nextState = swap(current, zeroPos, newZeroPos);
                    if(visited.contains(nextState)) continue;
                    visited.add(nextState);
                    queue.add(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
}