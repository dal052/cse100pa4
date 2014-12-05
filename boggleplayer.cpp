#include <algorithm>
#include "boggleplayer.h"

using namespace std;

void boggleplayer::setBoard(unsigned int rows, unsigned int cols, stirng** diceArray){
  graph = new Graph(rows, cols, diceArray);
  boardExist = true;
}


//check if word exists on board
vector<int> boggleplayer::isOnBoard(const string& word_to_check) {
  Vertex* path;
  int length;

  for(unsigned int r = 0; r < graph->rows; r++) {
    for(unsigned int c = 0; c < graph->cols; c++) {
      graph->graph[r][c]->visited = false;
    }
  }

  //get connection to start if board does not exits
  if(!boardExist)
    return connection;

  for(unsigned int r = 0; r< graph->rows; r++){
    for(unsigned int c = 0; c< graph->cols; c++){
      path = graph->graph[r][c];
      //check if length and char matched
      if(matchChar(path->letter, 0, word_to_check)){
        length = path->letter.length();
        path->visited = true;
        connection.clear();
        connection.push_back((path->row)*(graph->cols)+(path->col));

        if(checkAdj(path->adj, length, word_to_check))
          return connection;
        else
          connection.pop_back();
        path->visited = false;
      }
    }
  }
  connection.clear();
  return connection;
}



//compare if letter matches 
bool boggleplayer::matchChar(string word, unsigned int position, string check){
  for(unsigned int w = 0; w <word.length(); w++){
    if(check.length() <= w+position || word[w] != check[w+position])
      return false;
  }
  return true;
}

//check adjacency for word on board
bool boggleplayer::checkAdj(vector<Vertex*>adj, unsigned int length, string word){
  bool flag = false;

  if(length == word.length()){
    return true;
  }

  for(unsigned int i = 0; i < adj.size(); i++){
    if(!adj[i]->visited && matchChar(adj[i]->letter, length, word)){
      adj[i]->visited = true;
      connection.push_back((adj[i]->row)*(graph->cols)+(adj[i]->col));

      //recursive call 
      flag = checkAdj(adj[i]->adj, length+adj[i]->letter.length(), word);
      adj[i]->visited = false;

      if(flag)
        return true;

      connection.pop_back();
    }
  }
  return flag;
}


void boggleplayer::getCustomBoard(string** &new_board, unsigned int *rows, unsigned int *cols){
  *cols = 4;
  *rows = 4;

  new_board = new string*[*rows];
  for(int r = 0; r < *rows; r++){
    new_board[r] = new string[*cols];
  }

  new_board[0][0] = "O";
  new_board[0][1] = "H";
  new_board[0][2] = "N";
  new_board[0][3] = "E";

  new_board[1][0] = "S";
  new_board[1][1] = "T";
  new_board[1][2] = "T";
  new_board[1][3] = "U";

  new_board[2][0] = "Y";
  new_board[2][1] = "C";
  new_board[2][2] = "R";
  new_board[2][3] = "I";

  new_board[3][0] = "S";
  new_board[3][1] = "S";
  new_board[3][2] = "O";
  new_board[3][3] = "E";
}

