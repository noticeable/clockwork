// AUTO GEN SODA TB
#include "hrs_16_opt_kernel.h"
#include <iostream>
#include <fstream>

#define PIXEL_WIDTH 16
#define BURST_WIDTH 256

#include "runtime/test_utils.h"

using namespace std;

int main() {
  const int nrows = 1084;
  const int ncols = 1984;
  uint64_t img_pixels = nrows*ncols;
  const uint64_t bits_per_pixel = PIXEL_WIDTH;
  uint64_t img_bits = bits_per_pixel*img_pixels;
  const uint64_t num_transfers = img_bits / BURST_WIDTH;
  const uint64_t pixels_per_burst = BURST_WIDTH / bits_per_pixel;

  cout << "num transfers    : " << num_transfers << endl;
  cout << "pixels / transfer: " << pixels_per_burst << endl;

  const uint64_t transfer_cols = ncols / pixels_per_burst;
  ap_uint<BURST_WIDTH>* hrs_16 = (ap_uint<BURST_WIDTH>*) malloc(sizeof(ap_uint<BURST_WIDTH>)*num_transfers);
  ap_uint<BURST_WIDTH>* img_oc = (ap_uint<BURST_WIDTH>*) malloc(sizeof(ap_uint<BURST_WIDTH>)*num_transfers);
  fill_array_decimal<bits_per_pixel>("img_oc_input_pixel.csv", img_oc, nrows, ncols, transfer_cols);
  hrs_16_opt_kernel(hrs_16, img_oc, num_transfers);
  write_results_decimal<bits_per_pixel>("soda_hrs_16_opt_regression_result.csv", hrs_16, nrows, ncols, transfer_cols);
  free(img_oc);
  free(hrs_16);
}