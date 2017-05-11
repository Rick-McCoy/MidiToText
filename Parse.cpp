#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	FILE *fp = fopen("Input.txt", "r");
	char c = fgetc(fp);
	for(int x=1;c!=EOF;x++)
	{
		char name[20] = "Input-   .txt";
		name[8] = x%10+'0';
		name[7] = (x/10)%10+'0';
		name[6] = (x/100)%10+'0';
		FILE *fp1 = fopen(name, "w");
		while(c!='\n'&&c!=EOF)
		{
			fprintf(fp1, "%c", c);
			cout<<c;
			c = fgetc(fp);
		}
		c = fgetc(fp);
		int temp;
		fscanf(fp, "%d", &temp);
		c = fgetc(fp);
		c = fgetc(fp);
		c = fgetc(fp);
	}
}
