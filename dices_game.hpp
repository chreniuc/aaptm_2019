#ifndef DICES_GAME_HPP
#define DICES_GAME_HPP

#include <random>

class dices_game
{
  const unsigned int number_of_dices{0};
  const unsigned int sum_to_look_for{0};
  const unsigned int number_of_iterations{0};
  const unsigned int number_of_faces_of_dice{0};

  unsigned int number_of_successful_guess{0};

  ::std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution<> dis;

  dices_game() = delete;

public:
  dices_game(const unsigned int& number_of_dices,
             const unsigned int& sum_to_look_for,
             const unsigned int& number_of_iterations, const unsigned int&number_of_faces_of_dice);

  void prepare_for_run();
  void run();

  void print_results();

  double get_result();
};

#endif // DICES_GAME_HPP
