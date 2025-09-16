class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    int lcm(int a,int b){
        return (a/gcd(a,b))*b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> stk;
        int i=1,s=0;
        stk.push_back(nums[0]);
        while(i<nums.size()){
            stk.push_back(nums[i]);
            s++;
            while(stk.size()>1 && gcd(stk[s-1],stk[s])>1){
                stk[s-1]=lcm(stk[s],stk[s-1]);
                stk.pop_back();
                s--;
            }
            i++;
        }
        return vector<int>(stk.begin(),stk.end());
    }
};