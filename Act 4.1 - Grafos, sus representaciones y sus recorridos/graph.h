/*
*  autor: Benjamin Valdes Aguirre
*  fecha: Diciembre 2020
*  programa: act 4.1 Implementacion Grafos
*  desc: estos programas son solciones parciales a algunos de
*  las actividades planteadas en el curso TC1031
*
*
*  Extiende este archivo para completar tu solución.
*/

#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


class Graph {
private:
		int edgesList;
		int edgesMat;
		int nodes;
    	vector<int> *adjList;
		int *adjMatrix;
		//vector<Type> *vect = new vector<Type>

public:
		void loadGraphMat(string, int, int);

		void loadGraphList(string, int, int); // Para listas.

		Graph(int);
		Graph();
		void addEdgeAdjMatrix(int, int);

		void addEdgeAdjList(int, int); // Para listas.

		string printAdjMat();

		string printAdjList(); // Para listas.

		//string printAdjMat_clean();
		bool contains(list<int>, int);
		void sortAdjList();

		void DFS(int, int);
		void dHelp(int, int, stack<int>&, list<int>&, vector<vector<int>>&);
		void BFS(int, int);
		void bHelp(int, int, queue<int>&, list<int>&, vector<vector<int>>&);

		void print_visited(list<int>);
		void print_path(vector<vector<int>>&,int ,int);

};


void Graph::loadGraphMat(string name, int a, int b){

	adjMatrix = new int [a*b];
	nodes = a;
	for (int i = 0; i < a*b; i++)
		adjMatrix[i] = 0;
		string line;
		ifstream lee (name);
		int u, v;
		if (lee.is_open()){
			while (getline(lee, line)){
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjMatrix(u,v);
			}
			lee.close(); // Closes the file
		} else {
			cout << "Unable to open file";
		}
}


Graph::Graph() {
	edgesList = edgesMat = 0;
}

Graph::Graph(int n) {

	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;

}

void Graph::addEdgeAdjMatrix(int u, int v){

	adjMatrix[u*nodes+v] = 1;
	adjMatrix[v*nodes+u] = 1;
	edgesMat++;

}

string Graph::printAdjList(){

	  stringstream aux;

	  sortAdjList();
		for (int i = 0; i < nodes; i++){
	        aux << "vertex "
	             << i << " :";
	        for (int j = 0; j < adjList[i].size(); j ++){
							 aux << " " << adjList[i][j];
					}
	        aux << " ";
    }
		return aux.str();

}

string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodes; i++){
	   for (int j = 0; j < nodes; j++){
			 aux << adjMatrix[i*nodes+j] << " ";
		 }
  }
	return aux.str();
}

/*string Graph::printAdjMat_clean(){
	stringstream aux;
	aux << "\n nodes \t|";
	for (int i = 0; i < nodes; i++){
			aux << "\t" << i ;
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
			aux << "__________";
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
		 aux << i << "\t|";
	   for (int j = 0; j < nodes; j++){
			 aux << "\t" << adjMatrix[i*nodes+j];
		 }
	   aux << "\n";
  }
	return aux.str();
}*/

/************************************************* Para Listas *************************************************/

void Graph::loadGraphList(string name, int a, int b){

	adjList = new vector<int>[a];
	nodes = a;
	string line;
	ifstream lee (name);
	int u, v;
	//for (int i = 0; i < adjList.size(); i++)

		//adjList[i].push_back(0);
		
		if (lee.is_open()){

			while (getline(lee, line)){

				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjList(u,v);

			}
			lee.close();

		} else {

			cout << "Unable to open file";

		}
}


void Graph::addEdgeAdjList(int u, int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
	edgesList++;
}


/************************************************* DFS *************************************************/


void Graph::DFS(int start, int goal){

	//stringstream auxiliar;

	stack <int> st;
	list <int> visited;
	vector <vector<int>> paths(nodes, vector<int>(1, -1));
	st.push(start);

	/*auxiliar <<*/ dHelp(start, goal, st, visited, paths);
	/*uxiliar <<*/ print_path(paths, start, goal);

	//return auxiliar.str();
}


void Graph::dHelp(int current, int goal, stack<int> &st, list<int> &visited, vector<vector<int>> &paths){

		if(current == goal){

			print_visited(visited);

		} else if(st.empty()){

			cout << "\nNode not found";

		}	else {

			current = st.top();
			st.pop();
			visited.push_back(current);
			for(int  i = 0; i < adjList[current].size(); i++)

				if(!contains(visited, adjList[current][i])){

					st.push(adjList[current][i]);
					paths[adjList[current][i]][0] = current;

				}
			dHelp(current, goal, st, visited, paths);
		}
}


/************************************************* BFS *************************************************/


void Graph::BFS(int start, int goal){

	//stringstream auxiliar;

	queue <int> qu;
	list <int> visited;
	vector <vector<int>> paths(nodes, vector<int>(0));
	qu.push(start);

	/*auxiliar <<*/ bHelp(start, goal, qu, visited, paths);
	/*auxiliar <<*/ print_path(paths, start, goal);

	//return auxiliar.str();

}


void Graph::bHelp(int current, int goal, queue<int> &qu, list<int> &visited, vector<vector<int>> &paths){

		if(current == goal){

			print_visited(visited);

		} else if(qu.empty()){

			cout << "\nNode not found";

		}	else {

			current = qu.front();
			qu.pop();
			visited.push_back(current);
			for(int  i = 0; i < adjList[current].size(); i++)

				if(!contains(visited, adjList[current][i])){

					qu.push(adjList[current][i]);
					paths[adjList[current][i]].push_back(current);

				}

			bHelp(current, goal, qu, visited, paths);
		}
}


void Graph::print_visited(list<int> q){
	cout << "visited: ";
	while (!q.empty()){

		cout << q.front() << " ";
		q.pop_front();
	}
}


void Graph::print_path(vector<vector <int>> &path, int start, int goal){

	int node =  path[goal][0];
	stack<int> reverse;
	reverse.push(goal);
	cout << "path:";
	while (node != start) {

		reverse.push(node);
    	node = path[node][0];

  	}

	reverse.push(start);
	while (!reverse.empty()) {

		cout << " " << reverse.top();
		reverse.pop();

  	}
}


bool Graph::contains(list<int> ls, int node){
		list<int>::iterator it;
		it = find(ls.begin(), ls.end(), node);
		if(it != ls.end())
			return true;
		else
			return false;
}


void Graph::sortAdjList(){
	for (int i = 0; i < nodes; i++)
		sort(adjList[i].begin(),adjList[i].end());
}

#endif /* Graph_H_ */