#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct elem
{
    int a = 0, b = 0, i = 0;
};

int main()
{
    int n = 0;
    cin >> n;
    vector<elem> A, B;
    A.reserve(n); ////////////////////////////////////////////////////////////////////////////////// reserve
    B.reserve(n);

    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = 0, y = 0;
        cin >> x >> y;

        if (x - y > 0)
        {
            A.push_back({x, y, i});
            sum += x - y;
        }
        else
        {
            B.push_back({x, y, i});
        }
    }

    int ff = A.size() - 1;
    for (int i = 0; i < ff; i++)
    {
        if (A[i].b > A[ff].b)
        {
            swap(A[i], A[ff]);
        }
        if (A[i].b == A[ff].b)
        {
            if (A[i].a > A[ff].a)
                swap(A[i], A[ff]);
        }
    }

    for (int i = 1; i < B.size(); i++)
    {
        if (B[0].a < B[i].a)
            swap(B[0], B[i]);
    }

    if (!A.empty() && !B.empty())
    {
        if (sum + A[ff].b > sum + B[0].a)
            cout << sum + A[ff].b << endl;
        else
            cout << sum + B[0].a << endl;
        for (int i = 0; i < A.size(); i++)
            cout << A[i].i << " ";
        for (int i = 0; i < B.size(); i++)
            cout << B[i].i << " ";
    }
    else if (!A.empty())
    {
        cout << sum + A[ff].b << endl;
        for (int i = 0; i < A.size(); i++)
            cout << A[i].i << " ";
    }
    else
    {
        cout << B[0].a << endl;
        for (int i = 0; i < B.size(); i++)
            cout << B[i].i << " ";
    }

    return 0;
}
