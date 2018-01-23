#ifndef PLACE_H
#define PLACE_H

// I: Input weight
// O: Output weight
template<unsigned int I=1, unsigned int O=1>
class place : public placeInterface {
public:

    place(unsigned int number_of_tokens) : numTokens(number_of_tokens){
        // Constructor
    }

    void addTokens(){
        numTokens += I;
    }

    void removeTokens(){
        numTokens -= I;
    }

    bool testTokens() {
        return (numTokens > 0);
    }

protected:
    unsigned int numTokens;
};

#endif // PLACE_H
