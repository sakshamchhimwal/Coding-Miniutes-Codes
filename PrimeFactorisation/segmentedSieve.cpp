#include<bits/stdc++.h>
#define long long int int
using namespace std;
class SegmentedSieve{
public:
    vector<int> rangePrimeFinder(int n,int m){
        int segmentSize = sqrt(m)+1;
        vector<int> segment(segmentSize,0);
        vector<int> segmnetPrimes={};
        for(int i=2;i<segmentSize;i++){
            if(!segment[i]){
                segment[i]=1;
                segmnetPrimes.push_back(i);
                for(int j=i*i;j<segmentSize;j++){segment[j]=1;}
            }
        }
        vector<int> rangeSegment(m-n+1,0);
        for(int num:segmnetPrimes){
            int base = n;
            while(base%num!=0){base++;}
            for(int i=base-n;i<m-n+1;i+=num){
                if(i+n!=num){rangeSegment[i]=1;}
            }
        }
        vector<int> rangePrimes = {};
        for(int i=0;i<m-n+1;i++){if(!rangeSegment[i]){rangePrimes.push_back(i+n);}}
        return rangePrimes;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    SegmentedSieve soln;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<int> ans = soln.rangePrimeFinder(n,m);
        for(int a:ans){if(a!=1)cout<<a<<'\n';}
    }
}

900000000
900100000