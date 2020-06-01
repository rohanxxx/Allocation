#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int houseCount(int arr[], int total_houses, int budget);

const int MAX_SIZE = 100000;

int main()
{
    int arr[MAX_SIZE];
    
    //var
    int total_houses = 0;
    int total_cases = 0;
    int canBuy = 0;
    int budget = 0;
    int price = 0;

    cin >> total_cases;
    for(int i = 1; i <= total_cases; i++)
    {
        cin >> total_houses >> budget;
        for(int i = 0; i < total_houses; i++)
            cin >> arr[i];

        canBuy = houseCount(arr, total_houses, budget);
        cout << "Case #" << i << ": " << canBuy << endl;
    }
  
    return 0;
}

int houseCount(int arr[], int total_houses, int budget)
{
  int total_price, count, j;
  count = 0;
  j = 0;
  
  sort(arr, arr+total_houses);

  do
  {
    total_price = 0;

    for(int i = 0; i < (count = total_houses-j); i++)
      total_price += arr[i];
    if(total_price > budget)
      j++;

  }while(total_price > budget);

  return count;
}
