#include <iostream>
#include <chrono>
#include "powerAlgorithms.h"

using namespace std;

void output_info(long long int num_result, long long int time_taken);

int main()
{
    //the user's choice from the driver program menu
    char user_choice;
    //the number to be raised to a power
    int number{1};
    //the power a number is to be raised to
    int power{1};
    //the result obtained from any of the power algorithms
    long long int result;
    //the time at which a given algorithm was executed
    chrono::system_clock::time_point start;
    //the time at which a given algorithm finished running
    chrono::system_clock::time_point stop;
    //the total time the algorithm ran for (in nanoseconds)
    long long int elapsed;
    //whether or not a numerical result and time to obtain said result
    //should be outputted to the console
    bool output_results{false};

    cout << "\n\nWelcome to the Power Algorithms Driver!";

    do
    {
        cout << "\n\nCurrently, x = " << number << " and p = " << power << "."
                << "\n\nYour options are:"
                << "\n1) set X (the number being raised to a power)"
                << "\n2) set P (the power x is raised to)"
                << "\n3) test Naive power algorithm"
                << "\n4) test Unoptimized divide & conquer power algorithm"
                << "\n5) test Optimized divide & conquer power algorithm"
                << "\n6) Quit\n\n";
        cin >> user_choice;

        //change the number being raised to a power
        if(user_choice == '1' || tolower(user_choice) == 'x')
        {
            cout << "\n\nYou have chosen to change x. Please enter a new value.\n\n";
            cin >> number;
        }
        //change the power a number is raised to
        else if(user_choice == '2' || tolower(user_choice) == 'p')
        {
            cout << "\n\nYou have chosen to change p. Please enter a new value.\n\n";
            cin >> power;
        }
        //run the naive_power() algorithm and record time to complete
        else if(user_choice == '3' || tolower(user_choice) == 'n')
        {
            start = chrono::high_resolution_clock::now();
            result = naive_power(number, power);
            stop = chrono::high_resolution_clock::now();
            output_results = true;
        }
        //run the unoptimized_dc_power() algorithm and record time to 
        //complete
        else if(user_choice == '4' || tolower(user_choice) == 'u')
        {
            start = chrono::high_resolution_clock::now();
            result = unoptimized_dc_power(number, power);
            stop = chrono::high_resolution_clock::now();
            output_results = true;
        }
        //run the optimized_dc_power() algorithm and record time to 
        //complete
        else if(user_choice == '5' || tolower(user_choice) == 'o')
        {
            start = chrono::high_resolution_clock::now();
            result = optimized_dc_power(number, power);
            stop = chrono::high_resolution_clock::now();
            output_results = true;
        }
        //input is invalid unless user intends to quit the program
        else
        {
            if(tolower(user_choice) != '6' && tolower(user_choice) != 'q')
            {
                cout << "\n\nInvalid option selected! Please enter a new one.";
            }
        }

        //output the results if a computation was done
        if(output_results)
        {
            elapsed = chrono::duration_cast<chrono::nanoseconds>(stop-start).count();
            output_info(result, elapsed);
            output_results = false;
        }

    } while (tolower(user_choice) != '6' && tolower(user_choice) != 'q');
    

    return 0;
}

//given a numerical result and the time taken to compute it, this method 
//outputs this information
void output_info(long long int num_result, long long int time_taken)
{
    cout << "Numerical result: " << num_result
            << "\nTime to compute: " << time_taken << " nanoseconds";
}
