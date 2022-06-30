class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] count = new int[26];

        for (char t : tasks)count[task - 'A']++;

        final int maxFreq = Arrays.stream(count).max().getAsInt();
        // put the most frequent task in the slot first
        final int maxFreqTaskOccupy = (maxFreq - 1) * (n + 1);
        
        // Case1: idle slots
        // A   A   -ABC
        //          ---  
        // Case2:
        // everything will be filled, so it will be the sequence itself
        final int nMaxFreq = (int) Arrays.stream(count).filter(c -> c == maxFreq).count();
        // max(
        //   the most frequent task is frequent enough to force some idle slots,
        //   the most frequent task is not frequent enough to force idle slots
        // )
        return Math.max(maxFreqTaskOccupy + nMaxFreq, tasks.length);
    }
    
}
