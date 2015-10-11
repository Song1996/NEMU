#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "jcc-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "jcc-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "jcc-template.h"
#undef DATA_BYTE

make_helper_v(ja_i)
make_helper_v(jae_i)
make_helper_v(jb_i)
make_helper_v(jbe_i)
make_helper_v(jc_i)
make_helper_v(je_i)
