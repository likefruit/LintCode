
//我的答案
class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        while(n!=0&&n%2==0)
        {
            n=n/2;
        }
        if(n==1)
            return true;
        else
            return false;
    }
};

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
       if(n>0)
        return (n&(n-1))==0;
       else
        return false;
    }
};
