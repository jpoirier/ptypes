

#include "pasync.h"


PTYPES_BEGIN


pmemlock _mtxtable[_MUTEX_HASH_SIZE] // currently 29
#ifndef WIN32
    = {
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT, _MTX_INIT,
    _MTX_INIT
}
#endif
;


PTYPES_END
