#include "ap_int.h"

extern "C" {

void psef_ct2_4_opt_kernel(ap_uint<64>* psef_ct2_4, ap_uint<64>* in_off_chip, uint64_t coalesced_data_num);
}