// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/aplusb
#include "aplusb.hpp"

#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << aplusb(a,b) << '\n';
    return 0;
}