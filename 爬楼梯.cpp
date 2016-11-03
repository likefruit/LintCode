//递归
public static int climbStairs(int n) {
        int re = 0;
        if(n == 0 || n == 1){
            return 1;
        }else{
            re = climbStairs(n-1)+climbStairs(n-2);
        }
        return re;
    }
    
    
//非递归

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n==0||n==1) return 1;
        int s_1=1,s_2=1,st;
        int i=1;
        while(--n)
        {
            st=s_1+s_2;
            s_1=s_2;
            s_2=st;
        }
        return st;    
  }
        
};
