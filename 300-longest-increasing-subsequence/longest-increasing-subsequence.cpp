class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>arr=nums;
        vector<int>sorted_arr=nums;
        sort(sorted_arr.begin(),sorted_arr.end());
        sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
        int len1=arr.size();
        int len2=sorted_arr.size();
        vector<vector<int>> table( len1+1 , vector<int> (len2+1));
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                if(i==0||j==0){
                    table[i][j]=0;
                }
                else if(arr[i-1]==sorted_arr[j-1]){
                    table[i][j]=1+table[i-1][j-1];
                }
                else{
                    table[i][j]=max(table[i-1][j],table[i][j-1]);
                }

            }
        }
        return table[len1][len2];
    }
    
};