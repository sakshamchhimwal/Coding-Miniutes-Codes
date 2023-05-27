#include<bits/stdc++.h>
using namespace std;


class PrimeFactorisation{
public:
    //O(n)
    vector<int> primeFactors(int n){
        vector<int> primeFactor(n+1,0);
        for(int i=2;i<=n;i++){
            if(n%i==0){
                while (n%i==0){
                    primeFactor[i]++;
                    n/=i;
                }
            }
        }
        return primeFactor;
    }  
    //O(sqrt(n))
    vector<int> primeFactorsOptimal(int n){
        vector<int> primeFactor(n+1,0);
        //we will have a check till the sqrt of the number till concluding it is a prime number
        for(int i=2;i<=n;i++){
            if(i>sqrt(n)){primeFactor[n]++;break;}
            else{
                if(n%i==0){
                    while(n%i==0){
                        primeFactor[i]++;
                        n/=i;
                    }
                }
            }
        }
        return primeFactor;
    } 
    //Prime Fact using sieve
    vector<int> primeFactorsSieve(int n){
        vector<int> primeFactor(n+1,0);
        vector<int> sieve(n+1,0);
        for(int i=2;i<n+1;i++){
            if(!sieve[i]){
                sieve[i]=i;
                for(int j=i*i;j<n+1;j+=i){
                    sieve[j]=i;
                }
            }
        }
        int num = n;
        while(num!=1){
            primeFactor[sieve[num]]++;
            num/=sieve[num];
        }
        return primeFactor;
    }
};

int main(){
    int num;
    cin>>num;
    PrimeFactorisation pf;
    vector<int> factors = pf.primeFactorsSieve(num);
    for(int i=0;i<factors.size();i++){
        if(factors[i]!=0){
            cout<<i<<"^"<<factors[i]<<'\n';
        }
    }
}