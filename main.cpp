#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void add(int* table, int &curr);
void manadd(int* table, int &curr);
void display(int index, int* table, int depth, int size);
void print(int* table);
void remove(int* table, int size);
void check(int* table, int curr);
void rcheck(int* table, int curr);

int right(int curr){
  return curr * 2 + 1;
}
int left(int curr){
  return curr * 2;
}
int parent(int curr){
  return (int) floor((curr+1)/2) - 1;
}


int main(){
  srand(time(0));
  bool quit = false;//bool to check when user wants to quit
  int* table = new int[10];//Create intial table
  int curr = 0;
  for(int i = 0; i < 10; i++){
    table[i] = -1;
  }
  while(!quit){
    cout << "Type a valid command(ADD, REMOVE, MADD, PRINT, DISPLAY, QUIT)" << endl;//Prompt user for input
    char input[10];
    cin >> input;
    if(strcmp(input, "MADD") == 0){
      manadd(table, curr);
    }
    if(strcmp(input,"ADD") == 0){//If user wants to add students
      add(table, curr);
    }
    if(strcmp(input,"REMOVE") == 0){//If user wants to add students
      remove(table, curr);
      cout << endl;
      curr = 0;
      for(int i = 0; i < 10; i++){
	table[i] = -1;
      }   
    }
    else if(strcmp(input, "DISPLAY")==0){
      display(1, table, 0, curr);
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
  cout << "How many numbers do you want to add?" << endl;
  int ninput;
  cin >> ninput;
  cin.clear();
  for(int i = 0; i < ninput; i ++){
    fstream file("nums.txt");
    char input[100];
    int count = 0;
    int num = (rand() % 50) + 1;
    int n;
    char temp[100];
    while (file.getline(input, 100, ' ')) {
      if (count == num) {
	strcpy(temp,input);
	count++;
      }
      count++;
    }
    n = atoi(temp);
    table[curr] = n;
    check(table, curr);
    curr++;
  }
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

void display(int index, int* table, int depth, int size){  
  if(right(index) <= size && right(index) != -1){
    display(right(index), table, depth + 1, size);
  }
  for(int i =0; i < depth; i++){
    cout << "\t";
  }
  cout << table[index-1] << endl;
  if(left(index) <= size && left(index) != -1){
    display(left(index), table, depth + 1, size);
  }
}

void print(int* table){
  for(int i = 0; i < 10; i++){
    cout << table[i] <<  endl;
  }
}

void check(int* table, int curr){
  if(curr != 0 && table[parent(curr)] < table[curr]){
    int temp = table[parent(curr)];
    table[parent(curr)] = table[curr];
    table[curr] = temp;
    check(table, parent(curr));
  }
    return;
}

void remove(int* table, int size){
  cout << table[0] << " ";
  table[0] = table[size-1];
  table[size-1] = -1;
  rcheck(table, 1);
  size = size - 1;
  if(size != 0){
    remove(table, size);
  }
}

void rcheck(int* table, int curr){
  if(table[right(curr)-1] > table[left(curr)-1] && table[right(curr)-1] > table[curr-1]){
    int temp = table[curr-1];
    table[curr-1] = table[right(curr)-1];
    table[right(curr)-1] = temp;
    rcheck(table, right(curr));
  }
  else if(table[left(curr)-1] > table[right(curr)-1] && table[left(curr)-1] > table[curr-1]){
    int temp = table[curr-1];
    table[curr-1] = table[left(curr)-1];
    table[left(curr)-1] = temp;
    rcheck(table, left(curr));
  }
  return;
}
