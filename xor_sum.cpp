#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<bitset>
#include<sstream>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
const int N=100010;
typedef long long ll;
const ll o=1;
struct node
{
	int next[2];
	void init(){
		next[0]=next[1]=-1;
	}
};
class trie
{
	public:
		node tree[N*44];
		int cnt;
	public:
		void init() {
			cnt=1;
			for(int i=0;i<N*44;i++)
				tree[i].init();
		}
		void insert(ll val)
		{
			int u=0;
			for(int i=44;i>=0;i--)
			{
				int id=((o<<i)&val)!=0;
				if(tree[u].next[id]==-1)
					tree[u].next[id]=cnt++;
				u=tree[u].next[id];
			}
		}
		ll find(ll val)
		{
			ll res=0;
			int u=0;
			for(int i=44;i>=0;i--)
			{
				int id=((o<<i)&val)==0;
				if(tree[u].next[id]==-1)
					id=id^1;
				res=res*2LL+id;
				u=tree[u].next[id];
			}
			return res;
		}
};
ll a[N];
trie tree;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int t;
	int n,m;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%d%d",&n,&m);
		tree.init();
		for(int i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
			tree.insert(a[i]);
		}
		ll q;
		printf("Case #%d:\n",c);
		while(m--)
		{
			scanf("%I64d",&q);
			ll res=tree.find(q);
			printf("%I64d\n",res);
		}
	}
	return 0;
}
