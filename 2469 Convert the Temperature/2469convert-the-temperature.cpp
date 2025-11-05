class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {(double)celsius+273.15,(double)(celsius*(9.0/5.0)+32.0)};
    }
};