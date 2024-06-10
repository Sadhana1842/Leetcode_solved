class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1){
            return x;
        }
        int start=1;
        int end=x;
        int mid=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            long long sqr=static_cast<long long>(mid)*mid;
            if(sqr>x){
                end=mid-1;
            }
            else if(sqr==x){
                return mid;
            }

            else{
                start=mid+1;
            }
        }

        return end;
    }
};