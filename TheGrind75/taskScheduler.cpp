//https://leetcode.com/problems/task-scheduler/submissions/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //O(N) + sort efficiency O(nlogn)

        //find the totals for every task
        //the one that comes up the most will be the one with the most penalty.
        //we'll find what the total penalty would be if that were the only member.
        //we'll reduce that penalty as much as possible by reducing it for every
        //other member in the data set.

        // Create a frequency array to keep track of the count of each task
        vector<int> freq(26);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        // Sort the frequency array in non-decreasing order
        sort(freq.begin(), freq.end());
        // Calculate the maximum frequency of any task
        int maxFreq = freq[25] - 1;  //reduce it by one, because it's the number of penalties that would happen between using the same char, not for each use.
        // Calculate the number of idle slots that will be required
        int totalPenalty = maxFreq * n;
        // Iterate over the frequency array from the second highest frequency to the lowest frequency
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            // Subtract the minimum of the maximum frequency and the current frequency from the idle slots
            totalPenalty -= min(maxFreq, freq[i]);
        }
        // If there are any idle slots left, add them to the total number of tasks
        return totalPenalty > 0 ? totalPenalty + tasks.size() : tasks.size();
    }
};