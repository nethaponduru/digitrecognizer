/*
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,count=0;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    sort(a,a+n);
    do{
        count++;
        if(count==k){
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout << endl;
        }
    }while(next_permutation(a,a+n));
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}

#include<bits/stdc++.h>
using namespace std;
char arr[8][8];
vector<int>queens;

bool is_valid(int row , int col){
    if(arr[row][col]=='*') return 0;
    for(int pr=0;pr<queens.size();pr++){
        int pc=queens[pr];
        if(col==pc){
            
            return 0;
        }
        if(abs(pr-row)==abs(pc-col)){
            return 0;
        }
    }
    return 1;
}
int rec(int level){
    if(level==8){
        return 1;
    }
    int ans=0;
    for(int col=0;col<8;col++){
        if(is_valid(level,col)){
            queens.push_back(col);
            ans+=rec(level+1);
            queens.pop_back();
        }
    }
    return ans;
}

void solve(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>arr[i][j];
        }
    }
    cout<<rec(0)<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    vector<int> fact(14);
    fact[0] = 1;
    for (int i = 1; i <= 13; i++) {
        fact[i] = fact[i - 1] * i;
    }
    int start = max(0, n - 13);
    for (int i = start; i < n && k > 1; i++) {
        int pos = (k - 1) / fact[n - 1 - i];
        swap(a[i], a[i + pos]);
        sort(a.begin() + i + 1, a.end());
        k -= pos * fact[n - 1 - i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<int>queens;
int n;
bool is_valid(int row , int col){
    for(int pr=0;pr<queens.size();pr++){
        int pc=queens[pr];
        if(col==pc){
            
            return 0;
        }
        if((abs(pr-row)==abs(pc-col))||((abs(pr-row)==2 && abs(pc-col)==1)||abs(pr-row)==1 && abs(pc-col)==2)){
            return 0;
        }
    }
    return 1;
}
int rec(int level){
    if(level==n){
        return 1;
    }
    int ans=0;
    for(int col=0;col<n;col++){
        if(is_valid(level,col)){
            queens.push_back(col);
            ans+=rec(level+1);
            queens.pop_back();
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    cout<<rec(0)<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}


#include<bits/stdc++.h>
using namespace std;
int n;
int count=0;
vector<char> v;

vector<char> rec(int level){
    if(level==n){
        if(count==0) return v;
        else return;
    }
    count=0;
    v.push_back('(');
    count++;
    rec(level+1);
    v.pop_back();
    v.push_back(')');
    count--;
    rec(level+1);
}

void solve(){
    vector<char> c;
    cin>>n;
    c=rec(0);
    for(auto v: c){
        cout<<v;
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateParenthesis(int n, int open, int close, string str, vector<string> &result) {
    if (close == n) {
        result.push_back(str);
        return;
    }
    if (open < n) {
        generateParenthesis(n, open + 1, close, str + '(', result);
    }
    if (open > close) {
        generateParenthesis(n, open, close + 1, str + ')', result);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> result;
    generateParenthesis(n / 2, 0, 0, "", result);
    for (const string &str : result) {
        cout << str << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i ++) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimePalindromes(int a, int b) {
    int count = 0;
    if (a <= 11 && b >= 11) {
        count++;
    }
    for (int i = 1; i < 100000; i++) {
        string s = to_string(i);
        string r = s;
        reverse(r.begin(), r.end());
        int num = stoi(s + r.substr(1));
        if (num >= a && num <= b && isPrime(num)) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b;
    cin>>a>>b;
    cout << countPrimePalindromes(a, b) << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[10000];
map<int,int> m;
bool is_possible(){
    for(int b=n-2;b>=0;b--){
        for(int a1=b-1;a1>=0;a1--){
            if(m[x-a[a1]-a[b]]){
                return 1;
            }
        }
        int c=b;
        for(int d=c+1;d<n;d++){
            m[a[d]+a[c]]=1;
        }
    }
    return 0;
}
void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(is_possible())  cout<<"YES";
    else cout<<"NO";


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}


#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[40];

vector<int> subsetsums(vector<int> r){
    vector<int> p;
    for(int i=0;i<(1<<r.size());i++){
        long long int sum=0;
        for(int j=0;j<r.size();j++){
            if((i>>j)&1){
                sum+=r[j];
            }
        }
        p.push_back(sum);
    }
    return p;
}
void solve(){
    vector<vector<int>>v(2);
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        v[i&1].push_back(a[i]);
    }
    vector<int> p1=subsetsums(v[0]);
    vector<int> p2=subsetsums(v[1]);
    sort(p2.begin(),p2.end());
    long long int sum=0;
    for(auto v:p1){
        auto k=upper_bound(p2.begin(),p2.end(),x-v)-p2.begin();
        sum+=k;
    }
    cout<<sum<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[40];

vector<int> subsetsums(vector<int> r){
    vector<int> p;
    for(int i=0;i<(1<<r.size());i++){
        long long int sum=0;
        for(int j=0;j<r.size();j++){
            if((i>>j)&1){
                sum+=r[j]%m;
            }
        }
        p.push_back(sum%m);
    }
    return p;
}
void solve(){
    vector<vector<int>>v(2);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        v[i&1].push_back(a[i]);
    }
    vector<int> p1=subsetsums(v[0]);
    vector<int> p2=subsetsums(v[1]);
    sort(p2.begin(),p2.end());
    int y=0;
    for(auto v:p1){
        auto it=lower_bound(p2.begin(),p2.end(),m-v);
        it--;
        y=max(y,(v+*it)%m);
    }
    cout<<y;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}

#include<bits/stdc++.h>
using namespace std;

void multiply(int *A, int *B, int *result, int n) {
    if (n == 1) {
        result[0] = A[0] * B[0];
        return;
    }

    int mid = n / 2;
    int *Al = new int[mid];
    int *Ar = new int[mid];
    int *Bl = new int[mid];
    int *Br = new int[mid];

    for (int i = 0; i < mid; i++) {
        Al[i] = A[i];
        Ar[i] = A[i + mid];
        Bl[i] = B[i];
        Br[i] = B[i + mid];
    }

    int *P1 = new int[n]();
    int *P2 = new int[n]();
    int *P3 = new int[n]();
    int *P4 = new int[n]();

    multiply(Al, Bl, P1, mid);
    multiply(Ar, Br, P2, mid);

    for (int i = 0; i < mid; i++) {
        Al[i] += Ar[i];
        Bl[i] += Br[i];
    }

    multiply(Al, Bl, P3, mid);

    for (int i = 0; i < n; i++) {
        P4[i] = P3[i] - P1[i] - P2[i];
    }

    for (int i = 0; i < n; i++) {
        result[i] += P1[i];
        result[i + n / 2] += P4[i];
        result[i + n] += P2[i];
    }
}

void solve(){
    int n;
    cin>>n;
    
    // Find the smallest power of 2 greater than or equal to n+1
    int m = 1;
    while (m < n+1) m *= 2;
    
    // Dynamically allocate memory for the arrays
    int* a = new int[m]{0};
    int* b = new int[m]{0};
    
    // Initialize the result array with zeros
    int* result = new int[2*m]{0};
    
    for(int i=0;i<n+1;i++){
        cin>>a[i];
    }
    
    for(int i=0;i<n+1;i++){
        cin>>b[i];
    }
    
    multiply(a,b,result,m);
    
    for(int i=0;i<2*n+1;i++){
        cout<<result[i]<<" ";
    }
}

signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    
   int t;
    
   cin>>t;
    
   while(t--){
       solve();
       cout<<endl;
   }
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;
vector<int> vis;
void dfs(int node,int comp){
    vis[node]=comp;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,comp);
        }
    }
}
void solve(){
    int q;
    cin>>n>>m>>q;
    g.reserve(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int num_comp=0;
    vector<int> comp_size(n+1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            num_comp++;
            dfs(i,num_comp);
        }
    }
    for(int i=1;i<=n;i++){
        comp_size[vis[i]]++;
    }
    while(q--){
        int num;
        cin>>num;
        if(num==1){
            int x;
            cin>>x;
            cout<<comp_size[vis[x]]<<endl;
        } 
        if(num==2){
            int x,y;
            cin>>x>>y;
            if(vis[x]==vis[y]){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;
        }  
    }
}
    

signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    
   int t=1;
    
   //cin>>t;
    
   while(t--){
       solve();
   }
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;
vector<int>parent;
vector<int> col;
bool is_cycle=0;
void dfs(int node,int par){
    parent[node]=par;
    col[node]=2;
    for(auto v:g[node]){
        if(v==parent[node]) continue;
        if(col[v]==1){
            dfs(v,node);
        }else if(col[v]==2){
            is_cycle=1;
        }
    }
    col[node]=3;
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //dfs(1,0);
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i,0);
        }
    }
    if(is_cycle) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    
   int t=1;
    
   //cin>>t;
    
   while(t--){
       solve();
   }
}
*/
/*
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

int n, m, rooms;
vector<vector<bool>> vis;

vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
bool isValid(int x, int y)
{
	if(x<0 or x >= n or y <0 or y>=m)
		return false;
	if(vis[x][y])
		return false;
	return true;
}
void dfs(int i, int j)
{
	vis[i][j] = true;
	for(auto p: moves)
	{
		if(isValid(i+p.first, j+p.second))
		{
			dfs(i+p.first, j+p.second);
		}
	}
}
void connected_components()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!vis[i][j])
			{
				dfs(i,j);
				++rooms;
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vis.resize(n);

	for(int i = 0; i < n; ++i)
	{
		vis[i].resize(m);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char c; cin >> c;
			if(c == '#')
			{
				vis[i][j] = true;
			}
		}
	}
	connected_components();
	cout << rooms << endl;
}

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> nodes_in_component;

void dfs(int node,int comp){
    vis[node]=comp;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,comp);
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    nodes_in_component.assign(n+1,0);

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp++;
            dfs(i,comp);
        }
    }
    for(int i=1;i<=n;i++){
        nodes_in_component[vis[i]]++;
    }
    long long int ans=0;
    long long int sum=0;
    for(int i=1;i<=n;i++){
        ans+=nodes_in_component[i]*sum;
        sum+=nodes_in_component[i];
    }

    cout<<ans<<endl;
}

signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    
   int t=1;
    
   //cin>>t;
    
   while(t--){
       solve();
   }
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;
vector<int> col;
bool is_cycle=0;
void dfs(int node){
    col[node]=2;
    for(auto v:g[node]){
        if(col[v]==1){
            dfs(v);
        }else if(col[v]==2){
            is_cycle=1;
        }
    }
    col[node]=3;
}
void solve(){
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    col.assign(n+1,1);
    is_cycle = 0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    //dfs(1,0);
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i);
        }
    }
    if(is_cycle) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    
   int t;
    
   cin>>t;
    
   while(t--){
       solve();
       
   }
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second 
using ii=pair<int,int>;
int n,m;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
vector<string> arr;
bool inside(int x,int y){
    if(x<0||x>=n||y<0||y>=m||arr[x][y]=='#') return 0;
    else return 1;
}
int arr[1010][1010];
int par[1010][1010];
void bfs(int st){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dis[i][j]=1e9;
        }
    }
    dis[st.F][st.S]=0;
    queue<ii> q;
    q.push(st);
    while(!q.empty()){
        ii cur=q.front();
        q.pop();
        int curd=dis[curr.F][cur.S];
        for(int k=0;k<4;k++){
            if(!inside(cur.F+dx[k],curr,S+dy[k])) continue;
            ii neigh={cur.F+dx[k],curr,S+dy[k]};
            if(dis[neigh.F][neigh.S]>curd+1){
                dis[neigh.F][neigh.S]=curd+1;
                par[neigh.F][neigh.S]=cur;
                q.push(neigh);
            }
        }
    }
}
void solve(){
    vector<ii> mons;
    vector<ii> boun;
    vector<vector<int>> dis;
    cin>>n>>m;
    arr.resize(n);
    ii st;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                st={i,j};
            }else if(arr[i][j]=='M'){
                mons.push_back(make_pair(i,j));
            }else if((i=0  || i=n-1 ||j=0 ||j=n-1)&&arr[i][j]=='.'){
                boun.push_back(make_pair(i,j));
            }
        }
    }
    
    bfs[st];
    for(aauto v:boun){
        ii tempA=v;
        vector<pair<int,ii>> pathA;
        wile(tempA!=st){
            pathA.F.push_back(dis[tempA.F][tempA.S]);
            pathA.S.push_back(tempA);
            temp=par[tempA.F][tempA.S];
        }
        pathA.S.push_back(st);
        reverse(pathA.begin(),pathA.end());
    }
    vector<vector<int>> paths;
    for(auto stm:mons){

        bts(stm);
        for(auto v:boun){
            if(dis[v.F][v.S]!=1e9){
                ii temp=v;
                vector<pair<int,ii> path;
                wile(temp!=v){
                    path.F.push_back(dis[temp.F][temp.S]);
                    path.S.push_back(temp);
                    temp=par[temp.F][temp.S];
                }
                path.S.push_back(v);
                reverse(path.begin(),path.end());
                paths.push_back(path);
            }
        }
    }

}

signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    
   int t=1;
    
   //cin>>t;
    
   while(t--){
       solve();
       
   }
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node,int comp){
    vis[node]=comp;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,comp);
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int num_comp=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            num_comp++;
            dfs(i,num_comp);
        }
    }
    cout<<num_comp-1<<endl;
}

signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    
   int t=1;
    
   //cin>>t;
    
   while(t--){
       solve();
   }
}
*/

#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;
vector<int>parent;
vector<int> col;
bool is_cycle=0;
void dfs(int node,int par){
    parent[node]=par;
    col[node]=2;
    for(auto v:g[node]){
        if(v==parent[node]) continue;
        if(col[v]==1){
            dfs(v,node);
        }else if(col[v]==2){
            is_cycle=1;
        }
    }
    col[node]=3;
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //dfs(1,0);
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i,0);
        }
    }
    if(is_cycle) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
    
   int t=1;
    
   //cin>>t;
    
   while(t--){
       solve();
   }
}