#ifndef BOGGLEUTIL_H
#define BOGGLEUTIL_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

//node class for trie
class TNode{
  public:
    TNode* parent;
    TNode* left;
    TNode* right;
    TNode* middle;
    char letter;
    bool end;

    //constructor for trie node 
    TNode(char character): letter(character){
      parent = left = right = middle = nullptr;
    }
};




//Vertex class that is used in Graph for each place
class Vertex{
  public:
    string letter;
    vector<Vertex*> adj;
    bool visited;
    unsigned int row;
    unsigned int col;

    //constructor for vertex
    Vertex(string letter, unsigned int row, unsigned int col)
     : letter(letter), row(row), col(col) {}
};

//Graph class that represents board 
class Graph{
  public:
    unsigned int rows;  //row of the board
    unsigned int cols;  //colomn of the board

    //to draw the board 
    vector<vector<Vertex*>> graph;

    //constructor of graph(board)
    Graph(unsigned int rows, unsigned int cols, string** diceArray) : rows(rows), cols(cols)
    {
      //loop through rows and colomns and insert it to Vertex and graph 
      for(unsigned int r = 0; r < rows; r++){
        vector<Vertex*> temp;
        for(unsigned int c = 0; c < cols; c++){
          string board = diceArray[r][c];
          for(unsigned int i = 0; i <board.length(); i++){
            board[i] = (char)tolower(board[i]);
          }
          temp.push_back(new Vertex(board, r, c));
        }
        graph.push_back(temp);
      }//close for loop

      //loop through adjacency list
      for(unsigned int r = 0; r < rows; r++){
        for(unsigned int c = 0; c < cols; c++){
          //loop through the index of rows and colomns
          for(int i = -1; i < 2; i++){
            for(int j = -1; i <2; j++){
              int irow = r+i;
              int jcol = c+j;
              //check if index is within the board and if it is not add to adj list
              if(irow > -1 && irow < rows && jcol > -1 && jcol < cols
                && graph[r][c] != graph[irow][jcol]) {
                graph[r][c]-> adj.push_back(graph[irow][jcol]);
              }
            }
          }
        }
      }//close for loop
    }//close constructor
};

#endif
