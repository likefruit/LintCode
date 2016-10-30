class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if (n == 1)
		return 0;
	else if (n == 2 || n == 3)
		return 1;
	else
	{
		int a = 0;
		int b = 1;
		int result = 0;
		for (int i = 0; i < n-1; ++i)
		{
			result = a + b;
			a = b;
			b = result;
		}

		return a;
	}
    }
};


