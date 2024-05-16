#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

using namespace std;
using ll = long long;

// will I be good enough to solve a problem like this by myself one day? I hope so, cause I hate looking at other solutions. At least, I understand everything here…

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    default_random_engine gen;
    uniform_int_distribution<ll> distribution(1, 16e10);
    
    vector<ll> vec(k-1);
    ll sum = 0;
    
    for (auto& v : vec) {
        v = distribution(gen);
        sum += v;
    }
    vec.push_back(-sum);
    
    int ans = 0;
    sum = 0;
    unordered_map<ll, int> mp;
    mp[0] = 0; // when subarray goes from the first element
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        
        sum += vec[num - 1];
        if (mp.count(sum))
            ans = max(ans, i + 1 - mp[sum]);
        else
            mp[sum] = i + 1;
    }
    
    std::cout << ans << '\n';


}
