#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

class Solution {
public:
    int subsequencesWithMiddleMode(vector<int>& nums) {
        int n = (int)nums.size();
        if(n < 5) return 0;

        vector<long long> arr(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        auto idxOf = [&](long long x){
            return int(lower_bound(arr.begin(), arr.end(), x) - arr.begin());
        };
        int m = (int)arr.size();

        vector<vector<int>> pref(n+1, vector<int>(m,0));
        for(int i=0;i<n;i++){
            int p = idxOf(nums[i]);
            for(int j=0;j<m;j++){
                pref[i+1][j] = pref[i][j];
            }
            pref[i+1][p]++;
        }

        auto choose2 = [&](long long c){ 
            return (c<2? 0LL : (c*(c-1)/2) % MOD);
        };

        long long ans = 0;

        for(int i=2; i+2<n; i++){
            int pm = idxOf(nums[i]);

            long long cL = pref[i][pm];
            long long cR = pref[n][pm] - pref[i+1][pm];

            vector<long long> fL(m,0), fR(m,0);
            for(int v=0; v<m; v++){
                fL[v] = pref[i][v];
                fR[v] = (pref[n][v] - pref[i+1][v]);
            }

            long long sumAllL = 0, sumAllR = 0;
            long long sumSqL = 0, sumSqR = 0;
            for(int v=0; v<m; v++){
                if(v==pm) continue;
                long long c = fL[v];
                if(c>0){
                    sumAllL += c;
                    sumSqL += (c*c);
                }
            }
            for(int v=0; v<m; v++){
                if(v==pm) continue;
                long long c = fR[v];
                if(c>0){
                    sumAllR += c;
                    sumSqR += (c*c);
                }
            }
            sumAllL %= MOD; sumAllR %= MOD; sumSqL %= MOD; sumSqR %= MOD;

            auto modsub = [&](long long a, long long b){
                return ( (a%MOD - b%MOD) %MOD + MOD )%MOD;
            };
            long long cat3L = modsub((sumAllL*sumAllL)%MOD, sumSqL);
            cat3L = (cat3L * ((MOD+1)/2)) % MOD;
            long long cat3R = modsub((sumAllR*sumAllR)%MOD, sumSqR);
            cat3R = (cat3R * ((MOD+1)/2)) % MOD;

            long long s1=0, s2=0, t1=0, t2=0; 
            long long sumAllL_nonpm=0, sumAllR_nonpm=0; 
            for(int v=0; v<m; v++){
                if(v==pm) continue;
                sumAllL_nonpm += fL[v];
                sumAllR_nonpm += fR[v];
            }
            sumAllL_nonpm %= MOD; sumAllR_nonpm %= MOD;
            for(int v=0; v<m; v++){
                if(v==pm) continue;
                long long cLf = fL[v], cRf = fR[v];
                s1 = (s1 + cLf*cRf) % MOD;
                s2 = (s2 + cLf*( (cRf*cRf)%MOD )) % MOD;
                t2 = (t2 + cRf*( (cLf*cLf)%MOD )) % MOD;
            }

            long long ways5=0;
            if(cL>=2 && cR>=2){
                ways5 = ( ( (cL*(cL-1))/2 ) %MOD )* ( ( (cR*(cR-1))/2 ) %MOD ) %MOD;
            }

            long long ways4=0;
            if(cL>=2 && cR>=1){
                long long tmp1 = ((cL*(cL-1))/2)%MOD;
                long long tmp2 = cR % MOD;
                ways4 = (ways4 + ( (tmp1 * tmp2)%MOD * sumAllR_nonpm )%MOD )%MOD;
            }
            if(cL>=1 && cR>=2){
                long long tmp1 = cL % MOD;
                long long tmp2 = ((cR*(cR-1))/2)%MOD;
                ways4 = (ways4 + ( (tmp1 * tmp2)%MOD * sumAllL_nonpm )%MOD )%MOD;
            }

            auto C = [&](long long big, long long small){
                if(small<0 || small>big) return 0LL;
                if(small==0) return 1LL;
                if(small==1) return big;
                if(small==2) return (big*(big-1))/2;
                return 0LL;
            };
            long long ways3=0;
            if(cL>=2){
                long long w = C(cL,2)*C(cR,0);
                w %= MOD;
                w = ( w * C(sumAllL,0) )%MOD;
                w = ( w * C(sumAllR,2) )%MOD;
                ways3 = (ways3 + w)%MOD;
            }
            if(cR>=2){
                long long w = C(cL,0)*C(cR,2);
                w %= MOD;
                w = ( w * C(sumAllL,2) )%MOD;  
                w = ( w * C(sumAllR,0) )%MOD;  
                ways3 = (ways3 + w)%MOD;
            }
            if(cL>=1 && cR>=1){
                long long w = C(cL,1)*C(cR,1);
                w %= MOD;
                w = ( w * C(sumAllL,1) )%MOD;
                w = ( w * C(sumAllR,1) )%MOD;
                ways3 = (ways3 + w)%MOD;
            }

            auto freq2Part = [&](long long cPick, long long cat3S, long long sumAllS, long long s1_, long long s2_, long long sumAllSide){
                long long term1 = (cat3S * sumAllS) % MOD; 
                long long term2 = ( ( sumAllSide % MOD ) * ( s1_ % MOD ) ) % MOD;
                long long inside = ( (term1 - (term2 - s2_ + MOD)%MOD )%MOD + MOD )%MOD;
                return ( (cPick % MOD) * inside )%MOD;
            };

            long long pickL = (cL>=1? cL : 0LL);
            long long part1 = freq2Part(pickL, cat3R, sumAllL_nonpm, s1, s2, sumAllR);

            long long pickR = (cR>=1? cR : 0LL);
            long long part2 = 0;
            {
                long long term1 = (cat3L * sumAllR_nonpm) % MOD;
                long long term2 = ( ((long long)sumAllL %MOD)* (s1 %MOD)) %MOD; 
                long long inside = ( (term1 - (term2 - t2 + MOD)%MOD )%MOD + MOD )%MOD;
                part2 = ( (pickR %MOD) * inside )%MOD;
            }
            long long ways2 = (part1 + part2)%MOD;

            long long total = ( (ways5+ways4)%MOD + (ways3+ways2)%MOD )%MOD;
            ans = (ans + total) % MOD;
        }

        return (int)ans;
    }
};