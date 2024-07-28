class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        int maxlength=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxlength=max(maxlength,dp[i][j]);//using maxlength unline longest comm subseq because if the else case runs the value becomes 0..indicating there might be many common subsequences bw the strings..we want the longest of them all(subseq is not like that..ther is no reset n all)
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return maxlength;
    }
};