#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        int tot = 0;
        for (int i = 0; i < n; ++i) {
            tot += a[i];
        }

        int la = 0, lb = 0, lc = 0;
        int ra = 0, rb = 0, rc = 0;
        int sum_a = 0, sum_b = 0, sum_c = 0;
        int s1 = 0, s2 = 0, s3 = 0;

        int i = 0;
        int x = 0;
        while (i < n) {
            sum_a += a[i];
            sum_b += b[i];
            sum_c += c[i];
            if (sum_a >= (tot + 2) / 3) {
                la = 0;
                ra = i;
                s1 = sum_a;
                sum_b = 0;
                sum_c = 0;
                break;
            }
            if (sum_b >= (tot + 2) / 3) {
                lb = 0;
                rb = i;
                s1 = sum_b;
                sum_a = 0;
                sum_c = 0;
                break;
            }
            if (sum_c >= (tot + 2) / 3) {
                lc = 0;
                rc = i;
                s1 = sum_c;
                sum_a = 0;
                sum_b = 0;
                break;
            }
            i++;
        }
        i++;
        x = i;

        while(i < n) {
            sum_a += a[i];
            sum_b += b[i];
            sum_c += c[i];
            if (sum_a >= (tot + 2) / 3 && ra == 0) {
                s2 = sum_a;
                la = x;
                ra = i;
                if (lb == 0 && rb == 0) {
                    sum_b = 0;
                }
                if (lc == 0 && rc == 0) {
                    sum_c = 0;
                }
                break;
            }
            if (sum_b >= (tot + 2) / 3 && rb == 0) {
                lb = x;
                rb = i;
                s2 = sum_b;
                if (la == 0 && ra == 0) {
                    sum_b = 0;
                }
                if (lc == 0 && rc == 0) {
                    sum_c = 0;
                }
                break;
            }
            if (sum_c >= (tot + 2) / 3  && rc == 0) {
                lc = x;
                rc = i;
                s2 = sum_c;
                if (lb == 0 && rb == 0) {
                    sum_b = 0;
                }
                if (la == 0 && ra == 0) {
                    sum_c = 0;
                }
                break;
            }
            i++;
        }
        i++;
        x = i;

        while(i < n) {
            sum_a += a[i];
            sum_b += b[i];
            sum_c += c[i];
            if (sum_a >= (tot + 2) / 3 && ra == 0) {
                la = x;
                ra = n-1;
                s3 = sum_a;
                break;
            }
            if (sum_b >= (tot + 2) / 3  && rb == 0) {
                lb = x;
                rb = n-1;
                s3 = sum_b;
                break;
            }
            if (sum_c >= (tot + 2) / 3  && rc == 0) {
                lc = x;
                rc = n-1;
                s3 = sum_c;
                break;
            }
            i++;
        }

        cout << sum_a << " " << sum_b << " " << sum_c << endl;
        cout << s1 << " " << s2 << " " << s3 << endl;
        cout << la+1 << " " << ra+1 << " " << lb+1 << " " << rb+1 << " " << lc+1 << " " << rc+1 << endl;

        if (s1 < (tot + 2) / 3 || s2 < (tot + 2) / 3 || s3 < (tot + 2) / 3) {
            cout << -1 << endl;
        } else {
            cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
        }
    }

    return 0;
}