class Solution {
public:
int threeSumMulti(vector& A, int target) {
//size of array
int n = A.size();
//sort the array
sort(A.begin(), A.end());
int ans = 0;
int mod = 1e9+7;
//Selecting the first element in array
for (int i=0; i<n-2; ++i) {
int lo = i+1, hi = n-1;
while (lo < hi) {
if (A[i] + A[lo] + A[hi] == target) {

                int cntlo=1, cnthi=1;
                while (lo < hi && A[lo] == A[lo+1]) {cntlo++; lo++;}
                while (lo < hi && A[hi] == A[hi-1]) {cnthi++; hi--;}
				// A[lo]==A[hi]
                if (lo == hi) ans =(ans+cntlo*(cntlo-1)/2)%mod;
				// A[lo]!=A[hi]
                else ans = (ans+cntlo*cnthi)%mod;
                lo++; hi--; 
                
            } 
            //target is bigger than sum
            else if (A[i] + A[lo] + A[hi] > target) {
                hi--;
            } 
            //Target is smaller than sum
            else {
                lo++;
            }
        }
        //cout << ans << endl;
    }
    return ans;
}
};

