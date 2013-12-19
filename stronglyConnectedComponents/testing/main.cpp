#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "scc.h"
#include <vector>
using namespace std;

int main(){

/*
	Graph g(5);
	g.addEdge(1,0);
	g.addEdge(0,2);
	g.addEdge(2,1);
	g.addEdge(0,3);
	g.addEdge(3,4);
*/

/*

	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(3,4);
	g.addEdge(4,0);
*/

	string line;
	//eventually change this to command line argument input
	ifstream inputFile("exampleOutput");
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

	cout<<"populating the graph\n";
//	cout<<"displaying vector\n";
	Graph g(linkVector.size());
	for(int i = 0; i < linkVector.size(); i++){
		for(int j = 1; j < linkVector[i].size(); j++){
			g.addEdge(linkVector[i][0], linkVector[i][j]);
//			cout<<linkVector[i][j]<<" ";
			}
		}
		
	




	cout<<"Following are the strongly connected components in given graph\n";
	g.printSCCs();	

	return 0;
	}





