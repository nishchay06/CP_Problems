#include </Users/nishchay/Desktop/abc.h>
using namespace std;

int main(){
    vector<string> city = {"Chennai", "Bangalore", "Visakhapatnam", "Hyderabad", "Mumbai"};
    vector<int> distance = {380, 200, 250, 750, 635};
    int n = size(distance);
    vector<pair<string,int>> cdp;
    for(int i = 0; i < n; i++) {
        cdp.push_back({city[i],distance[i]});
    }
    sort(begin(cdp),end(cdp));
    vector<int> customSortDistances;
    for(int i = 0; i < n; i++) {
        cout<<"{"<<cdp[i].first<<","<<cdp[i].second<<"}, ";
        customSortDistances.push_back(cdp[i].second);
    }
    vector<int> acceptableDist;
    for(int i = 0; i < n; i++) {
        int cr = customSortDistances[i];
        int ind = lower_bound(begin(acceptableDist),end(acceptableDist),cr)-begin(acceptableDist);
        if(ind == size(acceptableDist)) acceptableDist.push_back(cr);
        else acceptableDist[ind] = cr;
    }
    cout<<size(acceptableDist)<<endl;
}
//-std=c++20
// #include<bits/stdc++.h>