#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){

	string line, tempLine;
	ifstream myFile("outputToBeProcessed");
	ofstream fileToWrite("processed");
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

	ifstream inputFile("processed");

	vector<int> counts;
	int counter = 0;

	if(inputFile.is_open()){
			while(getline(inputFile, line)){
				pos = line.find(' ');
				line.erase(0,pos+1);
				counter++;
				while((pos = line.find(' ')) != std::string::npos){
					counter++;
					line.erase(0,pos+1);
					}
				counts.push_back(counter);
				counter = 0;
			}	
			inputFile.close();
		}

	for(int i = 0; i < counts.size(); i++){
		cout<<counts[i]<<endl;
		}



	return 0;
	}
