#ifndef ENUMS_H
#define ENUMS_H


namespace Tetris {
enum class BtnCode {
  Space = 32,
  Right = 77,
  Left = 75,
  Down = 80
};
}

namespace GameField {
enum Size {
    H = 28,
    W = 15
};
}

namespace FigureManager {
enum Size {
    H = 7,
    W = 6
};
}

namespace Brush {
enum Colour {
    C1 = 32,
    C2 = 8,
    C3 = 250,
    C4 = 176
};
}

namespace Counter {
 enum Size {
    H = 4,
    W = 7
};

}

#endif //ENUM_H
