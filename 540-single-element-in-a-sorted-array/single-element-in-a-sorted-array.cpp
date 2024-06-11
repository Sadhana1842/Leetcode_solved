class Solution {
public:
    //XOR of all elements is the simplest but complexity is O(n)
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-2;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==nums[mid^1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        return nums[start];

    }
};