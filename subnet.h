#ifndef SUBNET_H
#define SUBNET_H
#include <systemc>
#include "transition.h"
#include "placeinterface.h"
#include "place.h"


SC_MODULE(subnet){
public:

    transition<1,1,0> RD, PRE, WR;
    transition<1,1,1> ACT;
    place<1,1> ACTIVE;

    sc_port<placeInterface> in;
    sc_port<placeInterface> out;

    SC_CTOR(subnet) : RD("RD"), PRE("PRE"), WR("R"), ACT("ACT"), ACTIVE(0), in("in"), out("out") {
        ACT.in.bind(in);
        ACT.inhibitors.bind(ACTIVE);
        ACT.out.bind(ACTIVE);

        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);

        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);

        PRE.in.bind(ACTIVE);
        PRE.out.bind(out);
    }
};

#endif // SUBNET_H
