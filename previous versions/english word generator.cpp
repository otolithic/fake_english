/* 
try putting letter frequencies for diff. languages in diff. files
read from the file to assign letter frequencies, this will cut down
number of lines of code

also try to find a way to prevent having 3 of the same letter in a row
maybe with an array?

then maybe have something for common letter combinations
like if the last letter was "s" there's a 5% greater chance the following letter will be h,
or something like that
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char getletter(int);
double getfrequency(char);

int main()
{
	const int MAXFREQ = 12702;
	double number;
	char letter;
	bool exceedsfrequency;
	double checkfreq;
	double freqtest;
	
	
	//get a time and store it as the seed
	unsigned seed = time(0);
	
	//use this as a seed for random numbers
	srand(seed);
	
	for (int x = 0; x < 50; x++)
	{	
	//pick a number of letters to go in the word
	int length = 3 + rand() % 9;
	//int length = 500; //for test purposes
	
	for (int x = 0; x < length; x++)
	{
		//generate a number between 0 and MAXFREQ (e's frequency)
		freqtest = rand() % MAXFREQ;
		freqtest /= 100000;
		
		exceedsfrequency = false;
		
		int test = 0;
		
		while (!exceedsfrequency)
		{
			if (getfrequency(getletter(test)) >= freqtest)
				exceedsfrequency = true;
			else
				test++;
		}
		
		letter = getletter(test);
		
		cout << letter;
	}
	cout << " ";
	}

	return 0;
}

//returns the letter associated with the random integer chosen
char getletter(int number1)
{
	switch (number1)
		{
			case 1: 
				return 'z';
				break;
			case 2:
				return 'q';
				break;
			case 3:
				return 'x';
				break;
			case 4:
				return 'j';
				break;
			case 5:
				return 'k';
				break;
			case 6:
				return 'v';
				break;
			case 7:
				return 'b';
				break;
			case 8:
				return 'p';
				break;
			case 9:
				return 'y';
				break;
			case 10:
				return 'g';
				break;
			case 11:
				return 'f';
				break;
			case 12:
				return 'w';
				break;
			case 13:
				return 'm';
				break;
			case 14:
				return 'u';
				break;
			case 15:
				return 'c';
				break;
			case 16:
				return 'l';
				break;
			case 17:
				return 'd';
				break;
			case 18:
				return 'r';
				break;
			case 19:
				return 'h';
				break;
			case 20:
				return 's';
				break;
			case 21:
				return 'n';
				break;
			case 22:
				return 'i';
				break;
			case 23:
				return 'o';
				break;
			case 24:
				return 'a';
				break;
			case 25:
				return 't';
				break;
			case 26:
				return 'e';
				break;
			default:
				return '0';
				break;
		}
}

//returns the frequency of the letter chosen, to be used in
//determining whether the letter can be placed
double getfrequency(char letter)
{
	double z = .00074;
	double q = .00095;
	double x = .00150;
	double j = .00153;
	double k = .00772;
	double v = .00978;
	double b = .01492;
	double p = .01929;
	double y = .01974;
	double g = .02015;
	double f = .02228;
	double w = .02360;
	double m = .02406;
	double u = .02758;
	double c = .02782;
	double l = .04025;
	double d = .04253;
	double r = .05987;
	double h = .06094;
	double s = .06327;
	double n = .06749;
	double i = .06966;
	double o = .07507;
	double a = .08167;
	double t = .09056;
	double e = .12702;
	
	switch (letter)
		{
			case 'a':
				return  a;
				break;
			case 'b':
				return  b;
				break;
			case 'c':
				return  c;
				break;
			case 'd':
				return  d;
				break;
			case 'e':
				return  e;
				break;
			case 'f':
				return  f;
				break;
			case 'g':
				return  g;
				break;
			case 'h':
				return  h;
				break;
			case 'i':
				return  i;
				break;
			case 'j':
				return  j;
				break;
			case 'k':
				return  k;
				break;
			case 'l':
				return  l;
				break;
			case 'm':
				return  m;
				break;
			case 'n':
				return  n;
				break;
			case 'o':
				return  o;
				break;
			case 'p':
				return  p;
				break;
			case 'q':
				return  q;
				break;
			case 'r':
				return  r;
				break;
			case 's':
				return  s;
				break;
			case 't':
				return  t;
				break;
			case 'u':
				return  u;
				break;
			case 'v':
				return  v;
				break;
			case 'w':
				return  w;
				break;
			case 'x':
				return  x;
				break;
			case 'y':
				return  y;
				break;
			case 'z':
				return  z;
				break;
			default:
				return 0;
				break;			
		}
	
}