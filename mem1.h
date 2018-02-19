#ifndef MEM1_H
#define MEM1_H

#include <systemc>
#include "transition.h"
#include "place.h"

SC_MODULE(mem1){

public:

    transition<1,1> ACT, RD, PRE, WR;
    place<1,1> init, ACTIVE;

    SC_CTOR(mem1) : ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"), init(1), ACTIVE(0) {
        ACT.in.bind(init);
        ACT.out.bind(ACTIVE);
        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        PRE.in.bind(ACTIVE);
        PRE.out.bind(init);
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);

        SC_THREAD(process);
    }

    void process(){
        while(true){
            wait(10,SC_NS);
            ACT.fire();
            wait(10,SC_NS);
            ACT.fire();
            wait(10,SC_NS);
            RD.fire();
            wait(10,SC_NS);
            WR.fire();
            wait(10,SC_NS);
            PRE.fire();
            wait(10,SC_NS);
            ACT.fire();
            sc_stop();
        }
    }

};

#endif // MEM1_H
