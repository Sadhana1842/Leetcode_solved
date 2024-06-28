class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        if(row==0||col==0){
            return false;
        }
        int start=0;
        int end=row*col-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int midVal=matrix[mid/col][mid%col];
            if(midVal==target){
                return true;
            }
            else if(midVal<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }

};