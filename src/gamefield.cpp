#include "gamefield.h"

#include <iostream>
#include "Enums.h"

namespace GameField {

GameField::GameField(size_t height, size_t width, FigureManager::FigureManager& manager, ScoreIncrement scoreIncrement)
    : height_(height)
    , width_(width)
    , end_(false)
    , game_state_(height, std::vector<bool>(width, false))
    , figure_(nullptr)
    , boost_(false)
    , manager_(manager)
    , scoreIncrement_(scoreIncrement) {
  figure_ = manager_.next();
}

void GameField::next() {
  if (canMerge(figure_, Vector2(0, 1))) {
    figure_->setPosition(figure_->getPosition() + Vector2(0, 1));
    return;
  }

  merge(figure_);
  update();
  if (!generateNewFigure()) {
    end_ = true;
  }
}

bool GameField::getState(const Vector2& position) const {
  if (outOfField(position)) {
    return false;
  }

  return game_state_[position.y_][position.x_];
}

void GameField::setState(const Vector2& position, bool value) {
  if (outOfField(position)) {
    return;
  }

  game_state_[position.y_][position.x_] = value;
}

bool GameField::canMerge(const Figures::FigureInterfacePtr& figure,
                         const Vector2& shift) const {
  return canMerge(figure->getSheme(), shift + figure->getPosition());
}

bool GameField::canMerge(const Scheme& sheme, const Vector2& shift) const {
  for (auto& point : sheme) {
    Vector2 newPoint = point + shift;
    if (outOfField(newPoint) || getState(newPoint)) {
      return false;
    }
  }
  return true;
}

void GameField::merge(const Figures::FigureInterfacePtr& figure) {
  for (auto& point : figure->getSheme()) {
    setState(point + figure->getPosition());
  }
}

bool GameField::generateNewFigure() {
  figure_ = manager_.next();
  return canMerge(figure_);
}

bool GameField::outOfField(const Vector2& position) const {
  return position.x_ >= width_ || position.y_ >= height_ || position.x_ < 0 ||
         position.y_ < 0;
}

void GameField::moveLeft() {
  if (canMerge(figure_, Vector2(-1, 0))) {
    figure_->setPosition(figure_->getPosition() + Vector2(-1, 0));
  }
}

void GameField::moveRight() {
  if (canMerge(figure_, Vector2(1, 0))) {
    figure_->setPosition(figure_->getPosition() + Vector2(1, 0));
  }
}

bool GameField::end() const {
  return end_;
}

bool GameField::boost() const {
  return boost_;
}

void GameField::setBoost() {
  boost_ = true;
}

void GameField::rotate() {
  if (canMerge(figure_->getNextRotate(), figure_->getPosition()))
    figure_->rotate();
}

void GameField::draw(
    std::function<void(int x, int y, wchar_t c)> drawer) const {
  for (size_t i = 0; i < game_state_.size(); ++i) {
    for (size_t j = 0; j < game_state_[i].size(); ++j) {
      getState(Vector2(j, i)) ? drawer(j, i, Brush::C2) : drawer(j, i, Brush::C3);
    }
  }
  figure_->draw(drawer);
}

void GameField::update() {
  boost_ = false;

  auto shiftUp = [this](size_t line) {
    for (size_t i = line; i > 0; --i) {
      this->game_state_[i] = this->game_state_[i - 1];
    }
  };

  for (size_t i = 0; i < game_state_.size(); ++i) {
    bool allTrue = true;
    for (size_t j = 0; j < game_state_[i].size(); ++j) {
        allTrue &= game_state_[i][j];
    }
    if (allTrue) {
      shiftUp(i);
      scoreIncrement_();
    }
  }
}
}
