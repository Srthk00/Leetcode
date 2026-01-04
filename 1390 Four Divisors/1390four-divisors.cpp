class Solution {
public:
    int func(int n){
        int sum=0,count=0;
        int till=sqrt(n);
        for(int i=1;i<=till;i++){
            if(n%i==0){
                if(i!=(n/i)){
                    count+=2;
                    sum+=(i+(n/i));
                }
                else{
                    sum+=i;
                    count++;
                }
            }
        }
        return count==4?sum:0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result=0;
        for(int i:nums){result+=func(i);}
        return result;
    }
};