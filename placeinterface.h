#ifndef PLACEINTERFACE_H
#define PLACEINTERFACE_H
#include<systemc.h>

class placeInterface : public sc_interface{
public:
    // Note: A virtual function is specified pure by "= 0"
    virtual void addTokens(void) = 0;
    virtual void removeTokens(void) = 0;
    virtual bool testTokens(void) = 0;
protected:
};

#endif // PLACEINTERFACE_H
