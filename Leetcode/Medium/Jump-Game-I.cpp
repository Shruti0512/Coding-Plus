/* You are given an integer array nums.
You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int r = 0; i < n && i <= r; ++i)
            r = max(i + nums[i], r);
        return i == n;
    }
};
