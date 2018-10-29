#include "Counter.h"
#include "Enums.h"
#include <string>
#include <sstream>
namespace Counter{

void Counter::draw(std::function<void(int x, int y, wchar_t c)> drawer) const {
    for(int y = 0; y < Size::H; ++y){
        for(int x = 0; x < Size::W; ++x){
            drawer(x, y, Brush::C1);
        }
    }

    std::string str = "SCORE";
    for(size_t i = 0; i < str.size(); i++){
        drawer(i + 1, 0, str[i]);
    }

    std::stringstream ss;
    ss << score_;
    str = ss.str();

    for(size_t i = 0; i < str.size(); i++){
        drawer(i + 1, 2, str[i]);
    }
}

Counter Counter::operator ++ (){
	this->score_ += GameField::Size::W;
	return *this;
}

}
