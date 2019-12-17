#include <iostream>
#include <random>

#include "dices_game.hpp"

using namespace ::std;

//----------------------------------------------------------------------------//
dices_game::dices_game(const unsigned int &number_of_dices,
                       const unsigned int &sum_to_look_for,
                       const unsigned int &number_of_iterations,
                       const unsigned int&number_of_faces_of_dice):
  number_of_dices(number_of_dices), sum_to_look_for(sum_to_look_for),
  number_of_iterations(number_of_iterations), number_of_faces_of_dice(number_of_faces_of_dice)
{
  cout << "-------------------------------------------------------------"<<endl;
  cout << "Starting dice game with the following dates:"<<endl;
  cout << "number_of_dices = " << number_of_dices << endl;
  cout << "sum_to_look_for = " << sum_to_look_for << endl;
  cout << "number_of_iterations = " << number_of_iterations << endl;
  cout << "-------------------------------------------------------------"<<endl;
}
//----------------------------------------------------------------------------//
void dices_game::prepare_for_run()
{
  cout << "Getting ready..." << endl;
  cout << "Preparing random utils..." << endl;
  gen = std::mt19937(rd());
  dis = std::uniform_int_distribution<> (1,number_of_faces_of_dice);
  cout << "Ready to run." << endl;
  cout << "-------------------------------------------------------------"<<endl;
}
//----------------------------------------------------------------------------//
void dices_game::run()
{
  number_of_successful_guess = 0;
  for(auto i = 0u ; i < number_of_iterations; i++)
  {
    unsigned int local_sum{0};
    for(auto dices = 0u; dices < number_of_dices; dices++)
    {
      unsigned int number_generated = dis(gen);
      //cout << "Generated number: " << number_generated << endl;
      local_sum += number_generated;
    }
    //cout << "Sum: " << local_sum << endl;
    if(local_sum >= sum_to_look_for)
    {
      number_of_successful_guess++;
    }
  }
}
//----------------------------------------------------------------------------//
void dices_game::print_results()
{
  cout << "-------------------------------------------------------------"<<endl;
  cout << "Result: " <<  (1.0 * number_of_successful_guess)/ number_of_iterations << endl;
}
//----------------------------------------------------------------------------//
double dices_game::get_result()
{
  return (1.0 * number_of_successful_guess)/ number_of_iterations;
}
//----------------------------------------------------------------------------//
