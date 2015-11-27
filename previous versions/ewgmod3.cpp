/* 
english word generator program
w/ no triple letters
cleaned up

modification: only a vowel allowed after 2 consonants in a row

6/11/14

future modifications:
   eliminate bad 2-consonant combos? (hard because some are allowable with vowels on either side)
      maybe just bad starting combos?
   might be useful to pass 0,1, or 2 to chooseletter to specify if a consonant, vowel, or any letter is needed?
   add a method for checking vowel status to eliminate bulky if statements
   allow user to choose base language (English, Italian, Arabic, etc) & work within that set of frequencies instead
      for unused letters, just set frequency to 0 & they'll never show up
      no extra letters for now
   give the triple-letter- and triple-consonant-check sections their own methods?
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char getletter(int);
double getfrequency(char);
void makeword(int);
int chooseletter();
char getnearestvowel(int);
bool twoconsonants(char, char);

int main()
{
   const int NUMWORDS = 10;
	
	//get a time and store it as the seed
	unsigned seed = time(0);
	
	//use this as a seed for random numbers
	srand(seed);
	
	for (int x = 0; x < NUMWORDS; x++)
	{	      
   	//pick a number of letters to go in the word (at least 3)
   	int length = 3 + rand() % 9;
   	//int length = 20; //for test purposes
      
      // cout << "Length: " << length << endl; //for test purposes
      cout << "Word " << x+1 << ": "; //for test purposes
      makeword(length);
      
   	cout << endl;
	}

	return 0;
}

void makeword(int length)
{
   char letter;
   char letterMinus1;
   char letterMinus2;
   bool tripleLetter = true;
	
   int test;
   
   for (int i = 0; i < length; i++)
	{
      //maybe pass a value that tells it to choose from vowels, consonants, or all?
      test = chooseletter();
      
      //assign first 2 letters to letterMinus2 and letterMinus1, respectively
      if (i==0)
      {
         letter = getletter(test);
		   cout << letter;
         letterMinus2 = letter;
      }
      else if (i==1)
      {
         letter = getletter(test);
		   cout << letter;
         letterMinus1 = letter;
      }
      
      //for every other letter, compare it to the 2 before it
      //if they're all the same, redo that round until they're not
      //once they're not, the current letterMinus1 = the current letter, letterMinus2 = letterMinus1 from before
      else
      {         
         //if the previous 2 letters were not vowels, this letter is the vowel closest to the originally chosen letter
         if(twoconsonants(letterMinus1, letterMinus2))
         {
            letter = getnearestvowel(test);
         }
         else
            letter = getletter(test);   
         
         //compare it to the two letters before it
         //if they're all the same, redo that round until they're not
         //once they're not, the current letterMinus1 = the current letter, letterMinus2 = letterMinus1 from before   
         if (letter == letterMinus1 && letterMinus1 == letterMinus2)
         {
            i-=1;
         }
         
         else
         {
            cout << letter;
            letterMinus2 = letterMinus1;
            letterMinus1 = letter; 
         }     
      }//end else
      
	}//end for
}

int chooseletter()
{
   const int MAXFREQ = 12702;
   double freqtest;
   bool exceedsfrequency;
   
	//generate a number between 0 and MAXFREQ (e's frequency)
	freqtest = rand() % MAXFREQ;
	freqtest /= 100000;
	
	exceedsfrequency = false;
	
	int test = 0;
	
   //while the frequency of the randomly chosen letter is less than freqtest
   //keep increasing test until the frequency of that letter matches
   /*
      NOTE:
      because the letters are listed in order of frequency, NOT alphabetically,
      this prevents letters earlier in the alphabet (i.e. "E") from being chosen
      too often
   */
	while (!exceedsfrequency)
	{
		if (getfrequency(getletter(test)) >= freqtest)
			exceedsfrequency = true;
		else
			test++;
	}
   
   return test;
   
}

bool twoconsonants(char letterMinus1, char letterMinus2)
{
   bool fail;
   
   if ((letterMinus1 != 'a' && letterMinus1 != 'e' && letterMinus1 != 'i' && letterMinus1 != 'o' && letterMinus1 != 'u' && letterMinus1 != 'y')
            && (letterMinus2 != 'a' && letterMinus2 != 'e' && letterMinus2 != 'i' && letterMinus2 != 'o' && letterMinus2 != 'u' && letterMinus2 != 'y'))
      fail = true;
   
   else
      fail =false;
      
   return fail;
}

//finds the vowel closest (upward) to the letter associated with the chosen integer
char getnearestvowel(int number1)
{
   bool vowelstatus = false;
   char vowel;
   
   do
   {
      if(number1 != 9 && number1 != 14 && number1 != 22 && number1 != 23 && number1 != 24 && number1 != 26)
      {
         number1++;
      }   
      else
      {
         vowelstatus = true;
      }   
   }while(vowelstatus == false);
   
   vowel = getletter(number1);
   
   return vowel;
}

//returns the letter associated with the integer chosen
char getletter(int number1)
{
   //vowel list:
   // 9,14,22,23,24,26
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