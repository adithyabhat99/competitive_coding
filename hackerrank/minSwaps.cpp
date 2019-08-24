// https://www.hackerrank.com/challenges/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    pair<int,int>p[arr.size()];
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        p[i].first=arr[i];
        p[i].second=i;
    }
    sort(p,p+arr.size());
    vector<bool> visited(arr.size());
    fill(visited.begin(),visited.end(),false);
    for(int i=0;i<arr.size();i++)
    {
        if(p[i].second==i || visited[i])
        {
            continue;
        }
        int j=i;
        int cycle=0;
        while(!visited[j])
        {
            visited[j]=true;
            cycle++;
            j=p[j].second;
        }
        ans+=(cycle>0)?(cycle-1):0;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

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

