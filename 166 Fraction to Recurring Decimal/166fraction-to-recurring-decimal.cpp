class Solution {
public:
    string fractionToDecimal(int numerator, int denomenator) {
        bool negative =(numerator<0)^(denomenator<0);
        long long nu=numerator>0?numerator:(long long)numerator*-1;
        long long de=denomenator>0?denomenator:(long long)denomenator*-1;
        if(nu==0){return "0";}
        if(nu%de==0){return negative?"-"+to_string(nu/de):to_string(nu/de);
        }
        string result="";
        int temp=nu/de;
        result+=to_string(temp)+".";
        nu=nu%de;
        unordered_map<long long,int> map;
        string frac="";
        while(nu>0){
            if(map.find(nu)!=map.end()){
                frac.insert(map[nu],"(");
                frac+=")";
                result+=frac;
                return negative?"-"+result:result;
            }
            map[nu]=frac.size();
            nu*=10;
            frac+=to_string(nu/de);
            nu%=de;
        }
        result+=frac;
        return negative?"-"+result:result;
    }
};