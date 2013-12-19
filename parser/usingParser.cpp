#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;


int main(){

	xml_document<> doc;
	xml_node<> * root_node;
//	ifstream theFile("example.hgw.xml");

	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);
	root_node = doc.first_node("mediawiki");
	for(xml_node<> * pageNode = root_node->first_node("page"); pageNode; pageNode = pageNode->next_sibling()){
		printf("%s %s\n", pageNode->first_attribute("id")->value(),pageNode->first_node("links")->value());
		}


	return 0;
}

