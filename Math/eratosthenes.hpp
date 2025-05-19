#pragma once

#include <vector>

// 素因数分解 O(logN)，約数列挙
struct eratosthenes
{
    std::vector<bool> table;
    std::vector<int> minfactor;

    // table[i] == trueならばiは素数
    // minfactor[i] : iの最小素因数
    eratosthenes(int n) : table(n + 1, true),
                          minfactor(n + 1, -1)
    {
        table[1] = false;
        minfactor[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (!table[i])
                continue;
            minfactor[i] = i;
            for (int j = i * 2; j <= n; j += i)
            {
                table[j] = false;
                if (minfactor[j] == -1)
                {
                    minfactor[j] = i;
                }
            }
        }
        return;
    }

    // 素因数分解　クエリあたりO(log(N))
    std::vector<std::pair<int, int>> pf(int n)
    {
        if (n == 1)
        {
            return {{1, 1}};
        }
        std::vector<std::pair<int, int>> res;
        while (n > 1)
        {
            int p = minfactor[n];
            int cnt = 0;
            while (minfactor[n] == p)
            {
                n /= p;
                cnt++;
            }
            res.emplace_back(p, cnt);
        }
        return res;
    }

    // 約数列挙　クエリあたりO(σ(N)) (約数の個数 n<=10^9で最大1344)
    std::vector<int> divisors(int n)
    {
        std::vector<int> res({1});
        if (n == 1)
        {
            return res;
        }
        auto p_list = pf(n);
        for (auto p : p_list)
        {
            int s = (int)res.size();
            for (int i = 0; i < s; ++i)
            {
                int v = 1;
                for (int j = 0; j < p.second; ++j)
                {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};
