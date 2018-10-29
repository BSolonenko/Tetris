#ifndef COUNTER_H
#define COUNTER_H

#include <functional>

namespace Counter {
class Counter {
public:
    Counter(): score_(0){}
    void draw(std::function<void(int x, int y, wchar_t c)> drawer) const;
    Counter operator ++ ();
protected:
    int score_;
};
}
#endif // COUNTER_H
