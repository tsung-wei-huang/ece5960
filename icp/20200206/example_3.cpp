#include <iostream>
#include <map>
#include <vector>

#define MAXN 100100
#define MAXK 31

int N, K;

/* For the hash map */
typedef struct NODE_INFO
{
	int bit[MAXK];
}NODE;

bool operator < (const NODE &a, const NODE &b)
{
	int i;
	for(i=0; i<K; i++)
		if(a.bit[i] != b.bit[i])
			return a.bit[i] < b.bit[i];
	return false;
}

std::map<NODE, int>code;
std::vector<int>level[MAXN];

/* for the input */
int table[MAXN], sum[MAXN][MAXK];

int main()
{

	int i, j, k, ans;
	NODE tmp;

	std::cin >> N >> K;

	/* read the input */
	for(i=1; i<=N; i++)
	{
		std::cin >> table[i];
	}

  // TODO
	/* start to trace */
	ans = 0;
  // END-TODO

	std::cout << ans << '\n';

	return 0;
}


