
// SlkTable.cpp - generated by the SLK parser generator 

#include "SlkAction.h"

void
SlkAction ::
initialize_table ( void )
{
    Action [ 0 ] = 0;
    Action [ 1 ] = &SlkAction::Finish;
    Action [ 2 ] = &SlkAction::Push;
    Action [ 3 ] = &SlkAction::Add;
    Action [ 4 ] = &SlkAction::Multiply;
    Action [ 5 ] = &SlkAction::Exponent;
    Action [ 6 ] = &SlkAction::Negate;
}
