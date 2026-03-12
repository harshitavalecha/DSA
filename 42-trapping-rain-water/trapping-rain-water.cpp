#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // int n=height.size();
        // int maxleft[n];
        // int maxright[n];
        // maxleft[0]=0;
        // for(int i=1;i<height.size();i++){
        //     maxleft[i]=max(maxleft[i-1],height[i-1]);
        // }
        // maxright[n-1]=0;
        // for(int i=n-2;i>=0;i--){
        //     maxright[i]=max(maxright[i+1],height[i+1]);
        // }
        // int water=0;
        // for(int i=0;i<n;i++){
        //     int mini= min(maxright[i],maxleft[i]);
        //     if(mini-height[i]>=0){
        //         water+=mini-height[i];
        //     }
            
        // }
        // return water;
   
//    optimized code
    int water=0; 
    int rightm=height[0];
    int leftm=0;
    //  int heightm=height[0];
     int n=height.size();
     int index=0;
     for(int i =1;i<n;i++){
        if(rightm<height[i]){
            rightm=height[i];
            index=i;

        }
        }
        // leftpart
    for(int i=0;i<index;i++){
         if(leftm>height[i]){
            water+=leftm-height[i];

         }
         else  leftm=height[i];
    }
    rightm=0;
    for(int i=n-1;i>index;i--){
        if(rightm>height[i]){
            water+= rightm-height[i];
        }
        else rightm=height[i];
    }
     
     return water;
    }
};
