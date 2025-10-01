#include <bits/stdc++.h>

using namespace std;

int main() {


   int n;
   cin>>n;
   vector<pair<pair<string,int>, pair<int,int>>> v;



   for(int i=0;i<n;i++)
   {
       int xx,x,y;
       string s;
       cin>>s>>xx>>x>>y;


       v.push_back({{s,xx},{x,y}});

   }

   sort(v.begin(), v.end(), [](auto &a, auto &b) {
    return tie(a.first.second, a.second.first, a.second.second) <
        tie(b.first.second, b.second.first, b.second.second);
});



   for(auto x: v)
   cout<<x.first.first<<" "<<x.first.second<< " "<<x.second.first<<" "<<x.second.second<<endl;

   cout<<endl;



}