#include <iostream>
using namespace std;
#include <vector>

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int>b(n);

    for (int i = 1; i < n; i++)
    {
        int cout = 0;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {

                cout++;
            }
        }
        b[i] = cout;

    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << (i == n - 1 ? "" : " ");
    }


    return 0;
}
// 64 位输出请用 printf("%lld")