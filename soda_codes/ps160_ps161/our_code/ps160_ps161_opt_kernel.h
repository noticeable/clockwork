#include "ap_int.h"

extern "C" {

void ps160_ps161_opt_kernel(ap_uint<256>* ps160, ap_uint<256>* ps161, ap_uint<256>* in_off_chip0_oc, ap_uint<256>* in_off_chip1_oc, uint64_t coalesced_data_num);
}