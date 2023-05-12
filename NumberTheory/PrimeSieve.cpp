#include<bits/stdc++.h>
using namespace std;

class PrimeSieve{
    private:
        int n;
        bool checker(){
            vector<int> markingList(n+1,1);
            for(int i=2;i<=this->n;i++){
                if(markingList[i]){
                    for(int j=i*i;j<=this->n;j+=i){
                        if(markingList[j]){markingList[j]=0;}
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
    while(getline(fop,line)){
        PrimeSieve newPrimeTest(stoi(line));
        bool isPrime=1;
        for(int i=2;i<stoi(line);i++){
            if(stoi(line)%i==0){isPrime=0;break;}
        }
        if(isPrime!=newPrimeTest.isPrime()){
            cout<<"Failed At: "<<stoi(line)<<'\n';
            return false;
        }
        fwr<<newPrimeTest.isPrime()<<'\t'<<isPrime<<'\n';
    }
    return true;
}

int main(){
    cout<<(test()?"All Tests Passed":"Failed");
}