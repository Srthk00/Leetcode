class Solution {
public:
    bool check(int num){
        string str=to_string(num);
        if(str.size()%2==1)
            return false;
        int n=str.size();
        int a=0,b=0;
        for(int i=0;i<n/2;i++){
            a+=str[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            b+=str[i]-'0';
        }
        if(a==b)
            return true;
        return false;
    }

    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            if(check(i))
                count++;
        }
        return count;
    }
};