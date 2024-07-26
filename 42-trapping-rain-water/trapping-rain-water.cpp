class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=height[i];
        }
        if(sum==n){
            return 0;
        }
        int tot_water=0;
        for(int i=0;i<n;i++){
            int left_max=0;
            int right_max=0;
            for(int j=0;j<=i;j++){
                if(height[j]>left_max){
                    left_max=height[j];
                }
            }
            for(int j=i;j<n;j++){
                if(height[j]>right_max){
                    right_max=height[j];
                }
            }

            int min=right_max<=left_max ? right_max:left_max;
            tot_water+=min-height[i];
        }
        return tot_water;
    }
};