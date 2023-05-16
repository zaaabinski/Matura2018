#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

string sortString(string a)
{
	sort(a.begin(), a.end());
	return a;
}

int main()
{
	ifstream przyk("przyklad.txt");
	ifstream sygnal("sygnaly.txt");
	ofstream wyniki("wyniki4.txt");
	//4.1
	string slowo[1000],zdanie;
	for (int i = 0; i < 1000; i++)
	{
		przyk >> slowo[i];
	}
	for (int i = 39; i < 1000; i += 40)
	{
		string help = "a";
		help[0] = slowo[i][9];
		zdanie.append(help);
	}
	wyniki << "4.1" << endl;
	wyniki << zdanie << endl;

	//4.2
	ifstream przyk2("przyklad.txt");
	ifstream sygnal2("sygnaly.txt");
	string linia[1000];
	int alf[26];

	int maxLiter=-1, maxI;
	for (int i = 0; i < 1000; i++)
	{
		for (int a = 0; a < 26; a++)
		{
			alf[a] = 0;
		}
		sygnal2 >> linia[i];
		int dl = linia[i].size();
		for (int j = 0; j < dl; j++)
		{
			alf[linia[i][j] - 65]++;
		}
		int liter=0;
		for (int a = 0; a < 26; a++)
		{
			if (alf[a] > 0)
			{
				liter++;
			}
			if (liter > maxLiter)
			{
				maxLiter = liter;
				maxI = i;
			}
		}
	}
	wyniki << "4.2";
	wyniki << linia[maxI];
	wyniki <<" "<< maxLiter << endl;

	//4.3
	string slowo43;
	ifstream przyk3("przyklad.txt");
	ifstream sygnal3("sygnaly.txt");
	wyniki << "4.3" << endl;
	for (int i = 0; i < 1000; i++)
	{
		sygnal3 >> slowo43;
		//cout << slowo43;
		int dl = slowo43.size();
		if (sortString(slowo43)[dl - 1] - sortString(slowo43)[0] < 10)
		{
			wyniki << sortString(slowo43) << endl;
		}
	}

	return 0;
}