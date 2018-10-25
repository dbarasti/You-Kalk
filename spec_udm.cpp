#include<udm.h>
#include<assert.h>
#include<iostream>

void udm_spec()
{

    assert(UdM::offset == 3);
    // caso semplice
    UdM u1("F");
    assert(u1.getUnita() == "F");
    assert(u1.getPrefisso() == '\0');
    assert(u1.getMoltiplicatore() == 1);
    assert(u1.getPrefisso() == '\0');
    u1.next();
    assert(u1.getPrefisso() == 'K');
    assert(u1.getMoltiplicatore() == 1000);
    u1.next();
    assert(u1.getPrefisso() == 'M');
    assert(u1.getMoltiplicatore() == 1000000);
    u1.next();
    assert(u1.getPrefisso() == 'M');
    assert(u1.getMoltiplicatore() == 1000000);

    // caso K
    UdM u2("Ohm", 'K');
    assert(u2.getUnita() == "Ohm");
    assert(u2.getMoltiplicatore() == 1000);
    assert(u2.getPrefisso() == 'K');
    u2.next();
    assert(u2.getPrefisso() == 'M');
    assert(u2.getMoltiplicatore() == 1000000);
    u2.next();
    assert(u2.getPrefisso() == 'M');
    assert(u2.getMoltiplicatore() == 1000000);


    // caso prefisso non esistente

    UdM u3("ohm");
    assert(u3.getUnita() == "ohm");
    assert(u3.getMoltiplicatore() == 1);
    assert(u3.getPrefisso() == '\0');
    u3.next();
    assert(u3.getPrefisso() == 'K');
    assert(u3.getMoltiplicatore() == 1000);
    u3.next();
    assert(u3.getPrefisso() == 'M');
    assert(u3.getMoltiplicatore() == 1000000);
    u3.setPrefisso('K');
    assert(u3.getMoltiplicatore() == 1000);

    try{ u3.setPrefisso('L'); }
    catch(const std::invalid_argument & e){
        std::cout << "exception " << e.what() <<" has been thrown;" << std::endl;
        std::cout << "setPrefix(..) has not been completed" << std::endl;
        assert(u3.getPrefisso() == 'K');
    }

    //cambio unità

    u3.setUnita("H");
    assert(u3.getUnita() == "H");
    assert((u3.getPrefisso() + u3.getUnita()) == "KH");

    //prev
    UdM u4("ohm", 'n');
    assert(u4.getMoltiplicatore() == 0.000000001 );
    u4.setPrefisso('m');
    assert(u4.getPrefisso() == 'm');
    assert(u4.getMoltiplicatore() == 0.001);
}

