class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=nums.size()-1;i>ind;i--){
                if(nums[ind]<nums[i]){
                    swap(nums[i],nums[ind]);
                    break;
                }
                
            }
            sort(nums.begin()+ind+1,nums.end());
        }
        
        
    }
};