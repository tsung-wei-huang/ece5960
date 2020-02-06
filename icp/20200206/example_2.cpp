#include <iostream>
#include <algorithm>
#include <vector>

const int MAXV = 149997;		/* big prime */

#define MAXN 100010

/* For the input table */
typedef struct table_info
{
	int nb[6], hv;
}TABLE;

TABLE table[MAXN];

/* For the transformed hash table */
std::vector<int>hash[MAXV];

/* Find the corresponding value of in */
int hash_value(int in[])
{
	return ((in[0]+in[2]+in[4]) & (in[1]+in[3]+in[5])) % MAXV;
}

/* check if the same for table a and table b */
bool check(int tmp1[], int tmp2[])
{
	int i;
	for(i=0; i<6; i++) if(tmp1[i]!=tmp2[i]) return false;
	return true;
}

bool same(int a, int b)
{
	int tmp[6], i, s;

	/* for the six direction, s represents the shift */
	for(s=0; s<6; s++)
	{
		for(i=0; i<6; i++) tmp[i] = table[a].nb[(i+s)%6];
		if(check(tmp, table[b].nb)) return true;

		//reverse
		std::reverse(tmp, tmp+6);
		if(check(tmp, table[b].nb)) return true;
	}
	return false;
}

int main()
{

	int i, j, N, k;
	char input[100];

	while(std::cin >> N)
	{
		/* clear the data */
		for(i=0; i<MAXV; i++) hash[i].clear();

		/* read the table */
		for(i=0; i<N; i++)
		{
      for(int j=0; j<6; ++j) {
        std::cin >> table[i].nb[j];
      }
		}

		/* start to find the answer */
		bool isfind = false;
    
    // TODO
    // END-TODO

		if(isfind) std::cout << "Twin snowflakes found.\n";
		else std::cout << "No two snowflakes are alike.\n";
	}

	return 0;
}
