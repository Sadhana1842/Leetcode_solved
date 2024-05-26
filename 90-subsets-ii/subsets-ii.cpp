class Solution {
public:
    void solve(vector<int> &nums,vector<int> &check,set<vector<int>> &ans_fin,int n,int ind){
        if(ind==n){
            vector<int>ans;
            for(int i=0;i<n;i++){
                if(check[i]==1){
                    ans.push_back(nums[i]);
                }

            }
            ans_fin.insert(ans);
            return;
        }
        else{
            check[ind]=1;
            solve(nums,check,ans_fin,n,ind+1);
            check[ind]=-1;
            solve(nums,check,ans_fin,n,ind+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>check(n,-1);
        set<vector<int>>ans_fin;
        solve(nums,check,ans_fin,n,0);
        return vector<vector<int>>(ans_fin.begin(),ans_fin.end());
    }

};