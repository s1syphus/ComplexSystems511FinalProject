#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "scc.h"
#include <vector>
using namespace std;

int main(int argc, char* argv[]){

	string line;
	//eventually change this to command line argument input
	ifstream inputFile(argv[1]);
	vector<vector<int> > linkVector;
	vector<int> tempVec;
	size_t pos = 0;	
	if(inputFile.is_open()){
		while(getline(inputFile, line)){
			tempVec.clear();
			pos = line.find(' ');
			tempVec.push_back(atoi(line.substr(0,pos).c_str()));
			line.erase(0,pos+1);
			while((pos = line.find(' ')) != std::string::npos){
				tempVec.push_back(atoi(line.substr(0,pos).c_str()));
				line.erase(0,pos+1);
				}
			tempVec.push_back(atoi(line.c_str()));
			linkVector.push_back(tempVec);
		}	
		inputFile.close();
	}

	Graph g(linkVector[linkVector.size()-1][0] + 1);

//	cout<<"populating the graph\n";
	for(long int i = 0; i < linkVector.size(); i++){
		for(long int j = 0; j < linkVector[i].size(); j++){
			g.addEdge(linkVector[i][0], linkVector[i][j]);
//			cout<<linkVector[i][j]<<" ";
			}
//		cout<<endl;
		}


//	cout<<"graph is populated\n";


//	cout<<"Following are the strongly connected components in given graph\n";
	g.printSCCs();	

	return 0;
	}





