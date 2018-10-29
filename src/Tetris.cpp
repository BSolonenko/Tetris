#include "Tetris.h"
#include <iostream>
#include "Enums.h"

namespace Tetris {

Tetris::Tetris() : field_(GameField::Size::H, GameField::Size::W, manager_, [this](){++this ->counter_;}),
BaseApp(GameField::Size::W + Counter::Size::W + 2, GameField::Size::H + 1) {
  divider_ = 0;
for(int i = 0; i < GameField::Size::H + 2; ++i){
    for(int j = 0; j < GameField::Size::W + Counter::Size::W + 3; ++j){
        SetChar(j, i, Brush::C4);
    }
  }
}

void Tetris::KeyPressed(int btnCode) {
  if (field_.boost()) {
    return;
  }
  switch (static_cast<BtnCode>(btnCode)) {
    case BtnCode::Down: {
      field_.setBoost();
      break;
    }
    case BtnCode::Left: {
      field_.moveLeft();
      break;
    }
    case BtnCode::Right: {
      field_.moveRight();
      break;
    }
    case BtnCode::Space: {
      field_.rotate();
      break;
    }
  }
  draw();
}

void Tetris::UpdateF(float deltaTime) {
  if (!field_.boost()) {
    divider_+=deltaTime;
    if (divider_ < 0.5) {
      return;
    }
    divider_ = 0;
  }
    field_.next();
    draw();
}

void Tetris::draw() {
      field_.draw(
      [this](int x, int y, wchar_t c) { this->SetChar(x + 1, y + 1, c); });

  manager_.draw(
      [this](int x, int y, wchar_t c) { this->SetChar(x + GameField::Size::W + 3, y + Counter::Size::H + 2, c); });

  counter_.draw([this](int x, int y, wchar_t c) { this->SetChar(x + GameField::Size::W + 2, y + 1, c); });

}

bool Tetris::end() const {
  return field_.end();
}

}
