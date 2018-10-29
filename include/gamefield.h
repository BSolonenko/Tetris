#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>
#include <cstddef>
#include <functional>
#include "FigureManager.h"
#include "figureinterface.h"

namespace GameField {

using ull = unsigned long long;
using State = std::vector<std::vector<bool> >;
using ScoreIncrement = std::function<void()>;

class GameField {
 public:
  GameField(size_t height, size_t width, FigureManager::FigureManager& manager, ScoreIncrement scoreIncrement);
  void next();
  void draw(std::function<void(int x, int y, wchar_t c)> drawer) const;
  void moveLeft();
  void moveRight();
  bool end() const;
  bool boost() const;
  void setBoost();
  void rotate();

 private:
  bool getState(const Vector2& position) const;
  void setState(const Vector2& position, bool value = true);
  bool canMerge(const Figures::FigureInterfacePtr& figure,
                const Vector2& shift = Vector2(0, 0)) const;
  bool canMerge(const Scheme& sheme,
                const Vector2& shift = Vector2(0, 0)) const;
  void merge(const Figures::FigureInterfacePtr& figure);
  void update();
  bool generateNewFigure();
  bool outOfField(const Vector2& position) const;

  State game_state_;
  size_t height_;
  size_t width_;
  Figures::FigureInterfacePtr figure_;
  FigureManager::FigureManager& manager_;
  bool boost_;
  bool end_;
  ScoreIncrement scoreIncrement_;
};
}
#endif  // GAMEFIELD_H
