#include "FigureManager.h"
#include <time.h>

#include "FigureImp.h"
#include "Enums.h"

namespace FigureManager {

using Figures::IFigure;
using Figures::OFigure;
using Figures::JFigure;
using Figures::LFigure;
using Figures::SFigure;
using Figures::ZFigure;
using Figures::TFigure;

FigureManager::FigureManager()
    : figures_({
                std::make_shared<IFigure>(),
                std::make_shared<OFigure>(),
                std::make_shared<JFigure>(),
                std::make_shared<LFigure>(),
                std::make_shared<SFigure>(),
                std::make_shared<ZFigure>(),
                std::make_shared<TFigure>()
                }),
                nexFigure_(0) {
  srand(time(0));
  nexFigure_ = rand() % figures_.size();
}

FigureManager::~FigureManager() {}

Figures::FigureInterfacePtr FigureManager::getNextFigure() const {
  return figures_[nexFigure_];
}

Figures::FigureInterfacePtr FigureManager::next() {
  size_t current = nexFigure_;
  nexFigure_ = rand() % figures_.size();
  figures_[current]->reset();
  return figures_[current];
}

void FigureManager::draw(std::function<void(int x, int y, wchar_t c)> drawer) {
  for(int y = 0; y < Size::H; ++y){
    for(int x = 0; x < Size::W; ++x){
        drawer(x, y, Brush::C1);
    }
  }
  drawer(1, 0, 'N');
  drawer(2, 0, 'E');
  drawer(3, 0, 'X');
  drawer(4, 0, 'T');

  for (auto p : getNextFigure()->get0Sheme()) {
    drawer(p.x_ + 2, p.y_ + 2, Brush::C2);
  }
}
}
