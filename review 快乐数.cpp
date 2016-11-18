//我的解法
class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        int dig=0;
        int sum=0;
        if(n==1) return true;
        while(n/10==0)
        {
            n*=n;                
        }
     
        while(n/10!=0)
        {
            while(n!=0)
            {
                dig=n%10;
                sum+=dig*dig;
                n=n/10;
            }
            n=sum;
            sum=0;
            
        }
        if(n==1) return true;
        else return false;
    }
};
//需要review的解法
// Time:  O(k), where k is the steps to be happy number
// Space: O(k)

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n != 1 && !visited.count(n)) {
            visited.emplace(n);
            n = nextNumber(n);
        }
        return n == 1;
    }

    int nextNumber(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};
