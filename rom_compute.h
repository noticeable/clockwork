#pragma once
#include "hw_classes.h"
#include "conv_3x3.h"


//store is: hw_input_global_wrapper.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y) = hw_input.stencil(hw_input_global_wrapper_s0_x, hw_input_global_wrapper_s0_y)
hw_uint<16> hcompute_hw_input_global_wrapper_stencil(hw_uint<16>& hw_input_stencil) {
  int16_t _hw_input_stencil_1 = (int16_t) hw_input_stencil.extract<0, 15>();

  return _hw_input_stencil_1;
}

//store is: hw_output.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi) = curvea0[int32(max(min(hw_input_global_wrapper.stencil(hw_output_s0_x_xi, hw_output_s0_y_yi), (int16)1023), (int16)0))]
hw_uint<8> hcompute_hw_output_stencil(hw_uint<16>& hw_input_global_wrapper_stencil) {
  int16_t _hw_input_global_wrapper_stencil_1 = (int16_t) hw_input_global_wrapper_stencil.extract<0, 15>();

  uint8_t _curvea0[256];
  // produce curvea0
  uint8_t _513 = (uint8_t)(0);
  _curvea0[0] = _513;
  uint8_t _514 = (uint8_t)(0);
  _curvea0[1] = _514;
  uint8_t _515 = (uint8_t)(0);
  _curvea0[2] = _515;
  uint8_t _516 = (uint8_t)(0);
  _curvea0[3] = _516;
  uint8_t _517 = (uint8_t)(0);
  _curvea0[4] = _517;
  uint8_t _518 = (uint8_t)(1);
  _curvea0[5] = _518;
  uint8_t _519 = (uint8_t)(1);
  _curvea0[6] = _519;
  uint8_t _520 = (uint8_t)(1);
  _curvea0[7] = _520;
  uint8_t _521 = (uint8_t)(1);
  _curvea0[8] = _521;
  uint8_t _522 = (uint8_t)(2);
  _curvea0[9] = _522;
  uint8_t _523 = (uint8_t)(2);
  _curvea0[10] = _523;
  uint8_t _524 = (uint8_t)(2);
  _curvea0[11] = _524;
  uint8_t _525 = (uint8_t)(2);
  _curvea0[12] = _525;
  uint8_t _526 = (uint8_t)(3);
  _curvea0[13] = _526;
  uint8_t _527 = (uint8_t)(3);
  _curvea0[14] = _527;
  uint8_t _528 = (uint8_t)(3);
  _curvea0[15] = _528;
  uint8_t _529 = (uint8_t)(3);
  _curvea0[16] = _529;
  uint8_t _530 = (uint8_t)(4);
  _curvea0[17] = _530;
  uint8_t _531 = (uint8_t)(4);
  _curvea0[18] = _531;
  uint8_t _532 = (uint8_t)(4);
  _curvea0[19] = _532;
  uint8_t _533 = (uint8_t)(4);
  _curvea0[20] = _533;
  uint8_t _534 = (uint8_t)(5);
  _curvea0[21] = _534;
  uint8_t _535 = (uint8_t)(5);
  _curvea0[22] = _535;
  uint8_t _536 = (uint8_t)(5);
  _curvea0[23] = _536;
  uint8_t _537 = (uint8_t)(5);
  _curvea0[24] = _537;
  uint8_t _538 = (uint8_t)(6);
  _curvea0[25] = _538;
  uint8_t _539 = (uint8_t)(6);
  _curvea0[26] = _539;
  uint8_t _540 = (uint8_t)(6);
  _curvea0[27] = _540;
  uint8_t _541 = (uint8_t)(6);
  _curvea0[28] = _541;
  uint8_t _542 = (uint8_t)(7);
  _curvea0[29] = _542;
  uint8_t _543 = (uint8_t)(7);
  _curvea0[30] = _543;
  uint8_t _544 = (uint8_t)(7);
  _curvea0[31] = _544;
  uint8_t _545 = (uint8_t)(7);
  _curvea0[32] = _545;
  uint8_t _546 = (uint8_t)(8);
  _curvea0[33] = _546;
  uint8_t _547 = (uint8_t)(8);
  _curvea0[34] = _547;
  uint8_t _548 = (uint8_t)(8);
  _curvea0[35] = _548;
  uint8_t _549 = (uint8_t)(8);
  _curvea0[36] = _549;
  uint8_t _550 = (uint8_t)(9);
  _curvea0[37] = _550;
  uint8_t _551 = (uint8_t)(9);
  _curvea0[38] = _551;
  uint8_t _552 = (uint8_t)(9);
  _curvea0[39] = _552;
  uint8_t _553 = (uint8_t)(9);
  _curvea0[40] = _553;
  uint8_t _554 = (uint8_t)(10);
  _curvea0[41] = _554;
  uint8_t _555 = (uint8_t)(10);
  _curvea0[42] = _555;
  uint8_t _556 = (uint8_t)(10);
  _curvea0[43] = _556;
  uint8_t _557 = (uint8_t)(10);
  _curvea0[44] = _557;
  uint8_t _558 = (uint8_t)(11);
  _curvea0[45] = _558;
  uint8_t _559 = (uint8_t)(11);
  _curvea0[46] = _559;
  uint8_t _560 = (uint8_t)(11);
  _curvea0[47] = _560;
  uint8_t _561 = (uint8_t)(11);
  _curvea0[48] = _561;
  uint8_t _562 = (uint8_t)(12);
  _curvea0[49] = _562;
  uint8_t _563 = (uint8_t)(12);
  _curvea0[50] = _563;
  uint8_t _564 = (uint8_t)(12);
  _curvea0[51] = _564;
  uint8_t _565 = (uint8_t)(12);
  _curvea0[52] = _565;
  uint8_t _566 = (uint8_t)(13);
  _curvea0[53] = _566;
  uint8_t _567 = (uint8_t)(13);
  _curvea0[54] = _567;
  uint8_t _568 = (uint8_t)(13);
  _curvea0[55] = _568;
  uint8_t _569 = (uint8_t)(13);
  _curvea0[56] = _569;
  uint8_t _570 = (uint8_t)(14);
  _curvea0[57] = _570;
  uint8_t _571 = (uint8_t)(14);
  _curvea0[58] = _571;
  uint8_t _572 = (uint8_t)(14);
  _curvea0[59] = _572;
  uint8_t _573 = (uint8_t)(14);
  _curvea0[60] = _573;
  uint8_t _574 = (uint8_t)(15);
  _curvea0[61] = _574;
  uint8_t _575 = (uint8_t)(15);
  _curvea0[62] = _575;
  uint8_t _576 = (uint8_t)(15);
  _curvea0[63] = _576;
  uint8_t _577 = (uint8_t)(15);
  _curvea0[64] = _577;
  uint8_t _578 = (uint8_t)(16);
  _curvea0[65] = _578;
  uint8_t _579 = (uint8_t)(16);
  _curvea0[66] = _579;
  uint8_t _580 = (uint8_t)(16);
  _curvea0[67] = _580;
  uint8_t _581 = (uint8_t)(16);
  _curvea0[68] = _581;
  uint8_t _582 = (uint8_t)(17);
  _curvea0[69] = _582;
  uint8_t _583 = (uint8_t)(17);
  _curvea0[70] = _583;
  uint8_t _584 = (uint8_t)(17);
  _curvea0[71] = _584;
  uint8_t _585 = (uint8_t)(17);
  _curvea0[72] = _585;
  uint8_t _586 = (uint8_t)(18);
  _curvea0[73] = _586;
  uint8_t _587 = (uint8_t)(18);
  _curvea0[74] = _587;
  uint8_t _588 = (uint8_t)(18);
  _curvea0[75] = _588;
  uint8_t _589 = (uint8_t)(18);
  _curvea0[76] = _589;
  uint8_t _590 = (uint8_t)(19);
  _curvea0[77] = _590;
  uint8_t _591 = (uint8_t)(19);
  _curvea0[78] = _591;
  uint8_t _592 = (uint8_t)(19);
  _curvea0[79] = _592;
  uint8_t _593 = (uint8_t)(19);
  _curvea0[80] = _593;
  uint8_t _594 = (uint8_t)(20);
  _curvea0[81] = _594;
  uint8_t _595 = (uint8_t)(20);
  _curvea0[82] = _595;
  uint8_t _596 = (uint8_t)(20);
  _curvea0[83] = _596;
  uint8_t _597 = (uint8_t)(20);
  _curvea0[84] = _597;
  uint8_t _598 = (uint8_t)(21);
  _curvea0[85] = _598;
  uint8_t _599 = (uint8_t)(21);
  _curvea0[86] = _599;
  uint8_t _600 = (uint8_t)(21);
  _curvea0[87] = _600;
  uint8_t _601 = (uint8_t)(21);
  _curvea0[88] = _601;
  uint8_t _602 = (uint8_t)(22);
  _curvea0[89] = _602;
  uint8_t _603 = (uint8_t)(22);
  _curvea0[90] = _603;
  uint8_t _604 = (uint8_t)(22);
  _curvea0[91] = _604;
  uint8_t _605 = (uint8_t)(22);
  _curvea0[92] = _605;
  uint8_t _606 = (uint8_t)(23);
  _curvea0[93] = _606;
  uint8_t _607 = (uint8_t)(23);
  _curvea0[94] = _607;
  uint8_t _608 = (uint8_t)(23);
  _curvea0[95] = _608;
  uint8_t _609 = (uint8_t)(23);
  _curvea0[96] = _609;
  uint8_t _610 = (uint8_t)(24);
  _curvea0[97] = _610;
  uint8_t _611 = (uint8_t)(24);
  _curvea0[98] = _611;
  uint8_t _612 = (uint8_t)(24);
  _curvea0[99] = _612;
  uint8_t _613 = (uint8_t)(24);
  _curvea0[100] = _613;
  uint8_t _614 = (uint8_t)(25);
  _curvea0[101] = _614;
  uint8_t _615 = (uint8_t)(25);
  _curvea0[102] = _615;
  uint8_t _616 = (uint8_t)(25);
  _curvea0[103] = _616;
  uint8_t _617 = (uint8_t)(25);
  _curvea0[104] = _617;
  uint8_t _618 = (uint8_t)(26);
  _curvea0[105] = _618;
  uint8_t _619 = (uint8_t)(26);
  _curvea0[106] = _619;
  uint8_t _620 = (uint8_t)(26);
  _curvea0[107] = _620;
  uint8_t _621 = (uint8_t)(26);
  _curvea0[108] = _621;
  uint8_t _622 = (uint8_t)(27);
  _curvea0[109] = _622;
  uint8_t _623 = (uint8_t)(27);
  _curvea0[110] = _623;
  uint8_t _624 = (uint8_t)(27);
  _curvea0[111] = _624;
  uint8_t _625 = (uint8_t)(27);
  _curvea0[112] = _625;
  uint8_t _626 = (uint8_t)(28);
  _curvea0[113] = _626;
  uint8_t _627 = (uint8_t)(28);
  _curvea0[114] = _627;
  uint8_t _628 = (uint8_t)(28);
  _curvea0[115] = _628;
  uint8_t _629 = (uint8_t)(28);
  _curvea0[116] = _629;
  uint8_t _630 = (uint8_t)(29);
  _curvea0[117] = _630;
  uint8_t _631 = (uint8_t)(29);
  _curvea0[118] = _631;
  uint8_t _632 = (uint8_t)(29);
  _curvea0[119] = _632;
  uint8_t _633 = (uint8_t)(29);
  _curvea0[120] = _633;
  uint8_t _634 = (uint8_t)(30);
  _curvea0[121] = _634;
  uint8_t _635 = (uint8_t)(30);
  _curvea0[122] = _635;
  uint8_t _636 = (uint8_t)(30);
  _curvea0[123] = _636;
  uint8_t _637 = (uint8_t)(30);
  _curvea0[124] = _637;
  uint8_t _638 = (uint8_t)(31);
  _curvea0[125] = _638;
  uint8_t _639 = (uint8_t)(31);
  _curvea0[126] = _639;
  uint8_t _640 = (uint8_t)(31);
  _curvea0[127] = _640;
  uint8_t _641 = (uint8_t)(31);
  _curvea0[128] = _641;
  uint8_t _642 = (uint8_t)(32);
  _curvea0[129] = _642;
  uint8_t _643 = (uint8_t)(32);
  _curvea0[130] = _643;
  uint8_t _644 = (uint8_t)(32);
  _curvea0[131] = _644;
  uint8_t _645 = (uint8_t)(32);
  _curvea0[132] = _645;
  uint8_t _646 = (uint8_t)(33);
  _curvea0[133] = _646;
  uint8_t _647 = (uint8_t)(33);
  _curvea0[134] = _647;
  uint8_t _648 = (uint8_t)(33);
  _curvea0[135] = _648;
  uint8_t _649 = (uint8_t)(33);
  _curvea0[136] = _649;
  uint8_t _650 = (uint8_t)(34);
  _curvea0[137] = _650;
  uint8_t _651 = (uint8_t)(34);
  _curvea0[138] = _651;
  uint8_t _652 = (uint8_t)(34);
  _curvea0[139] = _652;
  uint8_t _653 = (uint8_t)(34);
  _curvea0[140] = _653;
  uint8_t _654 = (uint8_t)(35);
  _curvea0[141] = _654;
  uint8_t _655 = (uint8_t)(35);
  _curvea0[142] = _655;
  uint8_t _656 = (uint8_t)(35);
  _curvea0[143] = _656;
  uint8_t _657 = (uint8_t)(35);
  _curvea0[144] = _657;
  uint8_t _658 = (uint8_t)(36);
  _curvea0[145] = _658;
  uint8_t _659 = (uint8_t)(36);
  _curvea0[146] = _659;
  uint8_t _660 = (uint8_t)(36);
  _curvea0[147] = _660;
  uint8_t _661 = (uint8_t)(36);
  _curvea0[148] = _661;
  uint8_t _662 = (uint8_t)(37);
  _curvea0[149] = _662;
  uint8_t _663 = (uint8_t)(37);
  _curvea0[150] = _663;
  uint8_t _664 = (uint8_t)(37);
  _curvea0[151] = _664;
  uint8_t _665 = (uint8_t)(37);
  _curvea0[152] = _665;
  uint8_t _666 = (uint8_t)(38);
  _curvea0[153] = _666;
  uint8_t _667 = (uint8_t)(38);
  _curvea0[154] = _667;
  uint8_t _668 = (uint8_t)(38);
  _curvea0[155] = _668;
  uint8_t _669 = (uint8_t)(38);
  _curvea0[156] = _669;
  uint8_t _670 = (uint8_t)(39);
  _curvea0[157] = _670;
  uint8_t _671 = (uint8_t)(39);
  _curvea0[158] = _671;
  uint8_t _672 = (uint8_t)(39);
  _curvea0[159] = _672;
  uint8_t _673 = (uint8_t)(39);
  _curvea0[160] = _673;
  uint8_t _674 = (uint8_t)(40);
  _curvea0[161] = _674;
  uint8_t _675 = (uint8_t)(40);
  _curvea0[162] = _675;
  uint8_t _676 = (uint8_t)(40);
  _curvea0[163] = _676;
  uint8_t _677 = (uint8_t)(40);
  _curvea0[164] = _677;
  uint8_t _678 = (uint8_t)(41);
  _curvea0[165] = _678;
  uint8_t _679 = (uint8_t)(41);
  _curvea0[166] = _679;
  uint8_t _680 = (uint8_t)(41);
  _curvea0[167] = _680;
  uint8_t _681 = (uint8_t)(41);
  _curvea0[168] = _681;
  uint8_t _682 = (uint8_t)(42);
  _curvea0[169] = _682;
  uint8_t _683 = (uint8_t)(42);
  _curvea0[170] = _683;
  uint8_t _684 = (uint8_t)(42);
  _curvea0[171] = _684;
  uint8_t _685 = (uint8_t)(42);
  _curvea0[172] = _685;
  uint8_t _686 = (uint8_t)(43);
  _curvea0[173] = _686;
  uint8_t _687 = (uint8_t)(43);
  _curvea0[174] = _687;
  uint8_t _688 = (uint8_t)(43);
  _curvea0[175] = _688;
  uint8_t _689 = (uint8_t)(43);
  _curvea0[176] = _689;
  uint8_t _690 = (uint8_t)(44);
  _curvea0[177] = _690;
  uint8_t _691 = (uint8_t)(44);
  _curvea0[178] = _691;
  uint8_t _692 = (uint8_t)(44);
  _curvea0[179] = _692;
  uint8_t _693 = (uint8_t)(44);
  _curvea0[180] = _693;
  uint8_t _694 = (uint8_t)(45);
  _curvea0[181] = _694;
  uint8_t _695 = (uint8_t)(45);
  _curvea0[182] = _695;
  uint8_t _696 = (uint8_t)(45);
  _curvea0[183] = _696;
  uint8_t _697 = (uint8_t)(45);
  _curvea0[184] = _697;
  uint8_t _698 = (uint8_t)(46);
  _curvea0[185] = _698;
  uint8_t _699 = (uint8_t)(46);
  _curvea0[186] = _699;
  uint8_t _700 = (uint8_t)(46);
  _curvea0[187] = _700;
  uint8_t _701 = (uint8_t)(46);
  _curvea0[188] = _701;
  uint8_t _702 = (uint8_t)(47);
  _curvea0[189] = _702;
  uint8_t _703 = (uint8_t)(47);
  _curvea0[190] = _703;
  uint8_t _704 = (uint8_t)(47);
  _curvea0[191] = _704;
  uint8_t _705 = (uint8_t)(47);
  _curvea0[192] = _705;
  uint8_t _706 = (uint8_t)(48);
  _curvea0[193] = _706;
  uint8_t _707 = (uint8_t)(48);
  _curvea0[194] = _707;
  uint8_t _708 = (uint8_t)(48);
  _curvea0[195] = _708;
  uint8_t _709 = (uint8_t)(48);
  _curvea0[196] = _709;
  uint8_t _710 = (uint8_t)(49);
  _curvea0[197] = _710;
  uint8_t _711 = (uint8_t)(49);
  _curvea0[198] = _711;
  uint8_t _712 = (uint8_t)(49);
  _curvea0[199] = _712;
  uint8_t _713 = (uint8_t)(49);
  _curvea0[200] = _713;
  uint8_t _714 = (uint8_t)(50);
  _curvea0[201] = _714;
  uint8_t _715 = (uint8_t)(50);
  _curvea0[202] = _715;
  uint8_t _716 = (uint8_t)(50);
  _curvea0[203] = _716;
  uint8_t _717 = (uint8_t)(50);
  _curvea0[204] = _717;
  uint8_t _718 = (uint8_t)(51);
  _curvea0[205] = _718;
  uint8_t _719 = (uint8_t)(51);
  _curvea0[206] = _719;
  uint8_t _720 = (uint8_t)(51);
  _curvea0[207] = _720;
  uint8_t _721 = (uint8_t)(51);
  _curvea0[208] = _721;
  uint8_t _722 = (uint8_t)(52);
  _curvea0[209] = _722;
  uint8_t _723 = (uint8_t)(52);
  _curvea0[210] = _723;
  uint8_t _724 = (uint8_t)(52);
  _curvea0[211] = _724;
  uint8_t _725 = (uint8_t)(52);
  _curvea0[212] = _725;
  uint8_t _726 = (uint8_t)(53);
  _curvea0[213] = _726;
  uint8_t _727 = (uint8_t)(53);
  _curvea0[214] = _727;
  uint8_t _728 = (uint8_t)(53);
  _curvea0[215] = _728;
  uint8_t _729 = (uint8_t)(53);
  _curvea0[216] = _729;
  uint8_t _730 = (uint8_t)(54);
  _curvea0[217] = _730;
  uint8_t _731 = (uint8_t)(54);
  _curvea0[218] = _731;
  uint8_t _732 = (uint8_t)(54);
  _curvea0[219] = _732;
  uint8_t _733 = (uint8_t)(54);
  _curvea0[220] = _733;
  uint8_t _734 = (uint8_t)(55);
  _curvea0[221] = _734;
  uint8_t _735 = (uint8_t)(55);
  _curvea0[222] = _735;
  uint8_t _736 = (uint8_t)(55);
  _curvea0[223] = _736;
  uint8_t _737 = (uint8_t)(55);
  _curvea0[224] = _737;
  uint8_t _738 = (uint8_t)(56);
  _curvea0[225] = _738;
  uint8_t _739 = (uint8_t)(56);
  _curvea0[226] = _739;
  uint8_t _740 = (uint8_t)(56);
  _curvea0[227] = _740;
  uint8_t _741 = (uint8_t)(56);
  _curvea0[228] = _741;
  uint8_t _742 = (uint8_t)(57);
  _curvea0[229] = _742;
  uint8_t _743 = (uint8_t)(57);
  _curvea0[230] = _743;
  uint8_t _744 = (uint8_t)(57);
  _curvea0[231] = _744;
  uint8_t _745 = (uint8_t)(57);
  _curvea0[232] = _745;
  uint8_t _746 = (uint8_t)(58);
  _curvea0[233] = _746;
  uint8_t _747 = (uint8_t)(58);
  _curvea0[234] = _747;
  uint8_t _748 = (uint8_t)(58);
  _curvea0[235] = _748;
  uint8_t _749 = (uint8_t)(58);
  _curvea0[236] = _749;
  uint8_t _750 = (uint8_t)(59);
  _curvea0[237] = _750;
  uint8_t _751 = (uint8_t)(59);
  _curvea0[238] = _751;
  uint8_t _752 = (uint8_t)(59);
  _curvea0[239] = _752;
  uint8_t _753 = (uint8_t)(59);
  _curvea0[240] = _753;
  uint8_t _754 = (uint8_t)(60);
  _curvea0[241] = _754;
  uint8_t _755 = (uint8_t)(60);
  _curvea0[242] = _755;
  uint8_t _756 = (uint8_t)(60);
  _curvea0[243] = _756;
  uint8_t _757 = (uint8_t)(60);
  _curvea0[244] = _757;
  uint8_t _758 = (uint8_t)(61);
  _curvea0[245] = _758;
  uint8_t _759 = (uint8_t)(61);
  _curvea0[246] = _759;
  uint8_t _760 = (uint8_t)(61);
  _curvea0[247] = _760;
  uint8_t _761 = (uint8_t)(61);
  _curvea0[248] = _761;
  uint8_t _762 = (uint8_t)(62);
  _curvea0[249] = _762;
  uint8_t _763 = (uint8_t)(62);
  _curvea0[250] = _763;
  uint8_t _764 = (uint8_t)(62);
  _curvea0[251] = _764;
  uint8_t _765 = (uint8_t)(62);
  _curvea0[252] = _765;
  uint8_t _766 = (uint8_t)(63);
  _curvea0[253] = _766;
  uint8_t _767 = (uint8_t)(63);
  _curvea0[254] = _767;
  uint8_t _768 = (uint8_t)(63);
  _curvea0[255] = _768;

  int16_t _769 = (int16_t)(1023);
  int16_t _770 = min(_hw_input_global_wrapper_stencil_1, _769);
  int16_t _771 = (int16_t)(0);
  int16_t _772 = max(_770, _771);
  int32_t _773 = (int32_t)(_772);
  uint8_t _774 = ((const uint8_t *)_curvea0)[_773];
  return _774;
}

