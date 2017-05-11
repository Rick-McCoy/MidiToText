#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	for(int x=1;x<=1;x++)
	{
		char name1[20] = "Input-   .txt", name2[20] = "Output-   .csv";
		name1[6] = name2[7] = (x/100)%10+'0';
		name1[7] = name2[8] = (x/10)%10+'0';
		name1[8] = name2[9] = x%10+'0';
		FILE *fp1 = fopen(name1, "r"), *fp2 = fopen(name2, "w+");
		cout<<name1<<" "<<name2<<endl;
		vector<vector<char>> v;
		char c = 'a';
		bool on[200] = {0};
		int tim = 0;
		c = fgetc(fp1);
		while(c!=EOF)
		{
			vector<char> temp;
			while(c!=' '&&c!=EOF)
			{
				temp.push_back(c);
				c = fgetc(fp1);
			}
			c = fgetc(fp1);
			if(temp.size()>0)
				v.push_back(temp);
			else
			{
				temp.push_back(' ');
				v.push_back(temp);
			}
		}
		fprintf(fp2, "0, 0, Header, 1, 2, 1024\n");
		fprintf(fp2, "1, 0, Start_Track\n");
		fprintf(fp2, "1, 0, Time_signature, 6, 2, 24, 8\n");
		fprintf(fp2, "1, 0, Key_signature, -5, \"minor\"\n");
		fprintf(fp2, "1, 0, Tempo, 333333\n");
		fprintf(fp2, "1, 0, Time_signature, 4, 2, 24, 8\n");
		fprintf(fp2, "1, %d, End_track\n", 128*(v.size()-100));
		fprintf(fp2, "2, 0, Start_track\n");
		fprintf(fp2, "2, 0, Title_t, \"Acoustic Grand Piano\"\n");
		fprintf(fp2, "2, 0, Program_c, 0, 0\n");
		for(auto i:v)
		{
			bool tr[200] = {0};
			for(auto j:i)
				tr[j-12] = 1;
			for(int j=21;j<109;j++)
				if(on[j]&&!tr[j])
				{
					fprintf(fp2, "2, %d, Note_off_c, 0, %d, 0\n", 128*tim, j);
					on[j] = 0;
				}
			for(int j=21;j<109;j++)
				if(!on[j]&&tr[j])
				{
					fprintf(fp2, "2, %d, Note_on_c, 0, %d, 80\n", 128*tim, j);
					on[j] = 1;
				}
			tim++;
		}
		fprintf(fp2, "2, %d, End_track\n", tim*128);
		fprintf(fp2, "0, 0, End_of_file\n");
		fclose(fp1);
		fclose(fp2);
	}
}
