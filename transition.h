#ifndef TRANSITION_H
#define TRANSITION_H
#include<systemc.h>
#include "placeinterface.h"

// N input ports
// M output ports
// L inhibitor ports
template<unsigned int M=1, unsigned int N=1, unsigned int L=0>
SC_MODULE (transition){
public:
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;


    SC_CTOR(transition): in("in"), out("out"), inhibitors("inhibitors"){

    }

    void fire(){

        // Check if there are enough tokens on every input.
        for (unsigned int i=0; i<N; ++i){
            if ((!in[i]->testTokens()) || ((L>0) ? inhibitors[i]->testTokens() : 0)){
                std::cout << this->name() << ": Not Fired" << std::endl;
                return;
            }
        }

        std::cout << this->name() << ": Fired" << std::endl;

        // take tokens from each input port
        for (unsigned int i=0; i<N; ++i){
            in[i]->removeTokens();
        }

        // add tokens to each output port
        for (unsigned int i=0; i<M; ++i){
            out[i]->addTokens();
        }
    }

protected:

};

#endif // TRANSITION_H
