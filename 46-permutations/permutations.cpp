class Solution {
public:
    void solve(int n,vector<int> &nums,vector<vector<int>> &ans,int start,int end){
        if(start==end){
            ans.push_back(nums);
        }
        else{
            for(int i=start;i<=end;i++){
                int temp=nums[i];
                nums[i]=nums[start];
                nums[start]=temp;
                solve(n,nums,ans,start+1,end);
                temp=nums[i];
                nums[i]=nums[start];
                nums[start]=temp;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        solve(n,nums,ans,0,n-1);
        return ans;
    }
};