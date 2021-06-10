#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a,int idx = 0)
{
    if(idx == a.size())
    {
        ans.push_back(a);
        return;
    }

    for(int i = idx;i<a.size();i++)
    {
        swap(a[i],a[idx]);
        permute(a,idx+1);
        swap(a[i],a[idx]);
    }
    return;
}

void permute_stl(vector<int> a)
{
    
    sort(a.begin(),a.end());

    do
    {
        ans.push_back(a);

    } while (next_permutation(a.begin(),a.end()));
    
}

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(auto &i : a)
        cin>>i;

    permute_stl(a);

    for(auto v : ans)
    {
        for(auto i:v)
            cout<<i<<" ";

        cout<<"\n";
    }

    return 0;
}