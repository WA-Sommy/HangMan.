#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

struct ranword{
	char word [40]; // read file one into
	char guessV [40];
	char cat[40];
	char used;
};

struct ranword3{

char b1f[40];
char b2f[40];
char b3f[40];
char cat[40];

};

struct ranword4{

char Allfile[40];
char hold[40];
char screenword[40];
char cat[40];
};



int getLength(char word2[])
{
	int i = 0, len = 0;
	
	while(word2[i] != '\0'){
		len++;
		i++;
	}
	return len;
}

bool isLetter(char ch) 
{
    if ( (ch >= 'A' && ch <= 'Z' ) || (ch >= 'a' && ch <= 'z') || ch== '.' || ch == '-' || ch == '!')
        return true;
    return false;
}

void strcopy1f(char a1f[], char b1f[], char cat[])
{
	ranword3 d3;
	ofstream outfile;
    char ch;
    int counter1=1;
    outfile.open("CompileAll.txt", ios_base::app);
	ranword3 d2;
	char fsend1 [25];
    int i=0;
    
	for(i=0;i<=getLength(a1f);i++)
		b1f[i]=a1f[i];
	
		outfile << b1f << "\t";
		outfile << cat << endl;
				
	outfile.close();             
}

char strcopy2f(char a2f[], char b2f[], char cat[])
{
	ofstream outfile;
	int counter2 = 2;
    char ch;
    outfile.open("CompileAll.txt", ios_base::app);
     
	ranword3 d2;
    int i=0;
    for(i=0;i<=getLength(a2f);i++)
  		b2f[i]=a2f[i];
  		
		outfile << b2f << "\t";	
		outfile << cat << endl;
	outfile.close();
}

char strcopy3f(char a3f[], char b3f[], char cat[])
{
	ofstream outfile;
    char ch;
    int counter3 = 3;
    outfile.open("CompileAll.txt", ios_base::app);
     
	ranword3 d2;
    int i=0;
    for(i=0;i<=getLength(a3f);i++)
  		b3f[i]=a3f[i];
		outfile << b3f << "\t";	
		outfile << cat << endl;
		
	outfile.close();
}

int strcomp(char a[], char b[])
{ //compares
    int sizea=getLength(a);
    int sizeb=getLength(b);
    if(sizea!=sizeb)
        return 1;
    else {
        for(int i=0;i<=sizea;i++){
            if(a[i]!=b[i])
                return 1;
        }
    }
    return 0;
}

void strcopy2(char a2[], char b2[]){
	
//	ranword2 d2;
    int i=0;
    for(i=0;i<=getLength(a2);i++)
        b2[i]=a2[i];
}

int getCharacters1(ranword d[])
{
	ifstream in;
    char ch;

    in.open("classic_tv.txt");

    if (!in.is_open()) {
        cout << "Error -- classic_tv.txt could not be opened." << endl;
        return -1;
    }

    int i=0;
    char word [30];

    char END[4];
    END[0]='E';
    END[1]='N';
    END[2]='D';
    END[3]='\0';
    char cat[40] = {'C', 'l', 'a', 's', 's', 'i', 'c', '-', 'T', 'V', '\0'};

    
    in >> word;
	while (strcomp (word, END) != 0){
	strcopy1f(word, d[i].word, cat);
		i = i + 1;
		in >> word;
    }
    
    return i;
}

//Reading the file Input
int getCharacters2(ranword d[])
{
	ifstream in;
    char ch;

    in.open("food_and_drink.txt");

    if (!in.is_open()) {
        cout << "Error -- Food could not be opened." << endl;
        return -1;
    }

    int i=0;
    char word [30];

    char END[4];
    END[0]='E';
    END[1]='N';
    END[2]='D';
    END[3]='\0';
    char cat[40] = {'F', 'o', 'o', 'd', '-', 'a', 'n', 'd', '-', 'D', 'r', 'i', 'n', 'k', '\0'};

    in >> word;

	while (strcomp (word, END) != 0){
	  	strcopy2f(word, d[i].word, cat);
		i = i + 1;
		in >> word;
	}
    
    return i;
}

//Reading the file Input
int getCharacters3(ranword d[])
{
	ifstream in;
    char ch;

    in.open("fictional_characters.txt");

    if (!in.is_open()) {
        cout << "Error -- Fictonal Character could not be opened." << endl;
        return -1;
    }

    int i=0;
    char word [30];

    char END[4];
    END[0]='E';
    END[1]='N';
    END[2]='D';
    END[3]='\0';
    char cat[40] = {'F', 'i', 'c', 't', 'i', 'o', 'n', 'a', 'l', '-', 'C', 'h', 'a', 'r', 'a', 'c', 't', 'e', 'r', 's', '\0'};
    in >> word;

	while (strcomp (word, END) != 0){
		strcopy3f(word, d[i].word, cat);
  
		i = i + 1;
		in >> word;
    }

    return i;
}


int getWord (char data[], int start, char word[]) 
{

    int i, j, size;

    size = getLength (data);

    i = start;
    while (i < size && (!isLetter(data[i])))
		i = i + 1;

    if (i == size)
		return -1;

    j = 0;
    while (isLetter(data[i])) {
		word[j]= data[i];
		i = i + 1;
		j = j + 1;
    }

    word[j]= '\0';

    return i;
}



int readFromOutputFile ( ranword d[] )
{
	int size = 300;
	ranword4 in[size];
	ifstream inoutfile;
    char inputnum;
    char inputword [30];
    int ii=0;
    int counter2 =0;
    int counter3 =0;
        
        
   int i=0;

	int call =9;
	char hold[40];
	int counter =0;
	char input; // reads in from the file
	char Allfile1[10000];
	int szf = 0; // size of Allfile

    inoutfile.open("CompileAll.txt");
    if (!inoutfile.is_open()) {
        cout << "Error CompileAll.txt could not be opened." << endl;
        return -1;
    }
    
    
    inoutfile >> noskipws ;  // says include the white spaces
    inoutfile >> input;
    while(!inoutfile.eof())
      {
      	    Allfile1[i]= input;
      	    
      	    i++;
      	    inoutfile >> input;
        }
        Allfile1[i]= '\0';
        

        szf = getLength(Allfile1);
        
        while(ii < szf)
        {
        	
        	ii = getWord(Allfile1, ii, d[counter3].word);
			ii = getWord(Allfile1, ii, d[counter3].cat);
			   	   	
        	ii++;
        	counter3 ++;
        	counter2 ++;
		}

	inoutfile.close();
	
	return counter3;
}


void convertToStars (ranword d[], int wordamt)
{
	int lengthofword;
	for(int i = 0; i < wordamt; i++){//get the words
		lengthofword = getLength(d[i].word);
		for(int j = 0; j < getLength(d[i].word); j++){ //convert the letters to stars
			if(d[i].word[j] == 'r' || d[i].word[j] == 's' || d[i].word[j] == 't' || d[i].word[j] == 'l' || d[i].word[j] == 'n'
			|| d[i].word[j] == 'R' || d[i].word[j] == 'S' || d[i].word[j] == 'T' || d[i].word[j] == 'L' || d[i].word[j] == 'N'
			|| d[i].word[j] == '-' || d[i].word[j] == '/' || d[i].word[j] == '!'){
				d[i].guessV[j] = d[i].word[j];
			}
			else{
				d[i].guessV[j] = '*';
			}
				
			
		}
		d[i].used = false;
	}
}

void getWords(ranword d[], int wordamt, ranword d1[], int amt)
{
	//d is all words
	//d1 is the words to guess
	int random;
	int length;
	
	for(int i = 0; i < amt; i++){
		random = 1 + (rand() % wordamt);
		
		if(d[random].used == false){
			
			length = getLength(d[random].word);
			strcopy2(d[random].word, d1[i].word);
			strcopy2(d[random].guessV, d1[i].guessV);
			strcopy2(d[random].cat, d1[i].cat);

			d[random].used = true;
			d1[i].used = true;
		} else {
			while(d[random].used == true){
				random = 1 + (rand() % wordamt);
				if(d[random].used == false){
					
					length = getLength(d[random].word);
					strcopy2(d[random].word, d1[i].word);
					strcopy2(d[random].guessV, d1[i].guessV);
					strcopy2(d[random].cat, d1[i].cat);

					d[random].used = true;
					d1[i].used = true;
					break;
				}
			}
		}
	}
}

bool checkstar(char position)
{
	if(position == '*'){
		return true;
	}
	return false;
}

char toUpper(char letter)
{
	return letter + 32;
}
char toLower(char letter)
{
	return letter - 32;
}
bool isAlpha(char letter)
{
	if((letter >= 'A') && (letter <= 'Z') || (letter >= 'a') && (letter <= 'z')){
		return true;
	}
	return false;
}

int letterCheck(char originalword[], char guessword[], char guess)
{
	int i = 0;
	int j = 0;
	while(i < getLength(originalword)){
		if(originalword[i] == guess){
			if(checkstar(guessword[i]) == true){
				guessword[i] = guess;
				j++;
			}
			else
				guessword[i] = guessword[i];
		} else if ((isAlpha(originalword[i]) == true) && originalword[i] == toUpper(guess)){
			if(checkstar(guessword[i]) == true){
				guessword[i] = toUpper(guess);
				j++;
			}
			else
				guessword[i] = guessword[i];
		} else if ((isAlpha(originalword[i]) == true) && originalword[i] == toLower(guess)){
			if(checkstar(guessword[i]) == true){
				guessword[i] = toLower(guess);
				j++;
			}
			else
				guessword[i] = guessword[i];
		}
		i++;
	}
	return j;
}

drawborder(char a[10][50])
{

    for (int row = 0; row < 10; row++)  //creates the outer box
        for (int col = 0; col < 50; col++)
        {
            if (row == 0 || row == 9 || col == 0 || col == 38)
                a[row][col] = '%';
        }

    for (int row = 0; row < 10; row++)  //creates the outer right line
        for (int col = 0; col < 50; col++)
        {
            if (row == 0 || row == 9 || col == 0 || col == 49)
                a[row][col] = '%';
        }

    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 50; col++)
            cout << a[row][col] ;
        cout << endl;
    }

}

void headneck(char a[10][50])
{
        a[1][42] = '_';
		a[1][43] = '_';
        a[1][44] = '_';
        a[1][45] = '_';
        
        a[2][41] = '|';
        a[2][43] = '0';
        a[2][44] = '0';
        a[2][46] = '|';
        
        a[3][41] = '|';
        a[3][42] = '\\';
        a[3][43] = '_';
        a[3][44] = '_';
        a[3][45] = '/';
        a[3][46] = '|';
        
}

void leftarm(char a[10][50])
{

    a[4][42] = '/';
	a[5][41] = '/';

}

void rightarm(char a[10][50])
{

    a[4][45] = '\\';
	a[5][46] = '\\';

}

void body(char a[10][50])
{

    a[4][43] = ')';
    a[4][44] = '(';
    
	a[5][43] = '|';
	a[5][44] = '|';
	
    a[6][43] = '|';
    a[6][44] = '|';

}

void leftleg(char a[10][50])
{

    a[7][42] = '/';
	a[8][41] = '/';

}

void rightleg(char a[10][50])
{

     a[7][45] = '\\';
	 a[8][46] = '\\';

}

int randomNumber (int min, int max) {
	return min + rand() % max;
}

bool intexists(int arr[], int num, int size){
	for(int i = 0; i < size; i++){
		if(arr[i] == num){
			return true;
		}
	}
	return false;
}

int gethangmanorder(int partsorder[]){
	int random = 0;
	int i = 0;
	bool exists = false;
	
	while(i < 6){
		random = randomNumber(1, 6);
		exists = intexists(partsorder, random, 6);
		if(exists == false){
			partsorder[i] = random;
		} 
		else {
			exists = intexists(partsorder, random, 6);
			while(exists == true){
				random = randomNumber(1, 6);
				exists = intexists(partsorder, random, 6);
				if(!exists){
					partsorder[i] = random;
					break;
				} 
			}		
		}
		i++;
	}
	return i;
	
}

void centerword(char n[], char a[][50], int amt, int start)
{
	int col;
    
    int sizebox=0;
	int k=0;
	
	sizebox = (40 - getLength(n)) / 2;
	while(n[k] != '\0')	{
  		col = sizebox;

    	a[start][sizebox] = n[k];
    	sizebox++;
    	k++;
	}
}

void randomdraw(char a[10][50], int arr[], int drawn)
{

	if(arr[drawn] == 1)
	{
		rightleg(a);
	}
	else if (arr[drawn] == 2){
		leftleg(a);
	}
	else if (arr[drawn] == 3){
		body(a);
	}
	else if (arr[drawn] == 4){
		rightarm(a);
	}
	else if (arr[drawn] == 5){
		headneck(a);
	}
	else if (arr[drawn] == 6){
		leftarm(a);
	}	
	
}

int solvedword(char word[]){
	int missingletters = 0;
	int lenword = getLength(word);
	
	for(int j = 0; j < lenword; j++){
		if(word[j] == '*'){
			missingletters++;
		}
	}
	return missingletters;
}

int main() {

	ranword d[1000];
	ranword4 d4[100];
	char data[99];
	char key;
	char str2[20];
	char str3[20];
	char i1;
	char i2;
	char i3;
	
	int amt;	//number of words to guess
	int wordamt; //number of words
	int drawn =0;
	char continueplaying = 'Y';
	int numfound = 0;
	char a[10][50];
	int counter = 0;
	int partsorder[6];
	int numberofwords = 0;
	int row;
	char guess;
	int guessed = 0;
	
 	srand(time (NULL));
 	
 	
	ofstream outfile;
	
	outfile.open("CompileAll.txt", std::ofstream::out | std::ofstream::trunc);
	outfile.close();
	
	int i;
	
	i1 = getCharacters1(d);
	i2 = getCharacters3(d);
	i3 = getCharacters2(d);
		
	wordamt = readFromOutputFile (d);
	convertToStars(d, wordamt);
	
	while(continueplaying == 'Y' || continueplaying == 'y'){
		
		for (int row = 0; row < 10; row++){
	        for (int col = 0; col < 50; col++){
	            a[row][col] = ' ';
	        }
	    }
	    for(int i = 0; i < 6; i++){
			partsorder[i] = 0;
		}
		counter = gethangmanorder(partsorder);
		
		amt = randomNumber(1, 5);
		ranword d1[amt];
		getWords(d, wordamt, d1, amt);
		
		
		cout<<"You solved "<<numfound<<" of "<<amt<<" words"<<endl;
		if(amt == 1 || amt == 2){
			row = 4;
		} else if(amt == 3 || amt == 4){
			row = 3;
		} else {
			row = 2;
		}
		
		for(int i = 0; i < amt; i++){
			centerword(d1[i].guessV, a, amt, row);
			row++;
		}
		
		drawborder(a);
		for(int i = 0; i < amt; i++){
			cout<<"The clue for word "<<i+1<<" is: "<<d1[i].cat<<endl;
		}
		
		drawn = 0;
		
		int totalguessed = 0;
		int missingletters = 0;
		while(drawn < 6 && totalguessed < amt){
			totalguessed = 0;
			guessed = 0;
			
			cout<<endl;
			cout<<"Guess a letter: ";
			cin>>guess;
			
			for(int i = 0; i < amt; i++){
				guessed += letterCheck(d1[i].word, d1[i].guessV, guess);
				
			}
			if(amt == 1 || amt == 2){
				row = 4;
			} else if(amt == 3 || amt == 4){
				row = 3;
			} else {
				row = 2;
			}
			for(int i = 0; i < amt; i++){
				centerword(d1[i].guessV, a, amt, row);
				row++;
			}
			if(guessed == 0){
				cout<<"No "<<guess<<"'s found...try again"<<endl;
				randomdraw(a, partsorder, drawn);
				drawn++;
				if(drawn == 6){
					cout<<"GAME OVER!"<<endl;
				}
			} else {
				cout<<"Great "<<guessed<<" "<<guess<<"'s found! keep going!"<<endl;
			}
			
			
			for(int i = 0; i < amt; i++){
				if(solvedword(d1[i].guessV) == 0){
					totalguessed++;
				} else {
					totalguessed = totalguessed;
				}
			}
			cout<<"You solved "<<totalguessed<<" of "<<amt<<" words"<<endl;
			drawborder(a);
			for(int i = 0; i < amt; i++){
				cout<<"The clue for word "<<i+1<<" is: "<<d1[i].cat<<endl;
			}
			cout<<endl;
			
			if(drawn == 6){
				cout<<"The correct words are: "<<endl;
				for(int i = 0; i < amt; i++){
					cout<<d1[i].word<<endl;
				}
				cout<<endl;
			}
		}
		
		cout<<endl<<"Continue playing enter Y for Yes or N for No: ";
		cin>>continueplaying;
	}
	
	
return 0;
}
