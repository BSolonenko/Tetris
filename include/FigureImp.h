#ifndef FIGUREIMPL_H
#define FIGUREIMPL_H

#include <vector>
#include "figureinterface.h"
namespace Figures {
class FigureImpl : public FigureInterface {
 public:
  FigureImpl(std::vector<Scheme> schemes);
  ~FigureImpl();
  const Scheme& getSheme() const override;
  const Vector2& getPosition() const override;
  void setPosition(const Vector2& position) override;
  void draw(std::function<void(int x, int y, wchar_t c)> drawer) const override;
  void rotate() override;
  const Scheme& getNextRotate() const override;
  void reset() override;
  const Scheme& get0Sheme() const override;

 private:
  Vector2 position_;
  std::vector<Scheme> schemes_;
  size_t iterator_;
};

class IFigure : public FigureImpl {
 public:
  IFigure():FigureImpl({
                        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                        {{0, 0}, {1, 0}, {2, 0}, {3, 0}}
                       }){}
};

class OFigure : public FigureImpl {
 public:
  OFigure():FigureImpl({
                       {{0, 0}, {0, 1}, {1, 1}, {1, 0}}
                       }){}
};

class JFigure : public FigureImpl {
 public:
  JFigure():FigureImpl({
                       {{1,0},{1,1},{1,2},{0,2}},
                       {{0,0},{0,1},{1,1},{2,1}},
                       {{2,0},{1,0},{1,1},{1,2}},
                       {{0,0},{1,0},{2,0},{2,1}}
                       }){}
};

class LFigure : public FigureImpl {
 public:
  LFigure():FigureImpl({
                       {{0,0},{0,1},{0,2},{1,2}},
                       {{0,1},{0,0},{1,0},{2,0}},
                       {{0,0},{1,0},{1,1},{1,2}},
                       {{0,1},{1,1},{2,1},{2,0}}
                       }){}
};

class SFigure : public FigureImpl {
 public:
  SFigure():FigureImpl({
                       {{0,1},{1,1},{1,0},{2,0}},
                       {{0,0},{0,1},{1,1},{1,2}}
                       }){}
};

class ZFigure : public FigureImpl {
 public:
  ZFigure():FigureImpl({
                       {{0,0},{1,0},{1,1},{2,1}},
                       {{0,2},{0,1},{1,1},{1,0}}
                       }){}
};

class TFigure : public FigureImpl {
 public:
  TFigure():FigureImpl({
                       {{0,1},{1,1},{2,1},{1,0}},
                       {{0,0},{0,1},{0,2},{1,1}},
                       {{0,0},{1,0},{2,0},{1,1}},
                       {{1,0},{1,1},{1,2},{0,1}}
                       }){}
};
}
#endif  // FIGUREIMPL_H
