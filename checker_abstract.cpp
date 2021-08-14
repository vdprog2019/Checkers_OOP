#include "checker_abstract.h"

checker_abstract::checker_abstract(int pos_x)
{
    this->position_X = pos_x;
    this->isCrown = false;
}
checker_abstract::checker_abstract(){

}
void checker_abstract::moveNext(int to){
    this->position_X = to;
}
void checker_abstract::Dead(){
    this->position_X = -1;
}
