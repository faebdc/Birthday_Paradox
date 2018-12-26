#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;
const int N = 8000050;	//max_n
const int M = 10000;	//test_times
const int P = 3;	//collision_time
int n;
int xu[N];
int arr[M+1];
unsigned int r(unsigned int x)
{
	unsigned int a=rand();
	a<<=10;
	a%=x;
	a+=rand();
	a<<=10;
	a%=x;
	a+=rand();
	a<<=10;
	a%=x;
	a+=rand();
	a%=x;
	return a;
}
int main()
{
	srand(time(0));
	int i;
	scanf("%d",&n);
	long long val=0;
	for(i=1;i<=M;i++)
	{
		memset(xu,0,sizeof xu);
		int now=0;
		while(1)
		{
			int t=r(n);
			xu[t]++;
			now++;
			if(xu[t]>=P)
				break;
		}
		val+=now;
		arr[i]=now;
		if(i%100==0)
			printf("%d %f\n",i,((double)val)/i);
	}
	sort(arr+1,arr+M+1);
	printf("%d\n",arr[(M+1)/2]);
	return 0;
}
