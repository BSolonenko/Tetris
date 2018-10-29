#ifndef TETRIS_H
#define TETRIS_H

#include "BaseApp.h"
#include "gamefield.h"
#include "FigureManager.h"
#include "Counter.h"

namespace Tetris {

class Tetris : public BaseApp {
 public:
  Tetris();

 private:
  void KeyPressed(int btnCode) override;
  void UpdateF(float deltaTime) override;
  void draw();
  bool end() const override;
  FigureManager::FigureManager manager_;
  Counter::Counter counter_;
  float divider_;
  GameField::GameField field_;
};
}

#endif  // TETRIS_H
