#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "scc.h"
#include <vector>
using namespace std;

int main(){

	string line;
	//eventually change this to command line argument input
	ifstream inputFile("outputFile");
		vector<vector<int> > linkVector;
		vector<int> tempVec;
		size_t pos = 0;	
		if(inputFile.is_open()){
			while(getline(inputFile, line)){
				tempVec.clear();
				pos = line.find(' ');
//				cout<<"id: "<<line.substr(0,pos)<<" ";
				tempVec.push_back(atoi(line.substr(0,pos).c_str()));
				line.erase(0,pos+1);
				while((pos = line.find(' ')) != std::string::npos){
				//	cout<<line.substr(0,pos)<<" ";
					tempVec.push_back(atoi(line.substr(0,pos).c_str()));
					line.erase(0,pos+1);
					}
				tempVec.push_back(atoi(line.c_str()));
//				cout<<line<<endl;		
				linkVector.push_back(tempVec);
			}	
			inputFile.close();
		}

	//	cout<<"displaying vector\n";
	cout<<"linkVector.size() = "<<linkVector.size()<<endl;
	Graph g(linkVector.size());
	cout<<"populating the graph\n";

	for(long int i = 0; i < linkVector.size(); i++){
		for(long int j = 0; j < linkVector[i].size(); j++){
			g.addEdge(linkVector[i][0], linkVector[i][j]);
			cout<<linkVector[i][j]<<" ";
			}
		cout<<endl;
		}
		
	

	cout<<"graph is populated\n";


//	cout<<"Following are the strongly connected components in given graph\n";
//	g.printSCCs();	

	return 0;
	}





