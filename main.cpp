/*
This is a class that is a max heap that lets you add, print, display and remove stuff from a heap

Last Modified: 4/3/22

Help from: Kyle Zhou

By: Kushal Rao
*/
//Imports
#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
//Methods
void add(int* table, int &curr);
void check(int* table, int curr);
void display(int index, int* table, int depth, int size);
void manadd(int* table, int &curr);
void print(int* table);
void rcheck(int* table, int curr);
void remove(int* table, int size);
//Methods that give the index for children, left and right, and the parent
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
  int* table = new int[100];//Create intial table
  int curr = 0;//Create original index
  for(int i = 0; i < 100; i++){//Set all values to -1
    table[i] = -1;
  }
  while(!quit){//Main while
    cout << "Type a valid command(ADD, REMOVE, MADD, PRINT, DISPLAY, QUIT)" << endl;//Prompt user for input
    char input[10];//Get input from user
    cin >> input;
    if(strcmp(input, "MADD") == 0){//if user wants to manually add
      manadd(table, curr);
    }
    if(strcmp(input,"ADD") == 0){//If user wants to add students
      add(table, curr);
    }
    if(strcmp(input,"REMOVE") == 0){//If user wants to remove from heap, printing it out in the process
      remove(table, curr);
      cout << endl;
      curr = 0;
      for(int i = 0; i < 100; i++){
	table[i] = -1;
      }   
    }
    else if(strcmp(input, "DISPLAY")==0){//Dislay the heap as a tree
      display(1, table, 0, curr);
    }
    else if(strcmp(input,"PRINT") == 0){//If user wants to print the array
      print(table);
    }
    else if(strcmp(input,"QUIT") == 0){//If user wants to quit
      quit = true;
    }
  }
  return 0;
}  

void add(int* table, int &curr){//If user wants to add using the file
  cout << "How many numbers do you want to add?" << endl;
  int ninput;
  cin >> ninput;
  cin.clear();
  for(int i = 0; i < ninput; i ++){//Create how many numbers the user wants
    fstream file("nums.txt");//Import the number file
    char input[100];
    int count = 0;
    int num = (rand() % 50) + 1;
    int n;
    char temp[100];
    //Get random number and add it to the array
    while (file.getline(input, 100, ' ')) {
      if (count == num) {
	strcpy(temp,input);
	count++;
      }
      count++;
    }
    n = atoi(temp);
    table[curr] = n;
    check(table, curr);//Check if there is a child larger than its parent
    curr++;
  }
}

void manadd(int* table, int &curr){//Add manually
  cout << "Waht is the number you want to add(1-1000)" << endl;
  int input;
  cin >> input;
  cin.clear();
  table[curr] = input;
  check(table, curr);//Check if there is a child larger that its parent
  curr++;
}

void display(int index, int* table, int depth, int size){//If user wants to display the heap as a tree using recurrsion
  if(right(index) <= size && right(index) != -1){//If there is a right call print on the right
    display(right(index), table, depth + 1, size);
  }
  for(int i =0; i < depth; i++){//print tabs then yourself
    cout << "\t";
  }
  cout << table[index-1] << endl;
  if(left(index) <= size && left(index) != -1){//Call print on the left if there is a left
    display(left(index), table, depth + 1, size);
  }
}

void print(int* table){//Print the array
  for(int i = 0; i < 100; i++){
    cout << table[i] <<  endl;
  }
}

void check(int* table, int curr){//Check if there is a child larger than its parent
  if(curr != 0 && table[parent(curr)] < table[curr]){//If child is greater than its parent
    //Switch values
    int temp = table[parent(curr)];
    table[parent(curr)] = table[curr];
    table[curr] = temp;
    //Call check on the new parent
    check(table, parent(curr));
  }
    return;
}

void remove(int* table, int size){//Use iteration to print all the values
  while(size != 0){//While there is numbers in the array
    cout << table[0] << " ";//Print the root of the tree
    table[0] = table[size - 1];//Switch the root with the last number in the array
    table[size - 1] = -1;
    rcheck(table, 1);//Check if the new root needs to be switched
    size = size - 1;
  }
}

void rcheck(int* table, int curr){//Use reccursion to switch a parent with its child if the children are larger
  if(table[right(curr)-1] >= table[left(curr)-1] && table[right(curr)-1] > table[curr-1]){//If right is greater than the parent and left
    //Switch and call check on the new child
    int temp = table[curr-1];
    table[curr-1] = table[right(curr)-1];
    table[right(curr)-1] = temp;
    rcheck(table, right(curr));
    return;
  }
  if(table[left(curr)-1] > table[right(curr)-1] && table[left(curr)-1] > table[curr-1]){//If left is greater than the parent and right
    //Switch and call check on the new child
    int temp = table[curr-1];
    table[curr-1] = table[left(curr)-1];
    table[left(curr)-1] = temp;
    rcheck(table, left(curr));
    return;
  }
}
