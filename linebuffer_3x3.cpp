#include "hw_classes.h"

struct write0_cache {
	// Capacity: 131
	// Parition [0, 1) capacity = 1
	fifo<hw_uint<32> , 1> f0;
	// Parition [1, 2) capacity = 1
	fifo<hw_uint<32> , 1> f2;
	// Parition [2, 3) capacity = 1
	fifo<hw_uint<32> , 1> f4;
	// Parition [3, 64) capacity = 61
	fifo<hw_uint<32> , 61> f5;
	// Parition [64, 65) capacity = 1
	fifo<hw_uint<32> , 1> f6;
	// Parition [65, 66) capacity = 1
	fifo<hw_uint<32> , 1> f8;
	// Parition [66, 67) capacity = 1
	fifo<hw_uint<32> , 1> f10;
	// Parition [67, 128) capacity = 61
	fifo<hw_uint<32> , 61> f11;
	// Parition [128, 129) capacity = 1
	fifo<hw_uint<32> , 1> f12;
	// Parition [129, 130) capacity = 1
	fifo<hw_uint<32> , 1> f14;
	// Parition [130, 130] capacity = 1
	fifo<hw_uint<32> , 1> f16;


	inline hw_uint<32>  peek_0() {
		return f0.back();
	}

	inline hw_uint<32>  peek_1() {
		return f2.back();
	}

	inline hw_uint<32>  peek_2() {
		return f4.back();
	}

	inline hw_uint<32>  peek_63() {
		return f5.back();
	}

	inline hw_uint<32>  peek_64() {
		return f6.back();
	}

	inline hw_uint<32>  peek_65() {
		return f8.back();
	}

	inline hw_uint<32>  peek_66() {
		return f10.back();
	}

	inline hw_uint<32>  peek_127() {
		return f11.back();
	}

	inline hw_uint<32>  peek_128() {
		return f12.back();
	}

	inline hw_uint<32>  peek_129() {
		return f14.back();
	}

	inline hw_uint<32>  peek_130() {
		return f16.back();
	}



	inline hw_uint<32>  peek(const int offset) {
		if (offset == 0) {
			return f0.back();
		}
		if (offset == 1) {
			return f2.back();
		}
		if (offset == 2) {
			return f4.back();
		}
		if (offset == 63) {
			return f5.back();
		}
		if (offset == 64) {
			return f6.back();
		}
		if (offset == 65) {
			return f8.back();
		}
		if (offset == 66) {
			return f10.back();
		}
		if (offset == 127) {
			return f11.back();
		}
		if (offset == 128) {
			return f12.back();
		}
		if (offset == 129) {
			return f14.back();
		}
		if (offset == 130) {
			return f16.back();
		}
#ifndef __VIVADO_SYNTH__
		cout << "Error: Unsupported offset in linebuffer_3x3: " << offset << endl;
#endif // __VIVADO_SYNTH__
		assert(false);
		return 0;

	}

	inline void push(const hw_uint<32>  value) {
#ifdef __VIVADO_SYNTH__
#pragma HLS dependence array inter false
#endif //__VIVADO_SYNTH__
		f16.push(f14.back());
		f14.push(f12.back());
		f12.push(f11.back());
		f11.push(f10.back());
		f10.push(f8.back());
		f8.push(f6.back());
		f6.push(f5.back());
		f5.push(f4.back());
		f4.push(f2.back());
		f2.push(f0.back());
		f0.push(value);
	}

};



inline void write0_write(InputStream<hw_uint<32>  >& write0, write0_cache& write0_delay) {
	hw_uint<32>  write0_value = write0.read(); write0_delay.push(write0_value);
}

inline hw_uint<32>  read_0_0_select(write0_cache& write0_delay
, int i, int j) {
	hw_uint<32>  value_write0 = write0_delay.peek_130();
	return value_write0;
}

inline hw_uint<32>  read_0_1_select(write0_cache& write0_delay
, int i, int j) {
	hw_uint<32>  value_write0 = write0_delay.peek_129();
	return value_write0;
}

inline hw_uint<32>  read_0_2_select(write0_cache& write0_delay
, int i, int j) {
	hw_uint<32>  value_write0 = write0_delay.peek_128();
	return value_write0;
}

inline hw_uint<32>  read_1_0_select(write0_cache& write0_delay
, int i, int j) {
	hw_uint<32>  value_write0 = write0_delay.peek_66();
	return value_write0;
}

inline hw_uint<32>  read_1_1_select(write0_cache& write0_delay
, int i, int j) {
	hw_uint<32>  value_write0 = write0_delay.peek_65();
	return value_write0;
}

inline hw_uint<32>  read_1_2_select(write0_cache& write0_delay
, int i, int j) {
	hw_uint<32>  value_write0 = write0_delay.peek_64();
	return value_write0;
}

inline hw_uint<32>  read_2_0_select(write0_cache& write0_delay
, int i, int j) {
	hw_uint<32>  value_write0 = write0_delay.peek_2();
	return value_write0;
}

inline hw_uint<32>  read_2_1_select(write0_cache& write0_delay
, int i, int j) {
	hw_uint<32>  value_write0 = write0_delay.peek_1();
	return value_write0;
}

inline hw_uint<32>  read_2_2_select(write0_cache& write0_delay
, int i, int j) {
	hw_uint<32>  value_write0 = write0_delay.peek_0();
	return value_write0;
}

// Bundles...
// read_0_0
//	read_0_0
inline hw_uint<32> linebuffer_3x3_read_0_0_bundle_read(write0_cache& write0_delay, int i, int j) {
	hw_uint<32> result;
	hw_uint<32>  read_0_0_res = read_0_0_select(write0_delay, i, j);
	set_at<0, 32>(result, read_0_0_res);
	return result;
}

// read_0_1
//	read_0_1
inline hw_uint<32> linebuffer_3x3_read_0_1_bundle_read(write0_cache& write0_delay, int i, int j) {
	hw_uint<32> result;
	hw_uint<32>  read_0_1_res = read_0_1_select(write0_delay, i, j);
	set_at<0, 32>(result, read_0_1_res);
	return result;
}

// read_0_2
//	read_0_2
inline hw_uint<32> linebuffer_3x3_read_0_2_bundle_read(write0_cache& write0_delay, int i, int j) {
	hw_uint<32> result;
	hw_uint<32>  read_0_2_res = read_0_2_select(write0_delay, i, j);
	set_at<0, 32>(result, read_0_2_res);
	return result;
}

// read_1_0
//	read_1_0
inline hw_uint<32> linebuffer_3x3_read_1_0_bundle_read(write0_cache& write0_delay, int i, int j) {
	hw_uint<32> result;
	hw_uint<32>  read_1_0_res = read_1_0_select(write0_delay, i, j);
	set_at<0, 32>(result, read_1_0_res);
	return result;
}

// read_1_1
//	read_1_1
inline hw_uint<32> linebuffer_3x3_read_1_1_bundle_read(write0_cache& write0_delay, int i, int j) {
	hw_uint<32> result;
	hw_uint<32>  read_1_1_res = read_1_1_select(write0_delay, i, j);
	set_at<0, 32>(result, read_1_1_res);
	return result;
}

// read_1_2
//	read_1_2
inline hw_uint<32> linebuffer_3x3_read_1_2_bundle_read(write0_cache& write0_delay, int i, int j) {
	hw_uint<32> result;
	hw_uint<32>  read_1_2_res = read_1_2_select(write0_delay, i, j);
	set_at<0, 32>(result, read_1_2_res);
	return result;
}

// read_2_0
//	read_2_0
inline hw_uint<32> linebuffer_3x3_read_2_0_bundle_read(write0_cache& write0_delay, int i, int j) {
	hw_uint<32> result;
	hw_uint<32>  read_2_0_res = read_2_0_select(write0_delay, i, j);
	set_at<0, 32>(result, read_2_0_res);
	return result;
}

// read_2_1
//	read_2_1
inline hw_uint<32> linebuffer_3x3_read_2_1_bundle_read(write0_cache& write0_delay, int i, int j) {
	hw_uint<32> result;
	hw_uint<32>  read_2_1_res = read_2_1_select(write0_delay, i, j);
	set_at<0, 32>(result, read_2_1_res);
	return result;
}

// read_2_2
//	read_2_2
inline hw_uint<32> linebuffer_3x3_read_2_2_bundle_read(write0_cache& write0_delay, int i, int j) {
	hw_uint<32> result;
	hw_uint<32>  read_2_2_res = read_2_2_select(write0_delay, i, j);
	set_at<0, 32>(result, read_2_2_res);
	return result;
}

// write0
//	write0
inline void linebuffer_3x3_write0_bundle_write(InputStream<hw_uint<32>  >& write0, write0_cache& write0_delay) {
	write0_write(write0, write0_delay);
}



void linebuffer_3x3(OutputStream<hw_uint<32> >& read_0_0, OutputStream<hw_uint<32> >& read_0_1, OutputStream<hw_uint<32> >& read_0_2, OutputStream<hw_uint<32> >& read_1_0, OutputStream<hw_uint<32> >& read_1_1, OutputStream<hw_uint<32> >& read_1_2, OutputStream<hw_uint<32> >& read_2_0, OutputStream<hw_uint<32> >& read_2_1, OutputStream<hw_uint<32> >& read_2_2, InputStream<hw_uint<32> >& write0) {
	write0_cache write0_delay;

	for (int c0 = 0; c0 <= 63; c0 += 1)
	  for (int c1 = 0; c1 <= 63; c1 += 1) {

#pragma HLS pipeline
#pragma HLS dependence variable=write0_delay.f5.vals inter false
#pragma HLS dependence variable=write0_delay.f11.vals inter false

	    write0_write(write0, write0_delay);
	    if (c0 >= 2 && c1 >= 2) {
<<<<<<< HEAD
<<<<<<< HEAD
        int res = 0;
        res += (write0_delay.peek_130());
        res += (write0_delay.peek_129());
        res += (write0_delay.peek_128());

        res += (write0_delay.peek_66());
        res += (write0_delay.peek_65());
        res += (write0_delay.peek_64());

        res += (write0_delay.peek_2());
        res += (write0_delay.peek_1());
        res += (write0_delay.peek_0());

        read_0_0.write(res);

        //read_0_1.write(write0_delay.peek_1());
        //read_0_2.write(write0_delay.peek_128());
				
        //read_1_0.write(write0_delay.peek_0());
				//read_1_1.write(write0_delay.peek_66());
        //read_1_2.write(write0_delay.peek_130());
				
				//read_2_0.write(write0_delay.peek_65());
        //read_2_1.write(write0_delay.peek_2());
        //read_2_2.write(write0_delay.peek_64());
        //read_0_0.write(write0_delay.peek_129());
				//read_0_1.write(write0_delay.peek_1());
        //read_0_2.write(write0_delay.peek_128());
				
        //read_1_0.write(write0_delay.peek_0());
				//read_1_1.write(write0_delay.peek_66());
        //read_1_2.write(write0_delay.peek_130());
				
				//read_2_0.write(write0_delay.peek_65());
        //read_2_1.write(write0_delay.peek_2());
        //read_2_2.write(write0_delay.peek_64());
	      

				//read_1_0.write(read_1_0_select(write0_delay, c0 - 2, c1 - 2));
				//read_0_1.write(read_0_1_select(write0_delay, c0 - 2, c1 - 2));
				//read_2_1.write(read_2_1_select(write0_delay, c0 - 2, c1 - 2));
				//read_2_2.write(read_2_2_select(write0_delay, c0 - 2, c1 - 2));
				//read_2_0.write(read_2_0_select(write0_delay, c0 - 2, c1 - 2));
				//read_1_1.write(read_1_1_select(write0_delay, c0 - 2, c1 - 2));
				//read_0_2.write(read_0_2_select(write0_delay, c0 - 2, c1 - 2));
				//read_0_0.write(read_0_0_select(write0_delay, c0 - 2, c1 - 2));
				//read_1_2.write(read_1_2_select(write0_delay, c0 - 2, c1 - 2));
=======
	      read_1_0.write(linebuffer_3x3_read_1_0_bundle_action(write0_delay, c0 - 2, c1 - 2));
	      read_0_1.write(linebuffer_3x3_read_0_1_bundle_action(write0_delay, c0 - 2, c1 - 2));
	      read_2_1.write(linebuffer_3x3_read_2_1_bundle_action(write0_delay, c0 - 2, c1 - 2));
	      read_2_2.write(linebuffer_3x3_read_2_2_bundle_action(write0_delay, c0 - 2, c1 - 2));
	      read_2_0.write(linebuffer_3x3_read_2_0_bundle_action(write0_delay, c0 - 2, c1 - 2));
	      read_1_1.write(linebuffer_3x3_read_1_1_bundle_action(write0_delay, c0 - 2, c1 - 2));
	      read_0_2.write(linebuffer_3x3_read_0_2_bundle_action(write0_delay, c0 - 2, c1 - 2));
	      read_0_0.write(linebuffer_3x3_read_0_0_bundle_action(write0_delay, c0 - 2, c1 - 2));
	      read_1_2.write(linebuffer_3x3_read_1_2_bundle_action(write0_delay, c0 - 2, c1 - 2));
>>>>>>> 862ffcf7f2387fff4330a6d80bd4d025ee0c2bd8
=======
	      read_1_0.write(linebuffer_3x3_read_1_0_bundle_read(write0_delay, c0 - 2, c1 - 2));
	      read_0_1.write(linebuffer_3x3_read_0_1_bundle_read(write0_delay, c0 - 2, c1 - 2));
	      read_2_1.write(linebuffer_3x3_read_2_1_bundle_read(write0_delay, c0 - 2, c1 - 2));
	      read_2_2.write(linebuffer_3x3_read_2_2_bundle_read(write0_delay, c0 - 2, c1 - 2));
	      read_2_0.write(linebuffer_3x3_read_2_0_bundle_read(write0_delay, c0 - 2, c1 - 2));
	      read_1_1.write(linebuffer_3x3_read_1_1_bundle_read(write0_delay, c0 - 2, c1 - 2));
	      read_0_2.write(linebuffer_3x3_read_0_2_bundle_read(write0_delay, c0 - 2, c1 - 2));
	      read_0_0.write(linebuffer_3x3_read_0_0_bundle_read(write0_delay, c0 - 2, c1 - 2));
	      read_1_2.write(linebuffer_3x3_read_1_2_bundle_read(write0_delay, c0 - 2, c1 - 2));
>>>>>>> origin/master
	    }
	  }
	
}
