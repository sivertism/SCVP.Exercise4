#include <systemc.h>
#include "toplevel.h"
#include "mem1.h"
#include "twomem.h"

// Place Interface:
// TODO

// Place Channel:
// TODO

// Transition:
// TODO

// TOPLEVEL

int sc_main(int argc, char* argv[])
{
    //toplevel t("t");
    //mem1 t("mem1");
    twomem t("twomem");
    sc_start();
    return 0;
}
