#include<iostream>
using namespace std;

int main()
{
    int n, i, j, k;
    cout << "Enter total numbers of vertices: ";
    cin >> n;
    int a[n][n];
    cout << "Enter the value of cast matrix: ";
    for (i = 0; i < n; i++) {
        cout << "Enter the value of the " << i + 1 << " row " << endl;
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    cout << "Output Matrix" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
