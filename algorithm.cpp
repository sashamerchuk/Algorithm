#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mas[1000], block[1000], next_num[1000], prev_num[1000];
    bool forward[1000];
    for(int i=1;i<=n;i++) {
        mas[i] = i;
        block[i] = 1;
        forward[i] = true;
    }
    next_num[1] = n+1;
    int x = prev_num[1] = 0;
    while(x!=1) {
        for(int i = 1; i <= n; i ++) {
            bool bracket_open = false, bracket_close = false;
            for(int j = 1; j <= n; j ++) {
                if(block[j]==i) {
                    bracket_open = bracket_close = true;
                    break;
                }
            }
            if(bracket_open) {cout << "( ";}
            for(int j = 1; j <= n; j ++) {
                if(block[j]==i) {
                    cout << mas[j] << " ";
                }
            }
            if(bracket_close) {cout << ")";}
        }
        cout << "\n";
        x = n;
        while(x>1 && ((block[x]==x && forward[x]) || (block[x] == 1 && !forward[x]))) {
              forward[x] = !forward[x];
              x--;
        }
        int i=block[x];
        if(forward[x]) {
            if(next_num[i]>x) {
                if(next_num[i] == n+1) {
                    next_num[x] = n+1;
                }else {
                    next_num[x] = next_num[i];
                    prev_num[next_num[i]] = x;
                }
                next_num[i] = x;
                prev_num[x] = i;
            }
            block[x] = next_num[i];
        }else {
            if(block[x] == x) {
                if(next_num[i] == n+1) {
                    next_num[prev_num[i]] = n+1;
                }else {
                    next_num[prev_num[i]] = next_num[i];
                    prev_num[next_num[i]] = prev_num[i];
                }
            }
            block[x] = prev_num[i];
        }
    }
}
