// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
int N, M;
long long trees[1000000], maximumheight = 0, minheight = 1000000000;
long long ParametricSearch(long long index)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (trees[i] > index)
		{
			sum += trees[i] - index;
		}
	}
	return sum;

}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
		maximumheight = max(trees[i], maximumheight);
		minheight = min(trees[i], minheight);
	}
	long long left = 0, right = maximumheight;
	while (left+1< right)
	{
		long long mid = (left + right) /2;
		long long sum = ParametricSearch(mid);

		if (sum >= M)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout << left;
}

