#include <bits/stdc++.h>
#include <time.h>
using namespace std;
/* Test Cases:
01Dec2019
05Dec2019
02Dec2019
06Dec2019
(answer:4)

02Dec2019
06Dec2019
01Dec2019
05Dec2019
(answer:4)

01Dec2019
05Dec2019
01Dec2020
05Dec2020
(answer:0)
*/
class Date
{
    map<string, int> months;
    void setMonths()
    {
        months["Jan"] = 1;
        months["Feb"] = 2;
        months["Mar"] = 3;
        months["Apr"] = 4;
        months["May"] = 5;
        months["Jun"] = 6;
        months["Jul"] = 7;
        months["Aug"] = 8;
        months["Sep"] = 9;
        months["Oct"] = 10;
        months["Nov"] = 11;
        months["Dec"] = 12;
    }

public:
    string d;
    time_t time;
    Date(string d)
    {
        this->d = d;
        setMonths();
        // extract day,month and year
        int day = atoi(d.substr(0, 2).c_str());
        int month = months[d.substr(2, 3)];
        int year = atoi(d.substr(5, 4).c_str());
        // time structure(similar to Date in java)
        struct tm tStructure = {0};
        tStructure.tm_mday = day;
        tStructure.tm_mon = month - 1;
        tStructure.tm_year = year - 1900;
        tStructure.tm_isdst = -1;
        // convert timeStructure to time_t
        time = mktime(&tStructure);
        // cout<<time<<endl;
    }
    bool operator>=(Date &D)
    {
        return this->time >= D.time;
    }
};
// void swap(Date &a, Date &b)
// {
//     Date temp = a;
//     a = b;
//     b = temp;
// }
int numberOfDays(Date a, Date b)
{
    // if (b >= a)
    // {
    //     swap(a, b);
    // }
    // Make sure that 'b' is always >= 'a'. Otherwise uncomment swap function
    int seconds = difftime(a.time, b.time);
    int days = round(seconds / (24.0 * 60 * 60));
    return days + 1;
}
bool overlapOrNot(Date &c1, Date &c2, Date &d1, Date &d2)
{
    if (c2 >= d1 && d1 >= c1)
        return true;
    if (d2 >= c1 && c1 >= d1)
        return true;
    return false;
}
int findDays(Date &c1, Date &c2, Date &d1, Date &d2)
{
    // First we need to know if these intervals overlap or not.
    if (!overlapOrNot(c1, c2, d1, d2))
    {
        return 0;
    }
    if (c2 >= d1 && d1 >= c1)
    {
        return numberOfDays(c2, d1);
    }
    if (d2 >= c1 && c1 >= d1)
    {
        return numberOfDays(d2, c1);
    }
    return 0;
}
int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    Date c1(a), c2(b), d1(c), d2(d);
    cout << findDays(c1, c2, d1, d2) << endl;
    return 0;
}