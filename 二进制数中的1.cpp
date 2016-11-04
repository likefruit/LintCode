//第一种
/*原数除以2后，数字将减少一个0

若余数是1则，减少一个1，记录1的个数

若余数是0则，减少一个0，记录0的个数
*/
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        if(num == 0)
            return 0;
        
        
        int result =0;
        if(num>0){
            while(num!=0){
                if(num%2==1)
                    result++;
                num = num/2;
               
            }
        }
        if(num<0){
            num = num + 2147483648;//把负数转换成正数，主要算出结果后加1。
            while(num!=0){
                if(num%2==1)
                    result++;
                num = num/2;
               
            }
            result++;
        }
        return result;
    }
};

//第二种
// Time:  O(logn) = O(32)
// Space: O(1)

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int count = 0;
        for (; num; num &= num - 1) {
            ++count;
        }
        return count;
    }
};
