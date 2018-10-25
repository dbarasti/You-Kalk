#include<misura.h>
#include<assert.h>

void misura_spec()
{
    Misura m1;
    assert(m1.getValore() == 0);
    m1.setValore(1000);
    m1.setUnita("F");
    assert(m1.getUnita() == "F");
    assert(m1.getValore() == 1000);
    m1.reset();
    assert(m1.getValore() == 0);

    Misura m2(10, "Ohm");
    assert(m2.getMoltiplicatore() == 1);
    assert(m2.getPrefisso() == '\0');
    m2.setValore(100000);
    m2.normalizza();
    assert(m2.getValore() == 100);
    assert(m2.toString() == "100KOhm");

}

