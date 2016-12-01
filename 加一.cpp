class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        long long num=0;
        vector<int> res;
        for(int i=0;i<digits.size();++i)
        {
            num=digits[i]+num*10;
        }
        num++;
        while(num!=0)
        {
            res.insert(res.begin(),(num%10));
            num=num/10;
        }
        return res;
    }
};
