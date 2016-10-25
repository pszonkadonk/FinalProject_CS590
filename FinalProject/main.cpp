//
//  main.cpp
//  FinalProject
//
//  Created by Michael Pszonka on 12/18/15.
//  Copyright (c) 2015 Michael Pszonka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <deque>
#include <iomanip>
#include "Graph.h"

using namespace std;


void Graph::readGraph() {
    
    inFile.open("graph.dat");
    string line;
    
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            deque<int> temp;
            stringstream graphStream(line);
            
            int val;
            while(graphStream >> val ) {
                
                temp.push_back(val);
            }
            
            appendAdjacencyList(temp);
        }
    }
    inFile.close();
}


void Graph::appendAdjacencyList(deque<int> &t) {
    
    auto q = t;
    node *headNode = new node();
    headNode->source = q.at(0);
    q.pop_front();
    while(!q.empty()) {
        node *newNode = new node();
        newNode->destination = q.at(0);
        q.pop_front();
        newNode->weight=q.at(0);
        q.pop_front();
        headNode->neighborNodes.push_back(newNode);
        
    }
    adjacencyList.push_back(headNode);
}


void Graph::getEdges() {
    
    pair<int, int> p;
    for(int i = 0; i < adjacencyList.size(); i++) {
        for(int j = 0; j < adjacencyList.at(i)->neighborNodes.size(); j++){

                p.first = adjacencyList.at(i)->source;
                p.second = adjacencyList.at(i)->neighborNodes.at(j)->destination;
                edges.push_back(p);
                edgesAndWeight.insert(pair<pair<int,int>, int>(p, adjacencyList.at(i)->neighborNodes.at(j)->weight));
        }
    }
//    for(auto itr = edgesAndWeight.begin(); itr!=edgesAndWeight.end(); ++itr) {
//        
//        cout << "(" << itr->first.first << "," << itr->first.second << ")" << " WEIGHT: " << itr->second << endl;
//    }
}

void Graph::printGraph() {
    

    outFile.open("graph-printout.dat");
    
    for(auto itr = adjacencyList.begin(); itr!=adjacencyList.end(); ++itr) {
        
        outFile << "[" <<  (*itr)->source << "]";
        for(auto neighborItr = (*itr)->neighborNodes.begin(); neighborItr != (*itr)->neighborNodes.end(); ++neighborItr) {
            
            outFile << "-----" << (*neighborItr)->weight << "--->" << "[" << (*neighborItr)->destination << "]";
        }
        outFile << "\n";
        
    }
    
    outFile.close();
}

void Graph::shortestPath() {
    
    cout << setfill(' ') << setw(33) << "Shortest Paths" << endl;
    cout << setfill(' ') << setw(35) << "--------------------" << endl;
    cout << setfill(' ') << setw(20) <<"| Source |" << " Destination |" << " Path Value" << endl;
    
    for(auto itr = edgesAndWeight.begin(); itr!= edgesAndWeight.end(); ++itr) {
        
        int src = itr->first.first;
        int dest = itr->first.second;
        int weight = itr->second;
        
        cout << setfill(' ') << setw(11) << "|" << src << setfill(' ') << setw(8) << " |" << dest << setfill(' ') << setw(13) << " |" << weight <<
         setfill(' ') << setw(15) << "    direct from " << src << " to " << dest << endl;
    
    
    for(auto itr2 = ++edgesAndWeight.begin(); itr2!= edgesAndWeight.end(); ++itr2) {
        
        if(dest==itr2->first.first) {
            
            weight += itr2->second;
            cout << setfill(' ') << setw(11) << "|" << src << setfill(' ') << setw(8) << " |" << itr2->first.second << setfill(' ') << setw(13) << " |" <<
             weight << setfill(' ') << setw(15) <<  "    traversing through " << itr2->first.first << endl;


            weight = itr->second;
        }
    }
}
    

}
    



int main() {
    
    
    
    
    Graph g;

    g.readGraph();
    g.getEdges();
    
    g.shortestPath();
    g.printGraph();
 
    
    
    
    
//adjaceny test printout
    
//    for(int i = 0; i < g.adjacencyList.size(); i++) {
//        for(int j = 0; j < g.adjacencyList.at(i)->neighborNodes.size(); j++)
//            cout << "NODE SOURCE: " << g.adjacencyList.at(i)->source << " DESTINATION: " <<
//            g.adjacencyList.at(i)->neighborNodes.at(j)->destination << " WITH WEIGHT: " <<  g.adjacencyList.at(i)->neighborNodes.at(j)->weight << endl;
//    }
    
    return 0;
}
