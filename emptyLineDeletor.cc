#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int length = 0;
	int arlen = 100;
	string fPath;
	cout << "Type complete path for file: " << endl;
	cin >> fPath;
	fstream fs;
	fs.open(fPath,ios_base::in|ios_base::out);
	if(fs.fail())
	{
		cerr << "Unable to locate file" << endl;
		return 1;
	}
	char *z = new char[arlen];
	char *t;
	while(!fs.eof())
	{
		length++;
		z[length-1] = fs.get();
		if(length >= arlen-1)
		{
			t = new char[arlen*2];
			for(int i = 0; i < arlen; i++)
			{
				t[i] = z[i];
			}
			delete [] z;
			z = t;
			arlen *=2;
		}
	}
	//remove any consecutive \n
	int x = 0;
	int cont = 1;
	for(int i = 0; i < length-1; i++)
	{
		if((z[i] != '\n') && (z[i] != ' '))
		{
			cont = 0;
		}
		if(((z[i] == '\n') || (z[i] == ' ')) && cont==1)
		{
			for(int j = i; j < length-1; j++)
				{
					z[j] = z[j+1];
				}
				length--;
				i--;
		}
		if(z[i] == '\n'){
			cont = 1;
		}
		
		
	}

		










	
	length-=x;
	ofstream of;
	of.open(fPath);
	of.write(z,length-1);
	return 0;
}