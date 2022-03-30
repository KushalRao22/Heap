#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void add(int* table, int &curr);
void manadd(int* table, int &curr);
void display(int* table, int* o);
void print(int* table);
void check(int* table, int curr);
void order(int* table, int* order, int curr);
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
  char input[7];
  int o[10];
  int curr = 0;
  for(int i = 0; i < 10; i++){
    table[i] = -1;
    o[i] = -1;
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
    else if(strcmp(input, "DISPLAY")==0){
      order(table, o, curr);

      display(table, o);
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
    int num = (rand() % 20) + 1;
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

void order(int* table, int* order, int curr){
  for(int i = 0; i < 10; i++){
    
  }
}

void display(int* table, int* o){
  
  
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
