// Link to the Problem: https://leetcode.com/problems/rotting-oranges/

// Approach:
// 1) Take all the rotten oranges in the queue.
// 2) If its neighbours are not visited and orange states of those are 1, then rot those oranges and put them inot the queue.
// 3) Add a timer variable along with it in the queue and increment it for the newly added oranges in an iteration .
// 4) Continue this until queue is not empty.

