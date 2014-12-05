#ifndef BOGGLEPLAYER_H
#define BOGGLEPLAYER_H

#include "baseboggleplayer.h"
#include "boggleutil.h"
#include <vector>
#include <string>

using namespace std;

class boggleplayer: public BaseBogglePlayer {

  private:
    bool boardExist; //check if board is made or not    
    Graph* graph;  //graph
    vector<int> connection; //connection on letters that make words

  public:

    //constructor of boggleplayer
    boggleplayer(): graph(NULL), boardExist(false){};

    void setBoard(unsigned int rows, unsigned int cols, string** diceArray);

    vector<int> isOnBoard(const string& word_to_check);

    bool matchChar(string word, unsigned int position, string check);

    void getCustomBoard(string** &new_board, unsigned int *rows, unsigned int *cols);
    bool checkAdj(vector<Vertex*> adj, unsigned int length, string word);
};

#endif
~                                                                                 
~                                                                                 
~                                                                                 
~                                                                                 
~                                                                                 
~                                                                                 
~                   
