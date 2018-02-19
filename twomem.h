#ifndef TWOMEM_H
#define TWOMEM_H
#include <systemc>
#include "subnet.h"
#include "place.h"

SC_MODULE(twomem) {
public:
    subnet s1, s2;
    place<1,1> IDLE;

    SC_CTOR(twomem) : s1("s1"), s2("s2"), IDLE(1) {
        s1.in.bind(IDLE);
        s2.in.bind(IDLE);
        s1.out.bind(IDLE);
        s2.out.bind(IDLE);

        SC_THREAD(process);
    }

    void process(){
        wait(10,SC_NS);
        s1.ACT.fire();
        wait(10,SC_NS);
        s1.ACT.fire();
        wait(10,SC_NS);
        s1.RD.fire();
        wait(10,SC_NS);
        s1.WR.fire();
        wait(10,SC_NS);
        s1.PRE.fire();
        wait(10,SC_NS);
        s1.ACT.fire();
        wait(10,SC_NS);
        s2.ACT.fire();
        wait(10,SC_NS);
        s2.ACT.fire();
        wait(10,SC_NS);
        s1.PRE.fire();
        wait(10,SC_NS);
        s2.PRE.fire();
        wait(10,SC_NS);
        s2.ACT.fire();
        wait(10,SC_NS);
        s2.PRE.fire();
        wait(10,SC_NS);
        sc_stop();
    }
};



#endif // TWOMEM_H
