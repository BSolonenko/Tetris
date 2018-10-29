#ifndef FIGUREMANAGER_H
#define FIGUREMANAGER_H

#include "figureinterface.h"
#include <vector>

namespace FigureManager {

class FigureManager {
 public:
  FigureManager();
  ~FigureManager();
  Figures::FigureInterfacePtr getNextFigure() const;
  Figures::FigureInterfacePtr next();
  void draw(std::function<void(int x, int y, wchar_t c)> drawer);

 private:
  std::vector<Figures::FigureInterfacePtr> figures_;
  size_t nexFigure_;
};
}
#endif  // FIGUREMANAGER_H
