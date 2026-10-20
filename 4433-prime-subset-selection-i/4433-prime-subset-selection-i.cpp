vector<int> primeNumber(int n)
{
    vector<int> prime(n+1,1);
    vector<int> primeNumbers;
    if (n >= 0) prime[0] = 0;
    if (n >= 1) prime[1] = 0;
    for (int i = 2; i*i<=n; i++)
    {
        if(prime[i]) for(int j = i*i; j <= n; j+=i) prime[j]=0; 
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1)  primeNumbers.push_back(i);
    }
    return primeNumbers;
}
class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> primes=primeNumber(n);
        vector<int> ans;
        int sum=0;
        for(auto it:primes)
        {
            if(sum+it>s) break;
            ans.push_back(it);
            sum+=it;
        }
        return ans;
    }
};