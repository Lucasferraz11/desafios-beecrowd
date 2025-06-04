#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    char s[1005];
    while (1) {
        if (!fgets(s, sizeof(s), stdin)) return 0;
        size_t len = strlen(s);
        if (len > 0 && s[len-1] == '\n') {
            s[--len] = '\0';
        }
        if (len == 1 && s[0] == '*') break;
        int n = len;
        int v[1005];

        if (n > 0) {
            v[0] = (s[0] - 'a' + 26) % 26;
            for (int i = 1; i < n; i++) {
                v[i] = (s[i] - s[i-1] + 26) % 26;
            }
            v[n] = (0 - (s[n-1] - 'a') + 26) % 26;
        }

        int vn = n + 1;
        qsort(v, vn, sizeof(int), cmpfunc);

        int pos1 = 0;
        while (pos1 < vn && v[pos1] == 0) pos1++;
        if (pos1 == vn) {
            printf("0\n");
            continue;
        }

        int pos2 = vn - 1;
        while (pos2 > 0 && v[pos2] == 0) pos2--;

        long long ans = 0;
        while (pos2 > 0) {
            ans++;
            v[pos2] = (v[pos2] + 1) % 26;
            v[pos1] = (v[pos1] + 25) % 26;
            while (pos1 < vn && (v[pos1] == 0 || (pos2 < vn && v[pos1] == v[pos2]))) pos1++;
            if (pos1 >= vn) break;
            while (pos2 > 0 && v[pos2] == 0) pos2--;
        }
        if (pos2 >= 0 && v[pos2] != 0) {
            ans += 26 - v[pos2];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
