#include <stdio.h>
#include <string.h>
#define N_PLAYERS 3
#define MAX_WORDS 1000
#define WORD_LEN 4

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        
        char words[N_PLAYERS][MAX_WORDS][WORD_LEN];
        int points[N_PLAYERS] = {0, 0, 0};
        
        for (int i = 0; i < N_PLAYERS; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%s", words[i][j]);
            }
        }
        
        for (int i = 0; i < N_PLAYERS; i++) {
            for (int j = 0; j < n; j++) {
                int count = 1;
                
                for (int k = 0; k < N_PLAYERS; k++) {
                    if (k == i) continue;
                    
                    for (int l = 0; l < n; l++) {
                        if (strcmp(words[i][j], words[k][l]) == 0) {
                            count++;
                            break;
                        }
                    }
                }
                
                if (count == 1) {
                    points[i] += 3;
                } else if (count == 2) {
                    points[i] += 1;
                }
            }
        }
        
        printf("%d %d %d\n", points[0], points[1], points[2]);
    }
    
    return 0;
}