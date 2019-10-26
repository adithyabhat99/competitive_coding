//https://www.geeksforgeeks.org/game-theory-choice-area/
#include <bits/stdc++.h>
using namespace std;
class area
{
public:
    int a, b;
    area(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};
int max(int a, int b, int c)
{
    return max(a, max(b, c));
}
int maxSurvival(int A, int B, area &X, area &Y, area &Z, map<pair<int, int>, int> mem, int last)
{
    if (A <= 0 || B <= 0)
        return 0;
    pair<int, int> x = make_pair(A, B);
    if (mem.find(x) != mem.end())
    {
        return mem[x];
    }
    int t;
    switch (last)
    {
    case 1:
        t = 1 + max(maxSurvival(A + Y.a, B + Y.b, X, Y, Z, mem, 2), maxSurvival(A + Z.a, B + Z.b, X, Y, Z, mem, 3));
        break;
    case 2:
        t=1 + max(maxSurvival(A + X.a, B + X.b, X, Y, Z, mem, 1), maxSurvival(A + Z.a, B + Z.b, X, Y, Z, mem, 3));
        break;
    case 3:
        t=1 + max(maxSurvival(A + X.a, B + X.b, X, Y, Z, mem, 1), maxSurvival(A + Y.a, B + Y.b, X, Y, Z, mem, 2));
        break;
    default:
        break;
    }
    mem[x] = t;
    return t;
}
int getMax(int A, int B, area &X, area &Y, area &Z)
{
    if (A <= 0 || B <= 0)
        return 0;
    map<pair<int, int>, int> mem;
    return max(maxSurvival(A + X.a, B + X.b, X, Y, Z, mem, 1), maxSurvival(A + Y.a, B + Y.b, X, Y, Z, mem, 2), maxSurvival(A + Z.a, B + Z.b, X, Y, Z, mem, 3));
}
int main()
{
    int A, B, a1, a2, a3, b1, b2, b3;
    cout << "Enter 2 powers\n";
    cin >> A >> B;
    cout << "Enter powers of 3 areas(X,Y and Z)\n";
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    area X(a1, b1), Y(a2, b2), Z(a3, b3);
    cout << getMax(A, B, X, Y, Z) << endl;
    return 0;
}