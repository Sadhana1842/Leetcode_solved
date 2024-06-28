class Solution {
public:
    double myPow(double x, int n) {
        double pow=1;
        if(n<0){
            x=1/x;
        }
        n=labs(n);
        while(n!=0){
            if((n & 1)!=0){
                pow*=x;
            }
            x*=x;
            n=n/2;
        }
        return pow;
        
    }
};