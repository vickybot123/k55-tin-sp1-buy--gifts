#include <iostream>
#include "arrays.h"

using namespace std;



//int calcTotalWithVoucher(int prices[], int fees[], int n)
//{
//    int total = 0;
//    for (int i=0; i < n; i++)
//    {
//        int price = prices[i];
//        if (i==n-1)
//            price /= 2;
//        total +=  price + fees[i];
//    }
//    return total;
//}

int main()
{
    int n,k;
    cin >>n>>k;

    int  prices[n], fees[n];
    for (int i=0; i<n; i++)
        cin >> prices[i] >> fees[i];

    for (int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(prices[j]<prices[i])
            {
                arrays::swapIntArray(prices, i, j);
                arrays::swapIntArray(fees, i, j);
            }
        }
    }

    int numCows = 0;
    int prev = 0;
    for (int i=0; i<n; i++) {
        prev += fees[i];

        int total = prev + (prices[i] / 2);
        if (total > k)
            break;

        numCows = i + 1;
        prev += prices[i];
    }


//    for(int i=0; i < n; i++)
//    {
//        int numCows = i + 1;
//        int total = calcTotalWithVoucher(prices, fees, numCows);
//        if (total > k)
//            break;
//        result  = numCows;
//    }

    cout << "John can buy maximum " << numCows << " gift(s)" << endl;
    return 0;
}
