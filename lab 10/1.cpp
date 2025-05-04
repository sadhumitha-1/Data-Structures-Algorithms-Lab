#include <stdio.h>
#include <vector>

void solve(){
    int n;
    printf("Enter the length of the array=");
    scanf("%d",&n);
    
    std::vector <int> a(n);
    printf("Enter elements seperated by spaces:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    const int MAX_VAL=100;
    std::vector <int> last_pos(MAX_VAL+1,-1);
    int first_rep=0;

    for (int i=n-1;i>=0;i--){
        if (last_pos[a[i]]!=-1){
            first_rep=i+1;
            break;
        }
        last_pos[a[i]]=i;
    }

    printf("%d\n",first_rep);

}

int main(){
    int t;
    printf("Enter no. of test cases=");
    scanf("%d",&t);

    while (t--){
        solve();
    }
}