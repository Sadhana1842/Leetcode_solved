class Solution {
public:
    bool isP(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
            return false;
            }
        start++;
        end--;
        }
        return true;
        
    }
    void solve(int ind,string s,vector<string> &path,vector<vector<string>> &res){
        if(ind==s.size()){
            res.push_back(path);
            return;

        }
        else{
            for(int i=ind;i<s.size();i++){
                if(isP(s,ind,i)){
                    path.push_back(s.substr(ind,i-ind+1));
                    solve(i+1,s,path,res);
                    path.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>>res;
       vector<string>path;
       solve(0,s,path,res);
       return res;
    }
    
};