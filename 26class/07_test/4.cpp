#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long K,N;
    cin>>K>>N;
    vector<long long> numbers;
    for(long long i=0;i<N;i++){
        long long  number;
        cin>>number;
        numbers.push_back(number);
    }
    sort(numbers.begin(),numbers.end());

    long long lucky_number=0;
    int left = 0, right = N-1;
    while(left<right){
        long long cur_sum = numbers[left]+numbers[right];
        if(cur_sum==K){
            lucky_number++;
            cout<<numbers[left]<<" "<<numbers[right]<<endl;
            left++;right--;
        }else if(cur_sum>K){
            right--;
        }else{
            left++;
        }
    }

    if(lucky_number==0) cout<<"No Solution"<<endl;
}
