/*
Given an array arr[] of N non-negative integers representing the height of blocks. 
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
*/
#include<bits/stdc++.h>

using namespace std;
class Solution{
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int lmax[n],rmax[n],i;
        lmax[0]=arr[0];
        for(i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],arr[i]);
        }
        rmax[n-1]=arr[n-1];
        for(i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],arr[i]);
        }
        long long res=0;
        for(i=1;i<n-1;i++){
            res+=min(lmax[i],rmax[i])-arr[i];
        }
        return res;
        
    }
};

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
} 
