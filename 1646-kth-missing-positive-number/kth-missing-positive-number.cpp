class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]<=k)  k++;
        //     else break;
        // }
        // return k;


    // binary search method
    int start=0;
    int end=arr.size()-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k
        ){
            start=mid+1;
        }
        else end=mid-1;
    }
    return k+end+1;
    }
};