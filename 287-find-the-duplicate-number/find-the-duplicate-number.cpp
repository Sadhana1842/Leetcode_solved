class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int max=-9999;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
            }

        }
        vector<int>temp(max+1,0);
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]=temp[nums[i]]+1;
        }
        int ans=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]>1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};