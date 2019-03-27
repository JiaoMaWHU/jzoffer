class Solution {
public:
    double Power(double base, int exponent) {
        if(fabs(base-0.0)<1e-6){
            return 0.0;
        }
        unsigned int absExponent=(unsigned int)exponent;
        if(exponent<0) absExponent=(unsigned int)-exponent;
        double result=getPower(base,absExponent);
        if(exponent<0) result=1.0/result;
        return result;
    }
    
    double getPower(double base,unsigned int ex){
        if(ex==0) return 1.0;
        if(ex==1) return base;
        
        double re=getPower(base,ex>>1);
        re*=re;
        if(ex&0x1==1) re*=base;
        return re;
    }
};