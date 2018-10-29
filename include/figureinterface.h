#ifndef FIGUREINTERFACE_H
#define FIGUREINTERFACE_H

#include <cstddef>
#include <vector>
#include <memory>
using std::shared_ptr;

struct Vector2 {
  Vector2(int x, int y) : x_(x), y_(y) {}
  int x_;
  int y_;

  friend const Vector2 operator+(const Vector2& left, const Vector2& right) {
    return Vector2(left.x_ + right.x_, left.y_ + right.y_);
  }
  friend const Vector2 operator-(const Vector2& left, const Vector2& right) {
    return Vector2(left.x_ - right.x_, left.y_ - right.y_);
  }
};

using Scheme = std::vector<Vector2>;

namespace Figures {
class FigureInterface {
 public:
  virtual ~FigureInterface() {}
  virtual const Scheme& getSheme() const = 0;
  virtual const Scheme& get0Sheme() const = 0;
  virtual const Vector2& getPosition() const = 0;
  virtual void setPosition(const Vector2& position) = 0;
  virtual void draw(std::function<void(int x, int y, wchar_t c)> drawer) const = 0;
  virtual void rotate() = 0;
  virtual const Scheme& getNextRotate() const = 0;
  virtual void reset() = 0;
};

using FigureInterfacePtr = shared_ptr<FigureInterface>;
}
#endif                                        // FIGUREINTERFACE_H
