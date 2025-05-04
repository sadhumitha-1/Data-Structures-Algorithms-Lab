#include <stdio.h>
#include <vector>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve() {
    int q, k, n;
    scanf("%d %d", &k, &q);
    
    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < q; i++) {
        scanf("%d", &n);
        printf("%d ", MIN(a[0] - 1, n));
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        solve();
    }
    
    return 0;
}

