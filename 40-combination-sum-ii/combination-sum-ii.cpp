class Solution {
public:
    void findcom(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }
    
    for (int i = ind; i < arr.size(); i++) {
        // Skip duplicates
        if (i > ind && arr[i] == arr[i - 1]) continue;

        // Break early if the current element is greater than the target
        if (arr[i] > target) break;
        
        // Include the current element
        ds.push_back(arr[i]);
        // Move to the next index
        findcom(i + 1, target - arr[i], arr, ans, ds);
        // Backtrack
        ds.pop_back();
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findcom(0, target, candidates, ans, ds);
        return ans;
    }

};