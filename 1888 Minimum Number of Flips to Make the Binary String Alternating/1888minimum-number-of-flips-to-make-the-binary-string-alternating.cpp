class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        // two possible sequence

        // case 1
        // starting from 0
        // 010101010101
        // 0 at even, 1 at odd
        int one_at_even=0,zero_at_odd=0;

        // case 2
        // starting from 0
        // 101010101010
        // 0 at even, 1 at odd
        int zero_at_even=0,one_at_odd=0;

        // find count who dont follow the sequence
        for(int i=0;i<n;i++){
            if(i&1 && s[i]=='1'){one_at_odd++;}
            if(!(i&1) && s[i]=='0'){zero_at_even++;}
            if(i&1 && s[i]=='0'){zero_at_odd++;}
            if(!(i&1) && s[i]=='1'){one_at_even++;}
        }
        int case1=one_at_even+zero_at_odd;
        int case2=one_at_odd+zero_at_even;
        // check all rotations
        for(int i=0;i<n;i++){
            // remove char from front
            if(s[i]=='0'){zero_at_even--;}
            else{one_at_even--;}
            // after removing first char, positions will be altered
            swap(zero_at_even,zero_at_odd);
            swap(one_at_even,one_at_odd);
            // if length is odd, new last position will be even
            if(n&1){
                s[i]=='1'?one_at_even++:zero_at_even++;
            }
            // if length is even, new last position will be odd
            else{
                s[i]=='1'?one_at_odd++:zero_at_odd++;
            }
            case1=min(case1,one_at_even+zero_at_odd);
            case2=min(case2,one_at_odd+zero_at_even);
        }
        int result=min(case1,case2);
        return result;
    }
};