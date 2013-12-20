#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){

	string line, tempLine;
	ifstream myFile(argv[1]);
	ofstream fileToWrite(argv[2]);
	size_t pos = 0;
	if(myFile.is_open() && fileToWrite.is_open()){
		while(getline(myFile,line)){
			tempLine = line;
			if((pos = line.find(' ')) != (line.length()- 1)){
				fileToWrite << line <<"\n";	
				}			
			}
		myFile.close();
		fileToWrite.close();
		}	

	//now to count

	ifstream inputFile(argv[2]);
	ofstream countFile(argv[3]);
	int counter = 0;

	if(inputFile.is_open() && countFile.is_open()){
			while(getline(inputFile, line)){
				pos = line.find(' ');
				line.erase(0,pos+1);
				counter++;
				while((pos = line.find(' ')) != std::string::npos){
					counter++;
					line.erase(0,pos+1);
					}
				countFile << counter <<"\n";
//				counts.push_back(counter);
				counter = 0;
			}	
			inputFile.close();
		}

	


	return 0;
	}
