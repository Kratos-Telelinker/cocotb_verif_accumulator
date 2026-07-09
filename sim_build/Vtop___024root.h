// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT__clk;
        VL_IN8(clk,0,0);
        VL_IN8(rst_A,0,0);
        VL_IN8(valid_in_A,0,0);
        VL_IN8(a_A,7,0);
        VL_IN8(b_A,7,0);
        VL_IN8(rst_B,0,0);
        VL_IN8(valid_in_B,0,0);
        VL_IN8(a_B,7,0);
        VL_IN8(b_B,7,0);
        CData/*0:0*/ dut_wrapper__DOT__clk;
        CData/*0:0*/ dut_wrapper__DOT__rst_A;
        CData/*0:0*/ dut_wrapper__DOT__valid_in_A;
        CData/*7:0*/ dut_wrapper__DOT__a_A;
        CData/*7:0*/ dut_wrapper__DOT__b_A;
        CData/*0:0*/ dut_wrapper__DOT__rst_B;
        CData/*0:0*/ dut_wrapper__DOT__valid_in_B;
        CData/*7:0*/ dut_wrapper__DOT__a_B;
        CData/*7:0*/ dut_wrapper__DOT__b_B;
        CData/*0:0*/ dut_wrapper__DOT____Vtogcov__clk;
        CData/*0:0*/ dut_wrapper__DOT____Vtogcov__rst_A;
        CData/*0:0*/ dut_wrapper__DOT____Vtogcov__valid_in_A;
        CData/*7:0*/ dut_wrapper__DOT____Vtogcov__a_A;
        CData/*7:0*/ dut_wrapper__DOT____Vtogcov__b_A;
        CData/*0:0*/ dut_wrapper__DOT____Vtogcov__rst_B;
        CData/*0:0*/ dut_wrapper__DOT____Vtogcov__valid_in_B;
        CData/*7:0*/ dut_wrapper__DOT____Vtogcov__a_B;
        CData/*7:0*/ dut_wrapper__DOT____Vtogcov__b_B;
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT__rst_A;
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT__valid_in_A;
        CData/*7:0*/ dut_wrapper__DOT__u_top_level__DOT__a_A;
        CData/*7:0*/ dut_wrapper__DOT__u_top_level__DOT__b_A;
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT__rst_B;
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT__valid_in_B;
        CData/*7:0*/ dut_wrapper__DOT__u_top_level__DOT__a_B;
        CData/*7:0*/ dut_wrapper__DOT__u_top_level__DOT__b_B;
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__clk;
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_A;
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_A;
        CData/*7:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_A;
        CData/*7:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_A;
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_B;
        CData/*0:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_B;
        CData/*7:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_B;
        CData/*7:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_B;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(sum_async_A,8,0);
        VL_OUT16(sum_sync_A,8,0);
        VL_OUT16(sum_async_B,8,0);
        VL_OUT16(sum_sync_B,8,0);
        SData/*8:0*/ dut_wrapper__DOT__sum_async_A;
        SData/*8:0*/ dut_wrapper__DOT__sum_sync_A;
        SData/*8:0*/ dut_wrapper__DOT__sum_async_B;
        SData/*8:0*/ dut_wrapper__DOT__sum_sync_B;
        SData/*8:0*/ dut_wrapper__DOT____Vtogcov__sum_async_A;
        SData/*8:0*/ dut_wrapper__DOT____Vtogcov__sum_sync_A;
        SData/*8:0*/ dut_wrapper__DOT____Vtogcov__sum_async_B;
        SData/*8:0*/ dut_wrapper__DOT____Vtogcov__sum_sync_B;
        SData/*8:0*/ dut_wrapper__DOT__u_top_level__DOT__sum_async_A;
        SData/*8:0*/ dut_wrapper__DOT__u_top_level__DOT__sum_sync_A;
        SData/*8:0*/ dut_wrapper__DOT__u_top_level__DOT__sum_async_B;
    };
    struct {
        SData/*8:0*/ dut_wrapper__DOT__u_top_level__DOT__sum_sync_B;
        SData/*8:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_A;
        SData/*8:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_A;
        SData/*8:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_B;
        SData/*8:0*/ dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_B;
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
