#include <iostream>

#define MAXN 31000

int p[MAXN], rank[MAXN], size[MAXN], ans[MAXN];

// TODO
void makeset()
{
}

int findset(int a)
{
}

void link(int x, int y)
{
}

void unionset(int x, int y)
{
}
// END-TODO

int main() {
	int i, j, datacase, N, M, a, b, len;

  std::cin >> datacase;

	while(datacase--)
	{
    std::cin >> N >> M;

		makeset();

		for(i=0; i<M; i++)
		{
      std::cin >> a >> b;
			unionset(a, b);
		}

		j = 0;

		for(i=1; i<=N; i++)
			j = std::max(j, size[findset(i)]);

		std::cout<< j << '\n';
	}

	return 0;
}
