//
//  Graph.h
//  FinalProject
//
//  Created by Michael Pszonka on 12/21/15.
//  Copyright (c) 2015 Michael Pszonka. All rights reserved.
//

#ifndef FinalProject_Graph_h
#define FinalProject_Graph_h


struct node {
    
    int weight;
    int destination;
    int source;
    std::vector<node*> neighborNodes;
    
    node() {
        
        weight = NULL;
        destination = NULL;
    }
};
class Graph {
    
public:
    
    // Parses through the graph.dat file and aclls appendAdjacenyList to
    // add the node to the adjaceny list.
    
    void readGraph();
    
    // At the end of each line of graph.dat, the integers are placed in a deque and
    // passed to appendAdjacenyList which creates a new node and pushes it into the
    // adjaceny list vector
    
    void appendAdjacencyList(std::deque<int> &t);
    
    // Does not meet requirements the assignment.  Was unable to figure out
    // output the nodes as required.  PrintGraph(), iterates through
    // adjaceny list, outputting the primary node, along with the nodes that
    // it is directed towards with the respective weights.
    
    void printGraph();
    
    // Iterates through the adjaceny file and places a pair (an edge) into a map
    // as a key along with the associated weight as the key.
    
    void getEdges();
    
    // Calculuates the shortest path between each node that a particular node can reach
    // and outputs this information in a chart.  Also calculates the path to traverse
    // around the entire graph and make it back to it's original position if possible.
    
    void shortestPath();
    
    std::ifstream inFile;  //graph.dat
    std::ofstream outFile; //graph output file
    std::vector<node*> adjacencyList;  //adjaceny list
    std::vector<std::pair<int, int>> edges;  //edges
    std::map<std::pair<int,int>, int> edgesAndWeight;  // edges and associated weight
    
    
};



#endif
