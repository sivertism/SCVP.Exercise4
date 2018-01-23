#ifndef TRANSITION_H
#define TRANSITION_H
#include<systemc.h>
#include "placeinterface.h"

// N input ports
// M output ports
template<unsigned int N=1, unsigned int M=1>
SC_MODULE (transition){
public:
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;


    SC_CTOR(transition): in("in"), out("out"){

    }

    void fire(){
        for (unsigned int i=0; i<N; ++i){
            if (!in[i]->testTokens()){
                std::cout << this->name() << ": Not Fired" << std::endl;
                return;
            }
        }

        std::cout << this->name() << ": Fired" << std::endl;

        // take a token from each input port
        for (unsigned int i=0; i<N; ++i){
            in[i]->removeTokens();
        }

        // add a token to each output port
        for (unsigned int i=0; i<M; ++i){
            out[i]->addTokens();
        }
    }

protected:

};

#endif // TRANSITION_H
