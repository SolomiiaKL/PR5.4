// Lab_05_4.cpp
// < Клак Соломія >
// Лабораторна робота № 5.4
// Варіант 14

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double term(int i)
{
    return (i + 1.0 / (i * i)) / sqrt(1.0 + exp(1.0 / i));
}

double S0(const int N)
{
    double p = 1.0;
    for (int i = N; i <= 10; i++)
        p *= term(i);
    return p;
}

double S1(const int N, const int i)
{
    if (i > 10)
        return 1.0;
    else
        return term(i) * S1(N, i + 1);
}

double S2(const int N, const int i)
{
    if (i < N)
        return 1.0;
    else
        return term(i) * S2(N, i - 1);
}

double S3(const int N, const int i, double t)
{
    if (i > 10)
        return t;
    else
        return S3(N, i + 1, t * term(i));
}

double S4(const int N, const int i, double t)
{
    if (i < N)
        return t;
    else
        return S4(N, i - 1, t * term(i));
}

int main()
{
    int N;
    cout << "N = "; cin >> N;

    if (N < 1 || N > 10)
    {
        cout << "Error: N must be in the range 1...10" << endl;
        return 1;
    }

    cout << fixed << setprecision(10);
    cout << "(iter)             S0 = " << S0(N) << endl;
    cout << "(rec up ++)        S1 = " << S1(N, N) << endl;
    cout << "(rec up --)        S2 = " << S2(N, 10) << endl;
    cout << "(rec down ++)      S3 = " << S3(N, N, 1.0) << endl;
    cout << "(rec down --)      S4 = " << S4(N, 10, 1.0) << endl;

    return 0;
}