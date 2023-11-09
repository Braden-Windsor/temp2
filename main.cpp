#include <iostream>
#include <random>


using namespace std;

bool monty_hall();

void simulate(int iterations);

int main() {
  int menu = 0, runNum;

  while(menu != -1){
    
    cout << "Play (1)Monty Hall or (2)Simulate or (-1)Exit ";
    cin >> menu;
    if(menu == 1){
    bool Prize = monty_hall();
    
    if(Prize == true)
      cout << "You won a car!\n";
    else
      cout << "You won a goat!\n";
    }
    else if(menu == 2){
      cout << "Enter number of iterations: ";
      cin >> runNum;

      simulate(runNum);
    }
  }
  return 0;
}

void simulate(int iterations){
  int swappc = 0, wins = 0, losses = 0, total = 0;
  int door1 = 0, door1pc = 1, door2 = 0, door2pc = 2, door3 = 0, door3pc = 3, input = 1;
  double ratio = 0;

  cout << "Stay or swap? 0 to stay, 1 to swap: ";
  cin >> swappc;

  for(int x = 0; x < iterations; x++){
    bool Result = false;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 99);

    int doorCont = distr(gen);

    if(doorCont <= 33)
      door1 = 1;
    else
      door1 = 0;

    if(doorCont > 33 && doorCont <= 66)
      door2 = 1;
    else
      door2 = 0;

    if(doorCont > 66 && doorCont <= 99)
      door3 = 1;
    else
      door3 = 0;
    
    if(input == door1pc && door1 == 1)
      Result = true;
    
    else if(input == door2pc && door2 == 1)
      Result = true;
    
    else if(input == door3pc && door3 == 1)
      Result = true;
    
  
    else if(swappc == 1){
      if(input == door1pc && door2pc != 0)
	input = 2;
      
      else if(input == door2pc && door1pc != 0)
	input = 1;
      
      else if(input == door3pc && door1pc != 0)
	input = 1;
      
      else if(input == 3)
	input = 2;
      
      else
	input = 3;
      
      if(input == door1pc && door1 == 1)
	Result = true;

      else if(input == door2pc && door2 == 1)
	Result = true;
      
      else if(input == door3pc && door3 == 1)
	Result = true;
    }
    
    total++;
    if(Result == true)
      wins++;
    else
      losses++;
  }
  ratio = wins / (double)total;

  cout << "Total runs: " << total << "\nTotal wins: " << wins
       << "\nTotal losses: " << losses << "\nRatio of wins to total played: " << ratio << "\n";
}
bool monty_hall(){
  
  bool Result = false;
  int swap, door1, door1pc = 1, door2, door2pc = 2, door3, door3pc = 3, input;
  
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distr(1, 99);

  int doorCont = distr(gen);

  if(doorCont <= 33)
    door1 = 1;
  else
    door1 = 0;

  if(doorCont > 33 && doorCont <= 66)
    door2 = 1;
  else
    door2 = 0;

  if(doorCont > 66 && doorCont <= 99)
    door3 = 1;
  else
    door3 = 0;
  
  cout << "Pick a door: ";
  cin >> input;

  if(input != door1pc && door1 == 0){
    cout << "Door 1 had a Goat!\n"; 
    door1pc = 0;
  }
  
  else if(input != door2pc && door2 == 0){
    cout << "Door 2 had a Goat!\n";
    door2pc = 0;
  }

  else if(input != door3pc && door3 == 0){
    cout << "Door 3 had a Goat!\n";
    door3pc = 0;
  }

  cout << "Do you swap? Input 0 for no, 1 for yes: ";
  cin >> swap;

  if(swap == 0){
    if(input == door1pc && door1 == 1)
      Result = true;
    
    else if(input == door2pc && door2 == 1)
      Result = true;
    
    else if(input == door3pc && door3 == 1)
      Result = true;

  }
  
  else if(swap == 1){
    if(input == door1pc && door2pc != 0)
      input = 2;

    else if(input == door2pc && door1pc != 0)
      input = 1;

    else if(input == door3pc && door1pc != 0)
      input = 1;

    else if(input == 3)
      input = 2;
    
    else
      input = 3;

    if(input == door1pc && door1 == 1)
      Result = true;

    else if(input == door2pc && door2 == 1)
      Result = true;

    else if(input == door3pc && door3 == 1)
      Result = true;

  }
  return Result;
}
