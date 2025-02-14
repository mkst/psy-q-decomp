#include "libspu_i.h"

long SpuSetReverb(long on_off) {
    unsigned int new_var;
    u16 var_v1;
    switch (on_off) {
    case 0:
        _spu_rev_flag = 0;
        var_v1 = _spu_RXX->rxx.spucnt;
        var_v1 = var_v1 & 0xFF7F;
        _spu_RXX->rxx.spucnt = var_v1;
        break;

    case 1:
        if ((_spu_rev_reserve_wa != on_off) &&
            (_SpuIsInAllocateArea_(_spu_rev_offsetaddr) != 0)) {
            _spu_rev_flag = 0;
            var_v1 = _spu_RXX->rxx.spucnt;
            var_v1 = var_v1 & 0xFF7F;
            new_var = var_v1;
            _spu_RXX->rxx.spucnt = new_var;
        } else {
            _spu_rev_flag = on_off;
            var_v1 = (new_var = _spu_RXX->rxx.spucnt) | 0x80;
            _spu_RXX->rxx.spucnt = var_v1;
        }
        break;
    }

    return _spu_rev_flag;
}