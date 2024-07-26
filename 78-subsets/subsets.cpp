class Solution {
public:
    void solve(vector<int> &nums, vector<int> &current, vector<vector<int>> &ans_fin, int n, int ind) {
    if (ind == n) {
        ans_fin.push_back(current);
        return;
    } else {
        // Include the current element
        current.push_back(nums[ind]);
        solve(nums, current, ans_fin, n, ind + 1);
        current.pop_back();  // Backtrack
        
        // Exclude the current element
        solve(nums, current, ans_fin, n, ind + 1);
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans_fin;
    vector<int> current;
    solve(nums, current, ans_fin, nums.size(), 0);
    return ans_fin;
}

};