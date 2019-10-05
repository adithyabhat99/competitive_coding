// https://www.hackerrank.com/challenges/find-maximum-index-product/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int solve(vector<int> arr) {
    int n=arr.size();
    stack<int> lstack;
    vector<int> lar;
    for(int i=0;i<n;i++)
    {
        while(!lstack.empty() && arr[lstack.top()-1]<=arr[i])
        {
            lstack.pop();
        }
        if(lstack.empty())
            lar.push_back(0);
        else
            lar.push_back(lstack.top());
        lstack.push(i+1);
    }
    vector<int> rar(n);
    stack<int> rstack;
    for(int i=n-1;i>=0;i--)
    {
        while(!rstack.empty() && arr[rstack.top()-1]<=arr[i])
        {
            rstack.pop();
        }
        if(rstack.empty())
            rar[i]=0;
        else
            rar[i]=rstack.top();
        rstack.push(i+1);
    }
    int m=-100;
    for(int i=0;i<n;i++)
    {
        m=max(m,(lar[i]*rar[i]));
    }
    return m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    int result = solve(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}