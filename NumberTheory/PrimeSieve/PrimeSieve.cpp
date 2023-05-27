#include<bits/stdc++.h>
#define int long long int
using namespace std;

class PrimeSieve{
    private:
        int n;
        bool checker(){
            vector<int> markingList(n+1,1);
            for(int64_t i=2;i<=this->n;i++){
                if(markingList[i]){
                    for(int64_t j=i*i;j<=this->n;j+=i){
                        if(j<n+1 && markingList[j]){markingList[j]=0;}
                        if(j==n){return false;}
                    }
                }
            }
            if(markingList[n]){return true;}
            else{return false;}
        }
    public:
        PrimeSieve(int n){
            this->n=n;
        }
        bool isPrime(){
            return checker();
        }
};

bool test(){
    ifstream fop;
    ofstream fwr;
    fop.open("./testFilePrimeSieve.txt");
    fwr.open("./testOutput.txt");
    string line;
    int TC=1;
    while(getline(fop,line)){
        cout<<"Running on TC: "<<TC++;
        PrimeSieve newPrimeTest(stoi(line));
        bool isPrime=1;
        clock_t timeNormal,timeOptimal;
        timeNormal=clock();
        for(int64_t i=2;i<stoi(line);i++){
            if(stoi(line)%i==0){isPrime=0;break;}
        }
        timeNormal=clock()-timeNormal;
        timeOptimal=clock();
        bool isPrimeSieve = newPrimeTest.isPrime();
        timeOptimal=clock()-timeOptimal;
        if(isPrime!=isPrimeSieve){
            cout<<"Failed At: "<<stoi(line)<<'\n';
            return false;
        }
        double ratio;
        ratio=((double)timeNormal/CLOCKS_PER_SEC)/((double)timeOptimal/CLOCKS_PER_SEC);
        if(isPrime){fwr<<isPrimeSieve<<'\t'<<isPrime<<'\t'<<ratio<<'\n';}
        system("CLS");
    }
    return true;
}

int32_t main(){
    system("CLS");
    cout<<(test()?"All Tests Passed":"Failed");
}