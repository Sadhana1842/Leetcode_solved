class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX; // Initialize with a large value

        // Iterate over the array with the right pointer
        for (int right = 0; right < n; ++right) {
            sum += nums[right]; // Expand the window by adding nums[right]

            // While the current window's sum is greater than or equal to target
            while (sum >= target) {
                minLength = min(minLength, right - left + 1); // Update minimum length
                sum -= nums[left++]; // Shrink the window by removing nums[left]
            }
        }

        return minLength == INT_MAX ? 0 : minLength; // Return 0 if no valid subarray found
    }
};