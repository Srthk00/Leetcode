class Solution {
public:
    string change(int n) {
        string temp="";
        while(n>0){
            int t=n%2;
            temp.push_back('0'+t);
            n/=2;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    string convertDateToBinary(string date) {
        string result="";
        string year=change(stoi(date.substr(0,4)));
        string month=change(stoi(date.substr(5,2)));
        string d=change(stoi(date.substr(8,2)));
        result+=year;
        result+="-";
        result+=month;
        result+="-";
        result+=d;
        return result;
    }
};