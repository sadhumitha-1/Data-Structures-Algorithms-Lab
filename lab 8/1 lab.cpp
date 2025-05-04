//This program is to solve the codeforces tower-block problem

#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
    long long t,n;
    printf("Enter no. of test cases=");
    scanf("%lld",&t);

    while(t--){
        printf("Enter no. of towers in test case %lld=",t);
        scanf("%lld",&n);
        std::vector <long long> a(n);

        for (int i=0;i<n;i++){
            printf("Enter no. of blocks in tower %d=",i);
            scanf("%lld",&a[i]);
        }

        std::sort(a.begin()+1,a.end());

        for (int i=1;i<n;i++){
            if (a[i]>a[0]){
                if ((a[0]+a[i])%2==0){
                    a[0]=(a[0]+a[i])/2;
                }
                else{
                    a[0]=((a[0]+a[i])/2)+1;
                }
                a[i]=a[0]-1;
            }
        }
        printf("The no. of blocks in the first tower=%lld\n",a[0]);
    }
    return 0;
}