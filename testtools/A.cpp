#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
/*
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize(3)
*/
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
const ll MAX_INT = 0x3f3f3f3f;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const ll CF = 2e5 + 9;
const ll mod = 1e9 + 7;
// 函数：生成随机字符串
std::string GenerateRandomString(size_t min_length, size_t max_length) {
    const std::string chars =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> length_distribution(min_length, max_length);
    std::uniform_int_distribution<> char_distribution(0, chars.size() - 1);

    size_t length = length_distribution(generator);
    std::string random_string;
    for (size_t i = 0; i < length; ++i) {
        random_string += chars[char_distribution(generator)];
    }
    return random_string;
}

// 函数：生成 SQL 插入语句
std::string GenerateInsertStatement() {
    std::string schoolNumber = GenerateRandomString(5, 12);
    std::string password = GenerateRandomString(5, 12);

    std::string sql = "INSERT INTO logins (authority, schoolNumber, passWord) VALUES (0, '" +
                      schoolNumber + "', '" + password + "');";
    return sql;
}
int main()
{
	freopen("datasheet1.txt","w",stdout);
	for(int i = 1; i <= 200; i++) 
	{
		std::string sql = GenerateInsertStatement();
		std::cout << sql << '\n';
	}
    return 0;
}


