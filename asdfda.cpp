#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define endl "\n"
#define pb push_back
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define mi map<int,int>
#define read(a,n) FOR(i,0,n){cin>>a[i];}
#define write(a) FOR(i,0,a.size()) {cout<<a[i]<<" ";}cout<<endl
#define all(v) v.begin(),v.end() 
#define INF LLONG_MAX
ll mod=998244353;
ll mod2=1000000009;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct HASH{
	static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
  size_t operator()(const pair<int,int>&x)const{
  	static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return hash<long long>()(((long long)splitmix64(x.first+FIXED_RANDOM)))^(((long long)splitmix64(x.second+FIXED_RANDOM)<<32));
  }
};
int lcm(int a, int b)
{
	return a/__gcd(a,b)*b;
}

int inv(int a,int mod) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a,mod) % mod;
}

int modexpo(int base,int power)
{
	if(power<0)
		return 0;
	if(power==0)
		return 1ll;
	if(power==1)
		return base;
	int temp=modexpo(base,power/2);
	temp=(temp*temp)%mod;
	if(power%2)
	{
		return (temp*base)%mod;
	}
	else
		return temp;
}
void kmp(vi &pref,string s)
{
	pref[0]=0;
	int n=s.size();
	int i=1;
	while(i<n)
	{
		int j=i-1;
		while(s[pref[j]]!=s[i]&&pref[j]!=0)
		{
			j=pref[j]-1;
		}
		if(s[pref[j]]==s[i])
			pref[i]=pref[j]+1;
		else
			pref[i]=0;
		i++;
	}
}

void zfunction(vi &zfunc,string s)
{
	int n=s.size();
	zfunc[0]=0;
	int left=1,right=-1;
	FOR(i,1,n)
	{
		if(s[i]==s[i-1])
		{
			zfunc[1]++;
		}
		else
		{
			right=i;
			break;
		}
	}
	if(right==-1)
		right=n;
	FOR(i,2,n)
	{
		if(i>=right)
		{
			left=i;
			int x=i;
			while(x<n)
			{
				if(s[x]==s[x-i])
					zfunc[i]++;
				else
				{
					break;
				}
				x++;
			}
			right=x;
		}
		else
		{
			zfunc[i]=min(zfunc[i-left],right-i);
			int x=i+zfunc[i];
			while(x<n)
			{
				if(s[x]==s[x-i-1])
					zfunc[i]++;
				else
					break;
			}
			if(x>right)
			{
				left=i;
				right=x;
			}
		}
	}
}
/*int tarjan(vi (&g)[],int current,int parent)
{
	visited[current]=1;
	tin[current]=t;
	lotin[current]=t;
	t++;
	int ans=0;
	FOR(i,0,g[current].size())
	{
		if(g[current][i]!=parent)
		{
			if(visited[g[current][i]]==0)
			{
				ans+=dfs(g,g[current][i],current);
			}
				lotin[current]=min(lotin[current],lotin[g[current][i]]);
		}
	}
	subtree[current]=1+ans;
	return 1+ans;
}*/




int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;   

    
    int cnt = 0;


    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; 
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  
    cnt += mergeSort(arr, mid + 1, high); 
    cnt += merge(arr, low, mid, high);  
    return cnt;
}
/*vi fact((int)1e5+5),invfact((int)1e5+5);
int C(int n,int r)
{
	if(r<0)
		return 0;
	if(n<0)
		return 0;
	if(r>n)
		return 0;
	return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
}*/
vector<vi> matmult(vector<vi> a,vector<vi>b)
{
	vector<vi> result;
	result.resize(a.size());
	FOR(i,0,a.size())
	{
		result[i].resize(b.size());
	}
	if(a[0].size()!=b.size())
	{
		cout<<"Matmult error"<<endl;
		return result;
	}
	int n=a.size();
	int m=b[0].size();
	int l=b.size();
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			FOR(k,0,l)
			{
				result[i][j]+=a[i][k]*b[k][j];
				result[i][j]=result[i][j]%mod;
			}
		}
	}
	return result;
}
vector<vi> matexpo(vector<vi> &base,int power)
{
	if(power==1)
	{
		return base;
	}
	if(power%2)
	{
		return matmult(matexpo(base,power-1),base);
	}
	else
	{
		vector<vi> temp = matexpo(base,power/2);
		return matmult(temp,temp);
	}
}

int min(int a,int b,int c)
{
	return min(min(a,b),c);
}
int min(int a,int b,int c,int d)
{
	return min(a,min(b,c,d));
}
struct trienode{
	trienode* left,*right;
	int val;
};
trienode* createnode()
{
	trienode* retval=new trienode;
	retval->left=NULL;
	retval->right=NULL;
	retval->val=0;
	return retval;
}
void inserttrie(int n, trienode* root,int &ans)
{
	int onecount=0;
	for(int i=29;i>=0;i--)
	{
		if(((n>>i)&1)==1)
		{
			if(root->left!=NULL)
			{
				ans=(ans+root->left->val*(2*onecount+3)%mod)%mod;
			}
			onecount++;
			if(root->right==NULL)
			{
				root->right=createnode();
			}
			root=root->right;
			root->val+=1;
		}
		else
		{
			if(root->right!=NULL)
			{
				ans=(ans+root->right->val*(2*onecount+3)%mod)%mod;
			}
			if(root->left==NULL)
			{
				root->left=createnode();
			}
			root=root->left;
			root->val+=1;
		}
	}
	ans=(ans+(onecount+1)+(root->val-1)*2*(onecount+1)%mod)%mod;
}
int maxxor(int n,trienode* root)
{
	int retval=0;
	for(int i=17;i>=0;i--)
	{
		if((n>>i)&1==1)
		{
			if(root->left!=NULL)
			{
				root=root->left;
				retval+=1<<i;
			}
			else
			{
				root=root->right;
			}
		}
		else
		{
			if(root->right!=NULL)
			{
				root=root->right;
				retval+=1<<i;
			}
			else
			{
				root=root->left;
			}
		}
	}
	return retval;
}

void updateseg(vi &segtree,int index,int rangelow,int rangehigh,int querylow,int queryhigh,int value)
{
	if(querylow>queryhigh)
		return;
	if(querylow<=rangelow&&queryhigh>=rangehigh)
	{
		segtree[index]=min(segtree[index],value);
		return;
	}
	if(rangehigh<querylow||rangelow>queryhigh)
	{
		return;
	}
	segtree[2*index]=min(segtree[2*index],segtree[index]);
	segtree[2*index+1]=min(segtree[2*index+1],segtree[index]);
	updateseg(segtree,2*index,rangelow,(rangelow+rangehigh)/2,querylow,queryhigh,value);
	updateseg(segtree,2*index+1,(rangelow+rangehigh)/2+1,rangehigh,querylow,queryhigh,value);
}

int get(vi &parents,int element)
{
	if(parents[element]==element)
	{
		return element;
	}
	return parents[element]=get(parents,parents[element]);
}
void merge(vi &parents,vi&size,vector<set<pair<int,int>>> &neighbours, int a,int b)
{
	int par1=get(parents,a),par2=get(parents,b);
	if(par1!=par2)
	{
		for(auto elem:neighbours[par2])
		{
			if(get(parents,elem.second)!=par1)
			{
				neighbours[par1].insert(elem);
			}
		}
		size[par1]+=size[par2];
		parents[par2]=par1;
	}
}
int queryseg1(vi &segtree,int index,int rangelow,int rangehigh,int query)
{
	if(rangehigh<=query)
	{
		return segtree[index];
	}
	if(rangelow>query)
		return 0;
	return queryseg1(segtree,2*index,rangelow,(rangelow+rangehigh)/2,query)+queryseg1(segtree,2*index+1,(rangelow+rangehigh)/2+1,rangehigh,query);
}
int queryseg2(vi&segtree,int index,int rlow,int rhigh,int query)
{
	if(2*index>segtree.size())
		return rlow;
	if(segtree[2*index]>=query)
	{
		return queryseg2(segtree,2*index,rlow,(rlow+rhigh)/2,query);
	}
	else
	{
		return queryseg2(segtree,2*index+1,(rlow+rhigh)/2+1,rhigh,query-segtree[2*index]);
	}
}
int timer=0;


int queryseg(vi &segtree,int index,int qlow,int qhigh,int rlow,int rhigh)
{
	if(qlow<=rlow&&qhigh>=rhigh)
		return segtree[index];
	if(qlow>rhigh||qhigh<rlow)
		return 0;
	return queryseg(segtree,2*index,qlow,qhigh,rlow,(rlow+rhigh)/2)+queryseg(segtree,2*index+1,qlow,qhigh,(rlow+rhigh)/2+1,rhigh);
}
int getdepth(vi &depth,vi &parents,int i)
{
	if(depth[i]!=-1)
		return depth[i];
	return depth[i]=getdepth(depth,parents,parents[i])+1;
}
int querysparse(vector<vi> &sparse,int l,int r)
{

	int val=0;
	while((1<<(val+1))<=r-l+1)
		val++;
	return __gcd(sparse[l][val],sparse[r-(1<<val)+1][val]);

}

void knapsackinsert(vi&knapsack,int weight)
{
	int n=knapsack.size();
	for(int i=n-1-weight;i>=0;i--)
	{
		knapsack[i+weight]=(knapsack[i+weight]+knapsack[i])%mod;
	}
}
void knapsackremove(vi&knapsack,int weight)
{
	int n=knapsack.size();
	FOR(i,0,n-weight)
	{
		knapsack[i+weight]=(knapsack[i+weight]-knapsack[i]+mod)%mod;
	}
}
int csqrt(int x)
{
	int l=1,r=2e9;
	while(r>l)
	{
		int mid=(l+r+1)/2;
		if(mid*mid>x)
		{
			r=mid-1;
		}
		else
		{
			l=mid;
		}
	}
	return l;
}
void solve()
{
	int k;
	cin>>k;
	int l=1,r=2e18;
	while(r>l)
	{
		int mid=(l+r)/2;
		int temp=mid-csqrt(mid);
		if(temp>=k)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<l<<endl;
}

//lower bound gives equal or greater
//upper bound gives strictly greater
int32_t main()
{
	auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   	int testcases=1;
   	if(1)
   		cin>>testcases;
   	while(testcases--)
   	{
   		solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}