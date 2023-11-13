#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    string curr;
    vector<string> next;
    string before{};
};
unordered_map<string,int> visits;
unordered_map<string,vector<pair<int,string>>> nodes;
unordered_map<string,string> trace;
vector<string> res;
int WholeSize = 0;
bool flags = false;
int dfs(string str,int cnt)
{
    //cout << cnt << endl;
    if(WholeSize == cnt) {
        //if(res.size() > 0) return true;
        flags = true;
        res[cnt] = str;        
        return 1;
        
    }
    int ret = 0;
    for(auto& pairs : nodes[str])
    {
        auto next = pairs.second;
        //cout << next << endl;
        if(pairs.first == true)
           continue;
        pairs.first = true;
        if(flags == false)
            res[cnt] = str;
        trace[next] = str;
        ret = dfs(next,cnt + 1);
        if(ret == 0)
        {
            pairs.first = false;
        }
    }
    
    return ret;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    for(auto& ticket : tickets)
    {
        nodes[ticket[0]].push_back(make_pair(false,ticket[1]));
    }
    for(auto& p : nodes)
    {
        auto& vec = p.second;
        sort(vec.begin(),vec.end(),[](pair<int,string>& a, pair<int,string>& b){ 
        return a.second < b.second;        
        });
    }
    WholeSize = tickets.size();
    res.resize(WholeSize + 1);
    visits["ICN"] = 3;
    dfs("ICN",0);
    
    //reverse(res.begin(),res.end());
    return res;
}