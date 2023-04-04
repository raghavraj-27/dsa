class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int n= reward1.length;
        
        Queue<Integer> maxHeap = new PriorityQueue<Integer>(Comparator.reverseOrder());
        for(int i=0; i<n; i++) {
            maxHeap.offer(reward1[i] - reward2[i]);
        }
        
        int totalScore = 0;
        for(int i=0; i<n; i++) {
            totalScore += reward2[i];
        }
        
        while(k > 0) {
            totalScore += maxHeap.poll();
            k--;
        }
        
        return totalScore;
    }
}