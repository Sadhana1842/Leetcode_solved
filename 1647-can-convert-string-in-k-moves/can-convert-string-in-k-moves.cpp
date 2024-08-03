class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n=s.size();
        int m=t.size();
        map<int,int>hm;
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                int diff=t[i]-s[i];
                if(diff<0){
                    diff+=26;
                }
                if(diff>k){
                    return false;
                }
                if(hm.find(diff)==hm.end()){
                    hm[diff]=1;
                }
                else{
                    hm[diff]+=1;
                }
                int ff=((hm[diff]-1)*26)+diff;
                if(ff>k){
                    return false;
                }

            }
        }
        return true;
    }
};