// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3410/
#include <bits/stdc++.h>
using namespace std;
class MyHashSet
{
public:
    int *set;
    int m;
    MyHashSet()
    {
        m = 10000;
        set = new int[m];
        for (int i = 0; i < m; i++)
        {
            set[i] = -2;
        }
    }
    int hash(int key, int i)
    {
        // quadratic probing
        return (key % m + i * i) % m;
    }
    void add(int key)
    {
        int i = 0;
        while (i < m)
        {
            int pos = hash(key, i);
            if (set[pos] == -2 || set[pos] == -1 || set[pos] == key)
            {
                set[pos] = key;
                break;
            }
            i++;
        }
    }

    void remove(int key)
    {
        int i = 0;
        while (i < m)
        {
            int pos = hash(key, i);
            if (set[pos] == key)
            {
                set[pos] = -1;
                break;
            }
            i++;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int i = 0;
        while (i < m)
        {
            int pos = hash(key, i);
            if (set[pos] == key)
            {
                return true;
            }
            if (set[pos] == -2)
            {
                return false;
            }
            i++;
        }
        return false;
    }
};
int main()
{
    MyHashSet m;
    m.add(1);
    m.add(2);
    cout << m.contains(1) << endl
         << m.contains(3) << endl;
    m.add(3);
    m.add(2);
    cout << m.contains(2) << endl;
    m.remove(2);
    cout << m.contains(2) << endl;
    return 0;
}