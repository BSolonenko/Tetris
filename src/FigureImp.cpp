#include "FigureImp.h"
#include "Enums.h"

namespace Figures {
FigureImpl::FigureImpl(std::vector<Scheme> schemes) : position_(Vector2(6, 0)), iterator_(0),schemes_(schemes) {

}

FigureImpl::~FigureImpl() {}

const Scheme& FigureImpl::getSheme() const {
  return schemes_[iterator_];
}

const Vector2& FigureImpl::getPosition() const {
  return position_;
}

void FigureImpl::setPosition(const Vector2& position) {
  position_ = position;
}

void FigureImpl::draw(std::function<void(int x, int y, wchar_t c)> drawer) const {
  for (auto p : getSheme()) {
    drawer(p.x_ + getPosition().x_, p.y_ + getPosition().y_, Brush::C2);
  }
}

void FigureImpl::rotate() {
  iterator_++;
  iterator_ %= schemes_.size();
}

const Scheme& FigureImpl::getNextRotate() const {
  return schemes_[(iterator_ + 1) % schemes_.size()];
}

void FigureImpl::reset() {
  position_ = Vector2(6, 0);
  iterator_ = 0;
}

const Scheme& FigureImpl::get0Sheme() const {
  return schemes_[0];
}
}
