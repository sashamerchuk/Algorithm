#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mas[1000], bloc[1000], next[1000], prev[1000];
    bool forw[1000];
    for(int i=1;i<=n;i++) {
        mas[i] = i;
        bloc[i] = 1;
        forw[i] = true;
    }
    next[1] = n+1;
    int x = prev[1] = 0;
    while(x!=1) {
        for(int i = 1; i <= n; i ++) {
            bool bracket_open = false, bracket_close = false;
            for(int j = 1; j <= n; j ++) {
                if(bloc[j]==i) {
                    bracket_open = bracket_close = true;
                    break;
                }
            }
            if(bracket_open) {cout << "( ";}
            for(int j = 1; j <= n; j ++) {
                if(bloc[j]==i) {
                    cout << mas[j] << " ";
                }
            }
            if(bracket_close) {cout << ")";}
        }
        cout << "\n";
        x = n;
        while(x>1 && ((bloc[x]==x && forw[x]) || (bloc[x] == 1 && !forw[x]))) {
              forw[x] = !forw[x];
              x--;
        }
        int i=bloc[x];
        if(forw[x]) {
            if(next[i]>x) {
                if(next[i] == n+1) {
                    next[x] = n+1;
                }else {
                    next[x] = next[i];
                    prev[next[i]] = x;
                }
                next[i] = x;
                prev[x] = i;
            }
            bloc[x] = next[i];
        }else {
            if(bloc[x] == x) {
                if(next[i] == n+1) {
                    next[prev[i]] = n+1;
                }else {
                    next[prev[i]] = next[i];
                    prev[next[i]] = prev[i];
                }
            }
            bloc[x] = prev[i];
        }
    }
}
