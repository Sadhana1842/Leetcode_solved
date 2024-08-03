class Solution {
public:
    static bool compare(pair<int,int> &p1,pair<int,int> &p2){
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>hm;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(hm.find(nums[i])!=hm.end()){
                hm[nums[i]]+=1;
            }
            else{
                hm[nums[i]]=1;
            }
        }
        vector<pair<int,int>>f_vec(hm.begin(),hm.end());
        sort(f_vec.begin(),f_vec.end(),compare);
        for(int i=0;i<k;i++){
            ans.push_back(f_vec[i].first);
        }
        return ans;
    }
};