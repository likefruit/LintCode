**题目**

将一个整数中的数字进行颠倒，当颠倒后的整数溢出时，返回 0 (标记为 32 位整数)。

**样例**

给定 x = 123，返回 321

给定 x = -123，返回 -321

```
class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        
        //如何判断整数的溢出？
        //如何判断整数反转后的溢出？是不是应该换成long
        
        bool flag=true;
        long res=0;
        
        //输入非法
        if(n>=2147483648||n<=-2147483648)
            return 0;
        
        //反转操作 
        else
        {
            vector<int> vec;
            if(n<0)
            {
                flag=false;
                n=-n;
            }
            while(n!=0)
            {
                //得到每一位的数字加入容器尾端
                vec.push_back(n%10);
                n/=10;
            }
            //求反转后的数字
            for(auto c:vec)
                res=res*10+c;
        }
    
        //反转之后的判断
        if(res>=2147483648)
        {
            return 0;
        }
        else if(flag==false)
            return -res;
        else
            return res;
    }
};
```


----------


**优化**

我们可以一边计算res的值一边判断res是否越界

```
class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        
        //如何判断整数的溢出？
        //如何判断整数反转后的溢出？是不是应该换成long
 
        long res=0;
        
        //输入非法
        if(n>=2147483648||n<=-2147483648)
            return 0;
        
        //反转操作 
        else
        {
            vector<int> vec;
            while(n!=0)
            {
                //得到每一位的数字加入容器尾端
                vec.push_back(n%10);
                n/=10;
            }
            //求反转后的数字，并判断数字是否越界
            for(auto c:vec)
            {
                res=res*10+c;
                if(res>=2147483648)
                    return 0;
            }
        }
        return res;
    }
};
```

再优化，因为res在计算的过程中，如果发生越界，那么得到的值/10操作肯定不会等于未加之前的值，则，res也可以声明为int类型。

```
class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        int result = 0;
        while (n) {
            auto prev = result;
            result *= 10;
            result += n % 10;
            if (result / 10 != prev) {
                result = 0;
                break;
            }
            n /= 10;
        }
        return result;
    }
};
```
