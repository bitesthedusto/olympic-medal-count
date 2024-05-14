//File name: main.cpp

//Kendal Anderson igt22@txstate.edu
//Jan 23, 2024
//17.1 PA #1 Olympic medal count
//CS2308 Spring 2024

//Olympic medal count. Displays table of countries and their medals.

#include <iostream>
#include <iomanip>
using namespace std;

int const SIZE = 8;
struct Country {
      string name;
      int gold;
      int silver;
      int bronze;
   };

//showResults: display the table of countries, given an array.
//set the array of countries and their respective medal counts
//returns nothing
void showResults(Country set[]) {
   cout << left
       << setw(3) << "N"
       << setw(15) << "Country"
       << right
       << setw(10) << "Gold"
       << setw(10) << "Silver"
       << setw(10) << "Bronze"
       << setw(10) << "Total"
       << endl;
   
   for (int i = 0; i < SIZE; ++i) {
      int n = i + 1;
      int total = set[i].gold + set[i].silver + set[i].bronze;
      cout << left
         << setw(3) << n
         << setw(15) << set[i].name
         << right
         << setw(10) << set[i].gold
         << setw(10) << set[i].silver
         << setw(10) << set[i].bronze
         << setw(10) << total
         << endl;
  }
}


//addMedal: adds to appropriate medal count for chosen country.
//countries the array of countries and their respective medal counts
//num the country number from user input
//medal the designated medal type
//returns nothing
void addMedal(Country countries[], int num, char medal) {
   
   if (medal == 'g' || medal == 'G') {
      countries[num - 1].gold++;
   }
      
   else if (medal == 's' || medal == 'S') {
      countries[num - 1].silver++;
   }
      
   else if (medal == 'b' || medal == 'B') {
      countries[num - 1].bronze++;
   }
}

//totalMedals: determines total medals awarded.
//arr the array of countries and their respective medal counts
//returns total medals awarded.
int totalMedals(Country arr[]) {
   
   int total = 0;
   
   for (int i = 0; i < SIZE; ++i) {
      
      total = total + arr[i].gold + arr[i].silver
      + arr[i].bronze;
   }
   
   return total;
}

//mostTotalMedals: determines country with the most total medals.
//arr the array of countries and their respective medal counts
//returns the index of country with most medals.
int mostTotalMedals(Country arr[]) {
   int total[SIZE];
   int most;
   int idx = 0;
   
   for (int i = 0; i < SIZE; ++i) {
      
      total[i] = arr[i].gold + arr[i].silver + arr[i].bronze;
      most = total[0];
      
      if (total[i] > most) {
         most = total[i];
         idx = i;
      }
   }
   
   return idx;
}


int main() {
   // insert code here...
   
   Country countries[SIZE] = {
      {"Australia", 11, 14, 12},
      {"Canada", 5, 0, 1},
      {"China", 9, 14, 11},
      {"Great Britain", 8, 4, 8},
      {"Japan", 8, 10, 10},
      {"Netherlands", 7, 6, 7},
      {"Russia", 6, 10, 8},
      {"USA", 10, 6, 7},
   };
   
   int num;
   char medal;
   
   
   do {
      
      showResults(countries);

      cout << "Enter the country number (0 to quit):" << endl;
      cin >> num;
      
      if (num >= 1 /*&& num < SIZE*/) {
         
         cout << "Enter the medal type (G,S, or B):" << endl;
         cin >> medal;
         addMedal(countries, num, medal);
         
         mostTotalMedals(countries);
         
      }
      
   } while (num != 0);
   
   cout << "Total medals awarded: " << totalMedals(countries) << endl;
   cout << "Country with the most total medals: " << countries[mostTotalMedals(countries)].name << endl;

   
   return 0;
}
