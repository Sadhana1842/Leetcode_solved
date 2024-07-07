class Solution {
public:
    bool canWePlace(vector<int> &stalls, int dist,int k){
        int cow_count=1;
        int last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=dist){
                cow_count++;
                last=stalls[i];
            }
            if(cow_count>=k){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1;
        int high=position[n-1]-position[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canWePlace(position,mid,m)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return high;
    }
};