#include "conv_3x3.h"

#include "hw_classes.h"

  // bank_I_I_id0_0_to_I_out_blur_30_3
  // bank_I_I_id0_0_to_I_out_blur_30_4
  // bank_I_I_id0_0_to_I_out_blur_30_5
struct I_I_id0_0_cache {
	// Capacity: 65
	// Parition [0, 1) capacity = 1
	fifo<hw_uint<16>, 1> f0;
	// Parition [1, 32) capacity = 31
	fifo<hw_uint<16>, 31> f1;
	// Parition [32, 33) capacity = 1
	fifo<hw_uint<16>, 1> f2;
	// Parition [33, 64) capacity = 31
	fifo<hw_uint<16>, 31> f3;
	// Parition [64, 64] capacity = 1
	fifo<hw_uint<16>, 1> f4;


	inline hw_uint<16> peek_0() {
		return f0.back();
	}

	inline hw_uint<16> peek_31() {
		return f1.back();
	}

	inline hw_uint<16> peek_32() {
		return f2.back();
	}

	inline hw_uint<16> peek_63() {
		return f3.back();
	}

	inline hw_uint<16> peek_64() {
		return f4.back();
	}



	inline hw_uint<16> peek(const int offset) {
		if (offset == 0) {
			return f0.back();
		}
		if (offset == 31) {
			return f1.back();
		}
		if (offset == 32) {
			return f2.back();
		}
		if (offset == 63) {
			return f3.back();
		}
		if (offset == 64) {
			return f4.back();
		}
#ifndef __VIVADO_SYNTH__
		cout << "Error: Unsupported offset in I: " << offset << endl;
#endif // __VIVADO_SYNTH__
		assert(false);
		return 0;

	}

	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#pragma HLS dependence array inter false
#endif //__VIVADO_SYNTH__
		f4.push(f3.back());
		f3.push(f2.back());
		f2.push(f1.back());
		f1.push(f0.back());
		f0.push(value);
	}

};

struct I_cache {
  I_I_id0_0_cache I_I_id0_0;
};



inline void I_I_id0_0_write(hw_uint<16>& I_I_id0_0, I_cache& I, int root, int id1, int id0) {
	I.I_I_id0_0.push(I_I_id0_0);
}

inline hw_uint<16> I_out_blur_30_3_select(I_cache& I, int root, int d1, int d0) {
  // qpd = { out_blur_30[root, d1, d0] -> 64 : root = 0 and 0 <= d1 <= 5 and 0 < d0 <= 30; out_blur_30[root, d1, d0] -> (33 + d0) : root = 0 and d0 = 31 and 0 <= d1 <= 5; out_blur_30[root, d1, d0] -> 64 : root = 0 and d0 = 0 and 0 <= d1 <= 5 }
	hw_uint<16> value_I_I_id0_0 = I.I_I_id0_0.peek_64();
	return value_I_I_id0_0;
}

inline hw_uint<16> I_out_blur_30_4_select(I_cache& I, int root, int d1, int d0) {
  // qpd = { out_blur_30[root, d1, d0] -> 32 : root = 0 and 0 <= d1 <= 5 and 0 < d0 <= 30; out_blur_30[root, d1, d0] -> (1 + d0) : root = 0 and d0 = 31 and 0 <= d1 <= 5; out_blur_30[root, d1, d0] -> 32 : root = 0 and d0 = 0 and 0 <= d1 <= 5 }
	hw_uint<16> value_I_I_id0_0 = I.I_I_id0_0.peek_32();
	return value_I_I_id0_0;
}

inline hw_uint<16> I_out_blur_30_5_select(I_cache& I, int root, int d1, int d0) {
  // qpd = {  }
	hw_uint<16> value_I_I_id0_0 = I.I_I_id0_0.peek_0();
	return value_I_I_id0_0;
}

// # of bundles = 2
// I_id0_write
//	I_I_id0_0
inline void I_I_id0_write_bundle_write(hw_uint<16>& I_id0_write, I_cache& I, int root, int id1, int id0) {
	hw_uint<16> I_I_id0_0_res = I_id0_write.extract<0, 15>();
	I_I_id0_0_write(I_I_id0_0_res, I, root, id1, id0);
}

// out_blur_30_read
//	I_out_blur_30_3
//	I_out_blur_30_4
//	I_out_blur_30_5
inline hw_uint<48> I_out_blur_30_read_bundle_read(I_cache& I, int root, int d1, int d0) {
	hw_uint<48> result;
	hw_uint<16> I_out_blur_30_3_res = I_out_blur_30_3_select(I, root, d1, d0);
	set_at<0, 48>(result, I_out_blur_30_3_res);
	hw_uint<16> I_out_blur_30_4_res = I_out_blur_30_4_select(I, root, d1, d0);
	set_at<16, 48>(result, I_out_blur_30_4_res);
	hw_uint<16> I_out_blur_30_5_res = I_out_blur_30_5_select(I, root, d1, d0);
	set_at<32, 48>(result, I_out_blur_30_5_res);
	return result;
}





// Operation logic
inline void I_id0(HWStream<hw_uint<16> >& /* buffer_args num ports = 1 */in, I_cache& I, int root, int id1, int id0) {
	// Consume: in
	auto in_id0_c__id1_value = in.read();
	auto compute_result = id(in_id0_c__id1_value);
	// Produce: I
	I_I_id0_write_bundle_write(compute_result, I, root, id1, id0);
}

inline void out_blur_30(I_cache& I, HWStream<hw_uint<16> >& /* buffer_args num ports = 1 */out, int root, int d1, int d0) {
	// Consume: I
	auto I_d0__p__0_c__d1__p__0_value = I_out_blur_30_read_bundle_read(I/* source_delay */, root, d1, d0);
	auto compute_result = blur_3(I_d0__p__0_c__d1__p__0_value);
	// Produce: out
	out.write(compute_result);
}

// Driver function
void blur_x(HWStream<hw_uint<16> >& /* no bundle get_args num ports = 1 */in, HWStream<hw_uint<16> >& /* get_args num ports = 1 */out) {
  I_cache I;
#ifdef __VIVADO_SYNTH__
#pragma HLS dependence variable=I inter false
#endif // __VIVADO_SYNTH__

/* CUSTOM CODE STRING

*/
	for (int c0 = 0; c0 <= 7; c0 += 1)
	  for (int c1 = 0; c1 <= 31; c1 += 1) {
	    I_id0(in, I, 0, c0, c1);
	    if (c0 >= 2)
	      out_blur_30(I, out, 0, c0 - 2, c1);
	  }
	
}
