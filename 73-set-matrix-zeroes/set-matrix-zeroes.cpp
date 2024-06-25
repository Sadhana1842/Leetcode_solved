class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ai;
        vector<int>jey;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    ai.push_back(i);
                    jey.push_back(j);
                }
            }

        }
        for(int i=0;i<ai.size();i++){
            int row=ai[i];
            for(int j=0;j<n;j++){
                matrix[row][j]=0;
            }
        }
        for(int i=0;i<jey.size();i++){
            int col=jey[i];
            for(int j=0;j<m;j++){
                matrix[j][col]=0;
            }
        }
        
    }
};