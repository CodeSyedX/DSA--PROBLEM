	// Union of two sorted arrays 

    #include<bits/stdc++.h>
    using namespace  std;
vector<int>arr(vector<int> a, vectot<int>b){
   int n = a.size();
   int m = b.size();
   vector<int>un;
   int i , j = 0
   while(i < n && j < m){
    if(a[i]<= b[j]){
        if(un.size() == 0 || un.back() != a[i]){
            un.push_back(a[i]);
        }
        i++;
    }
    else{
        
        if(un.size() == 0 || un.back != b[j]){
            un.push_back(b[j]);
        
        j++;
    }
    }
   }
   while(i < n){
     if(un.size() == 0 || un.back != a[i]){
            un.push_back(a[i]);
        }
        i++;
   }

   while(j < m){
    if(un.size() == 0 || un.back != b[j]){
            un.push_back(b[j]);
        }
        j++;
   }
   

   return un;

}