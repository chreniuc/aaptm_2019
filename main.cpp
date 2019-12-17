#include <iostream>
#include <fstream>
#include <chrono>
#include "dices_game.hpp"

using namespace std;

int main()
{
    cout << "AAPTM Project - Sum of X dices - Monte carlo" << endl;
    cout << "Student: Hreniuc Cristian-Alexandru" << endl;
    cout << "3172a" << endl;

    unsigned int number_of_dices{0};
    unsigned int sum_to_look_for{0};
    unsigned int number_of_iterations{0};
    unsigned int number_of_results{0};
    unsigned int number_of_faces_of_dice{0};


    cout << "Insert the number of dices: ";
    cin >> number_of_dices;

    cout << "Insert the number of faces of a dice: ";
    cin >> number_of_faces_of_dice;

    cout << endl << "Insert the sum to look for(We will look for a sum be(>=) than this value): ";
    cin >> sum_to_look_for;

    cout << endl;

    if(sum_to_look_for > (number_of_dices * 6))
    {
        cout << endl << "The sum will be impossible to find,"
         " because the max sum we can get from those dices is:"
         " 6 * number of dices, which is: " << number_of_dices * 6 << endl;
        exit(1);
    }

    if(sum_to_look_for < number_of_dices )
    {
        cout << endl << "The sum will be impossible to find,"
         " because the min sum we can get from those dices is:"
         "number of dices, which is: " << number_of_dices << endl;
        exit(1);
    }
    cout << endl << "Insert the number of iterations to try: ";
    cin >> number_of_iterations;

    cout << endl << "How many results do you want to get: ";
    cin >> number_of_results;

    dices_game dg(number_of_dices, sum_to_look_for,number_of_iterations, number_of_faces_of_dice);
    dg.prepare_for_run();

    double results[number_of_results];
    for(auto i = 0u; i < number_of_results; i++)
    {
      dg.run();
      dg.print_results();
      results[i] = dg.get_result();
    }

    auto start = std::chrono::system_clock::now();
     std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    ofstream myfile;
    myfile.open ("results_"s +to_string(end_time) + ".txt"s);
    for(auto val : results)
    {
      myfile << val << endl;
    }
    myfile.close();
    return 0;
}
