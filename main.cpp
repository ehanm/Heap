#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;

void addmanually(int num, int *heap);
void addfile(int* heap); // WORK ON THIS FRIDAY


int main(){

  cout << "Welcome to heap!" << endl;

  bool stillgoing = true;
  char input[100];
  int *heap;
  heap = new int[100];

  for (int i = 0; i < 100; i++){

    heap[i] = NULL;

  }

  
  while (stillgoing == true){

    cout << "What would you like to do? (ADD, FILE, DELETE, QUIT, DISPLAY)" << endl;

    cin >> input;

    if (strcmp(input, "ADD") == 0){

      int x;
      
      // add function
      cout << "Enter the number you would like to add: " << endl;

      cin >> x;

      addmanually(x, heap);

      
    }

    else if (strcmp(input, "FILE") == 0) {

      addfile(heap);
      
    }

    else if (strcmp(input, "DELETE") == 0) {

      int g;
      
      cout << "Enter the number you would like to delete: ";

      cin >> g;

      for (int i = 0; i < 100; i++) {

	if (heap[i] != NULL) {

	  if (heap[i] == g){

	    heap[i] = NULL;

	    sort(heap, heap + 100, greater<int>());

	  }

	}

      }

    }

    else if (strcmp(input, "QUIT") == 0) {

      stillgoing = false;
      break;
      
    }

    else if (strcmp(input, "DISPLAY") == 0) {

      // develop tree
      
      for (int i = 0; i < 100; i++) {

	if (heap[i] != NULL){

	  cout << heap[i] << " " << i << endl;

	}

      }

    }

    else {

      cout << "invalid input!";
      
    }
    


  }

}


void addmanually(int num, int *heap){
  
  for (int i = 0; i < 100; i++){

    if (heap[i] == NULL){

      heap[i] = num;
      break;

    }

  }

  // sorting method learned here: https://www.tutorialkart.com/cpp/cpp-sort-integer-array/#:~:text=C%2B%2B%20Program%20%E2%80%93%20Sort%20Integer%20Array%20To%20sort,%28%29%20as%20third%20argument%20to%20sort%20%28%29%20function.

  sort(heap, heap + 100, greater<int>());

}

void addfile(int *heap){

  cout << "reading in numbers from file..." << endl;
  
  ifstream inputfile("numbers.txt");
  
  for (int i = 0; i < 100; i++){

    if (heap[i] == NULL) {
      
      inputfile >> heap[i];

    }
  }

  sort(heap, heap + 100, greater<int>());

}

