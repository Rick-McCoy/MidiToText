#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	for(int x=1;x<=228;x++)
	{
		char name1[10] = {0}, name2[10] = {0}, c = 'a';
		int k, y = 0;
		string num;
		while(k!=0)
		{
			num.push_back(k%10+48);
			k = (k-k%10)/10;
		}
		while(num.size())
		{
			name1[y++] = num.back();
			name2[y-1] = num.back();
			num.pop_back();
		}
		name1[y] = name2[y] = '.';
		name1[y+1] = 'c';
		name1[y+2] = 's';
		name1[y+3] = 'v';
		name2[y+1] = name2[y+3] = 't';
		name2[y+2] = 'x';
		FILE *fp1 = fopen(name1, "r"), *fp2 = fopen("input_NewBachFormat1.txt", "a+");
		fprintf(fp2, "\n\n%d\n\n", x);
		c = fgetc(fp1);
		while(c!=EOF)
		{
			fprintf(fp2, "%c", c);
			c = fgetc(fp1);
		}
		fclose(fp1);
		fclose(fp2);
		cout<<x<<endl;
	}
}
