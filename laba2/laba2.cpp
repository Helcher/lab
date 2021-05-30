#include <iostream>
#include <limits>
#include <Windows.h>
#include <iomanip>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int Vmin, TS = 100000, S, N, A[100][100] = {};
    cout << "Введите количесво вершин" << endl;
    cin >> N; // Ввод количества вершин
    cout << "Введите матрицу смежности" << endl;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
        }
    // Алгоритм Флойда-Уоршелла
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);

    for (int i = 0; i < N; ++i)
    {
        S = 0;
        for (int j = 0; j < N; ++j)
            S += A[i][j];
        if (S < TS)
        {
            TS = S;
            Vmin = i;
        }
    }

    int s, n;
    cout << endl;
    cout << "Введите столицу" << endl;
    cin >> s;
    s--;
    cout << "Введите N" << endl;
    cin >> n;
    cout << "N-переферия" << endl;
    for (int i = 0; i < N; i++) {
        if (A[s][i] > n)
            cout << i + 1 << " ";

    }
    cin.get();
    return 0;
}



