#include<bits/stdc++.h>
using namespace std;

void buldSieve(vector<int> &nums){
    for(int64_t i=2;i<nums.size()+1;i++){
        if(nums[i]){
            for(int64_t j=i*i;j<1e6;j+=i)
                nums[j]=0;
        }
    }
}

void cummSum(vector<int> nums,vector<int> &cummSummArr){
    for(int i=1;i<cummSummArr.size()+1;i++){
        if(nums[i]){cummSummArr[i]+=cummSummArr[i-1]+1;}
        else{cummSummArr[i]=cummSummArr[i-1];}
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int queries;
    cin>>queries;
    vector<int> nums(1e6,1);
    nums[1]=0;
    vector<int> cummSummArr(1e6,0);
    buldSieve(nums);cummSum(nums,cummSummArr);
    for(int i=0;i<queries;i++){
        int a,b;
        cin>>a>>b;
        int ans = cummSummArr[b]-cummSummArr[a-1];
        cout<<ans;
    }
}