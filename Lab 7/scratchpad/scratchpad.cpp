#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <Array.h>
#include <LinkedList.h>
#include <TimeSupport.h>
#include <RandomSupport.h>
#include <BST.h>

using namespace std;

string reverse(string word){
    reverse(word.begin(), word.end());
    return word;
}
string reverse1(string word1){
    reverse(word1.begin(), word1.end());
    return word1;
}


long f(string word){
	long r=0;

	if (word.length()>=5){

		char a = word[0];
		char b = word[1];
		char c = word[2];
		char d = word[3];
		char e = word[4];
		r = a + ((b*10)+(c*250)+(d*1000) + (word.back()*100))%140000;
	}




	else if (word.length()>=4){

		char a = word[0];
		char b = word[1];
		char c = word[2];
		char d = word[3];
		r = a + ((b*10)+(c*250)+(d*1000) + (word.back()*100));
	}
	else if (word.length()>=3){

		char a = word[0];
		char b = word[1];
		char c = word[2];
		r = a + (b*250)+(c*1000)+(word.back()*100);
	}
	else if (word.length()>=2){

		char a = word[0];
		char b = word[1];
		r = (a + (b*500)+(word.back()*100));
	}
	else if (word.length()==1){

		char a = word[0];
		char b = word[1];
		r = ((a*2)%128+(word.back()*100));
	}





return r%500000;


}









 const long N = 200000;
LinkedList table[N];

void insert(string word){
	long index = f(word);
	table[index].append(word);
}

void insert1(string word1){
	long index1 = f(word1);
	table[index1].append(word1);
}

bool search1 (string word1){
	long index1 = f(word1);

return 	table[index1].search(word1);
}


bool search (string word){
	long index = f(word);

return 	table[index].search(word);
}


int main ()
{

    fstream file;
    ResizableArray words3;

    file.open("words3.txt",ios::in);
    if (file.is_open()){
        string tp;
        while(getline(file, tp)){
            (words3).append(tp);  
        }
        file.close(); 
    }

    else{
        cout << "Could not read file..." << endl;
    }

	for (int i = 0; i<words3.count; i++){
		insert(words3[i]);
	}
timestamp searchStart3 = current_time();

for (int i = 0; i<words3.count; i++){
	
	//cout << i<< ": " <<table[i]<<endl;

}
long counter3 = 0; 

for (int i = 0; i<words3.count; i++){
//cout << "Searching for " << words3[i]<< " in reverse: "<< search(reverse(words3[i]))<< endl;

	if (search(reverse(words3[i])) == 1){
		counter3++;
	
	}
}
timestamp searchEnd3 = current_time();
long searchDuration3= time_diff(searchStart3, searchEnd3);

cout <<"words3.txt: " << counter3 <<" matches" <<" in "<< searchDuration3 <<"ms" <<endl;










    fstream file2;
    ResizableArray words2;

    file2.open("words2.txt",ios::in);
    if (file2.is_open()){
        string tp2;
        while(getline(file2, tp2)){
            (words2).append(tp2);  
        }
        file2.close(); 
    }

    else{
        cout << "Could not read file..." << endl;
    }
timestamp searchStart2 = current_time();

	for (int i = 0; i<words2.count; i++){
		insert(words2[i]);
	}




long counter2 = 0; 
for (int i = 0; i<words2.count; i++){
//cout << "Searching for " << words2[i]<< " in reverse: "<< search(reverse(words2[i]))<< endl;

	if (search(reverse(words2[i])) == 1){
		counter2++;
	
	}
}


timestamp searchEnd2 = current_time();

long searchDuration2 = time_diff(searchStart2, searchEnd2);

cout <<"words2.txt: " << counter2 <<" matches" <<" in "<< searchDuration2 <<"ms" <<endl;




































    fstream file1;
    ResizableArray words1;
    file1.open("words.txt",ios::in);
    if (file1.is_open()){
        string tp1;
        while(getline(file1, tp1)){
            (words1).append(tp1);  
        }
        file1.close(); 
    }
    else{
        cout << "Could not read file..." << endl;
    }
	timestamp searchStart1 = current_time();

	for (int i = 0; i<words1.count; i++){
		insert1(words1[i]);
	}
//-87 because words2.txt and words.txt have 87 similar words in the same text file
long counter1 = -87; 
for (int i = 0; i<words1.count; i++){
//cout << "Searching for " << words2[i]<< " in reverse: "<< search(reverse(words2[i]))<< endl;

	if (search1(reverse1(words1[i])) == 1){
		counter1++;	
	
	}
}


timestamp searchEnd1 = current_time();

long searchDuration1 = time_diff(searchStart1, searchEnd1);

cout <<"words1.txt: " << counter1 <<" matches" <<" in "<< searchDuration1 <<"ms" <<endl;










    return 0;
}