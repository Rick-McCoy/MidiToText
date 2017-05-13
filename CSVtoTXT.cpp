#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	for(int x=1;x<=1;x++)
	{
		char name1[10] = {0}, name2[10] = {0}, c = 'a';
		int k = x, y = 0, div = 0, tmpint1 = 0, tmpint2 = 0, basetime = 0, endtime = 0;
		string num, tmpstr;
		vector<vector<string>> v, f;
		vector<int> Note[200];
		vector<char> Time[80000];
		string on = "Note_on_c", off = "Note_off_c", head = "Header";
		bool Tr[88] = {0};
		num = to_string(x);
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
		FILE *fp1 = fopen(name1, "r"), *fp2 = fopen("input.txt", "a+");
		if(!fp1||!fp2)
		{
			printf("ERROR!\n");
			continue;
		}
		c = fgetc(fp1);
		while(c!=EOF)
		{
			vector<string> tmp;
			while(c!='\n'&&c!=EOF)
			{
				string temp;
				while(c!='\n'&&c!=','&&c!=EOF)
				{
					if(c == ' ') c = fgetc(fp1);
					if(c == '\n'||c == ',') break;
					temp.push_back(c);
					c = fgetc(fp1);
				}
				tmp.push_back(temp);
				if(c == '\n') break;
				c = fgetc(fp1);
			}
			v.push_back(tmp);
			c = fgetc(fp1);
		}
		for(int i=0;i<v.size();i++)
			if(v[i][2]!=head&&v[i][2]!=on&&v[i][2]!=off)
				v.erase(v.begin()+i--);
			else if(v[i][2] == head) v[i][2] = "h";
			else if(v[i][2] == on) v[i][2] = "n";
			else if(v[i][2] == off) v[i][2] = "f";
		for(int i=1;i<v.size();i++)
		{
			v[i].erase(v[i].begin());
			v[i].erase(v[i].begin()+2);
			v[i].erase(v[i].end());
		}
		div = stoi(v[0][5]);
		v.erase(v.begin());
		v.pop_back();
		for(auto i:v)
		{
			basetime = min(basetime, stoi(i[0]));
			endtime = max(endtime, stoi(i[0]));
		}
		endtime = 8*(endtime-basetime)/div;
		printf("%d: %d %d %d\n", x, div, basetime, endtime);
		for(auto i:v)
			Note[stoi(i.back())].push_back(8*(stoi(i.front())-basetime)/div);
		for(int i=0;i<200;i++)
			if(Note[i].size()>0)
				for(auto j:Note[i])
					Time[j].push_back(i+12);
		fprintf(fp2, "\n\n%d\n\n", x);
		for(int i=0;i<endtime+100;i++)
		{
			for(auto j:Time[i])
				Tr[j] = 1-Tr[j];
			for(int j=0;j<200;j++)
				if(Tr[j]) 
					fprintf(fp2, "%c", j);
			fprintf(fp2, " ");
		}
		for(int i=0;i<100;i++)
			fprintf(fp2, " ");
		fclose(fp1);
		fclose(fp2);
	}
}
