#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>

using namespace std;

void add(int* table, int &curr);
void manadd(int* table, int &curr);
void display(int* table);
void print(int* table);
void check(int* table, int curr);

int main(){
  bool quit = false;//bool to check when user wants to quit
  int* table = new int[10];//Create intial table
  char input[7];
  int curr = 0;
  for(int i = 0; i < 10; i++){
    table[i] = -1;
  }
  while(!quit){
    cout << "Type a valid command(ADD, MADD, PRINT, DISPLAY, QUIT)" << endl;//Prompt user for input
    cin >> input;
    if(strcmp(input, "MADD") == 0){
      manadd(table, curr);
    }
    if(strcmp(input,"ADD") == 0){//If user wants to add students
      add(table, curr);
    }
    else if(strcmp(input, "ALL")==0){
      display(table);
    }
    else if(strcmp(input,"PRINT") == 0){//If user wants to print a specific student
      print(table);
    }
    else if(strcmp(input,"QUIT") == 0){//If user wants to quit
      quit = true;
    }
  }
  return 0;
}  


void add(int* table, int &curr){
  
}

void manadd(int* table, int &curr){
  cout << "Waht is the number you want to add(1-1000)" << endl;
  int input;
  cin >> input;
  cin.clear();
  table[curr] = input;

  check(table, curr);

  curr++;
}

void display(int* table){

}

void print(int* table){

}

void check(int* table, int curr){
  if(curr != 0 && table[(int) floor((curr+1)/2) - 1] < table[curr]){
    int temp = table[(int) floor((curr+1)/2) - 1];
    table[(int) floor((curr+1)/2) - 1] = table[curr];
    table[curr] = temp;
    check(table, floor((curr+1)/2) - 1);
  }
    return;
}
