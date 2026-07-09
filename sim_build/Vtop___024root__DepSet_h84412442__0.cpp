// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_A))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 202, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_A);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_A 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A;
    }
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_B))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 274, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_B);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_B 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B;
    }
    vlSelfRef.dut_wrapper__DOT__sum_sync_A = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A;
    vlSelfRef.dut_wrapper__DOT__sum_sync_B = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B;
    vlSelfRef.dut_wrapper__DOT__clk = vlSelfRef.clk;
    vlSelfRef.dut_wrapper__DOT__rst_A = vlSelfRef.rst_A;
    vlSelfRef.dut_wrapper__DOT__valid_in_A = vlSelfRef.valid_in_A;
    vlSelfRef.dut_wrapper__DOT__rst_B = vlSelfRef.rst_B;
    vlSelfRef.dut_wrapper__DOT__valid_in_B = vlSelfRef.valid_in_B;
    vlSelfRef.dut_wrapper__DOT__a_A = vlSelfRef.a_A;
    vlSelfRef.dut_wrapper__DOT__b_A = vlSelfRef.b_A;
    vlSelfRef.dut_wrapper__DOT__a_B = vlSelfRef.a_B;
    vlSelfRef.dut_wrapper__DOT__b_B = vlSelfRef.b_B;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__sum_sync_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_A))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 56, vlSelfRef.dut_wrapper__DOT__sum_sync_A, vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_A);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_A 
            = vlSelfRef.dut_wrapper__DOT__sum_sync_A;
    }
    vlSelfRef.sum_sync_A = vlSelfRef.dut_wrapper__DOT__sum_sync_A;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__sum_sync_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_B))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 128, vlSelfRef.dut_wrapper__DOT__sum_sync_B, vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_B);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_B 
            = vlSelfRef.dut_wrapper__DOT__sum_sync_B;
    }
    vlSelfRef.sum_sync_B = vlSelfRef.dut_wrapper__DOT__sum_sync_B;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__clk) ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 0, vlSelfRef.dut_wrapper__DOT__clk, vlSelfRef.dut_wrapper__DOT____Vtogcov__clk);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__clk 
            = vlSelfRef.dut_wrapper__DOT__clk;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__clk 
        = vlSelfRef.dut_wrapper__DOT__clk;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__rst_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__rst_A))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 2, vlSelfRef.dut_wrapper__DOT__rst_A, vlSelfRef.dut_wrapper__DOT____Vtogcov__rst_A);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__rst_A 
            = vlSelfRef.dut_wrapper__DOT__rst_A;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_A 
        = vlSelfRef.dut_wrapper__DOT__rst_A;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__valid_in_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__valid_in_A))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4, vlSelfRef.dut_wrapper__DOT__valid_in_A, vlSelfRef.dut_wrapper__DOT____Vtogcov__valid_in_A);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__valid_in_A 
            = vlSelfRef.dut_wrapper__DOT__valid_in_A;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_A 
        = vlSelfRef.dut_wrapper__DOT__valid_in_A;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__rst_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__rst_B))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 74, vlSelfRef.dut_wrapper__DOT__rst_B, vlSelfRef.dut_wrapper__DOT____Vtogcov__rst_B);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__rst_B 
            = vlSelfRef.dut_wrapper__DOT__rst_B;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_B 
        = vlSelfRef.dut_wrapper__DOT__rst_B;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__valid_in_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__valid_in_B))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 76, vlSelfRef.dut_wrapper__DOT__valid_in_B, vlSelfRef.dut_wrapper__DOT____Vtogcov__valid_in_B);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__valid_in_B 
            = vlSelfRef.dut_wrapper__DOT__valid_in_B;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_B 
        = vlSelfRef.dut_wrapper__DOT__valid_in_B;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__a_A) ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__a_A))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 6, vlSelfRef.dut_wrapper__DOT__a_A, vlSelfRef.dut_wrapper__DOT____Vtogcov__a_A);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__a_A 
            = vlSelfRef.dut_wrapper__DOT__a_A;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_A 
        = vlSelfRef.dut_wrapper__DOT__a_A;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__b_A) ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__b_A))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 22, vlSelfRef.dut_wrapper__DOT__b_A, vlSelfRef.dut_wrapper__DOT____Vtogcov__b_A);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__b_A 
            = vlSelfRef.dut_wrapper__DOT__b_A;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_A 
        = vlSelfRef.dut_wrapper__DOT__b_A;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__a_B) ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__a_B))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 78, vlSelfRef.dut_wrapper__DOT__a_B, vlSelfRef.dut_wrapper__DOT____Vtogcov__a_B);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__a_B 
            = vlSelfRef.dut_wrapper__DOT__a_B;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_B 
        = vlSelfRef.dut_wrapper__DOT__a_B;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__b_B) ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__b_B))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 94, vlSelfRef.dut_wrapper__DOT__b_B, vlSelfRef.dut_wrapper__DOT____Vtogcov__b_B);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__b_B 
            = vlSelfRef.dut_wrapper__DOT__b_B;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_B 
        = vlSelfRef.dut_wrapper__DOT__b_B;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__clk) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 146, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__clk, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__clk);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__clk 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__clk;
    }
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_A))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 148, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_A, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_A);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_A 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_A;
    }
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_A))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 150, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_A, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_A);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_A 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_A;
    }
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_B))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 220, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_B, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_B);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_B 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_B;
    }
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_B))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 222, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_B, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_B);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_B 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_B;
    }
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_A))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 152, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_A, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_A);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_A 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_A;
    }
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_A))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 168, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_A, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_A);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_A 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_A;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_A 
        = (0x1ffU & ((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_A) 
                     + (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_A)));
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_B))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 224, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_B, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_B);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_B 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_B;
    }
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_B))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 240, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_B, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_B);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_B 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_B;
    }
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_B 
        = (0x1ffU & ((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_B) 
                     + (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_B)));
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_A))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 184, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_A, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_A);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_A 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_A;
    }
    vlSelfRef.dut_wrapper__DOT__sum_async_A = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_A;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_B))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 256, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_B, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_B);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_B 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_B;
    }
    vlSelfRef.dut_wrapper__DOT__sum_async_B = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_B;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__sum_async_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_async_A))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 38, vlSelfRef.dut_wrapper__DOT__sum_async_A, vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_async_A);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_async_A 
            = vlSelfRef.dut_wrapper__DOT__sum_async_A;
    }
    vlSelfRef.sum_async_A = vlSelfRef.dut_wrapper__DOT__sum_async_A;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__sum_async_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_async_B))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 110, vlSelfRef.dut_wrapper__DOT__sum_async_B, vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_async_B);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_async_B 
            = vlSelfRef.dut_wrapper__DOT__sum_async_B;
    }
    vlSelfRef.sum_async_B = vlSelfRef.dut_wrapper__DOT__sum_async_B;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__clk__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_A;
    __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_A = 0;
    SData/*8:0*/ __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_B;
    __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_B = 0;
    // Body
    __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_A 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A;
    __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_B 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B;
    if (vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_A) {
        ++(vlSymsp->__Vcoverage[294]);
        __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_A = 0U;
    } else if (vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_A) {
        __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_A 
            = (0x1ffU & ((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A) 
                         + (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_A)));
        ++(vlSymsp->__Vcoverage[292]);
    } else {
        ++(vlSymsp->__Vcoverage[293]);
    }
    ++(vlSymsp->__Vcoverage[295]);
    if (vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_B) {
        ++(vlSymsp->__Vcoverage[298]);
        __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_B = 0U;
    } else if (vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_B) {
        __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_B 
            = (0x1ffU & ((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B) 
                         + (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_B)));
        ++(vlSymsp->__Vcoverage[296]);
    } else {
        ++(vlSymsp->__Vcoverage[297]);
    }
    ++(vlSymsp->__Vcoverage[299]);
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A 
        = __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_A;
    vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B 
        = __Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_B;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_A))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 202, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_A);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_A 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A;
    }
    vlSelfRef.dut_wrapper__DOT__sum_sync_A = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_B))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 274, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B, vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_B);
        vlSelfRef.dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_B 
            = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B;
    }
    vlSelfRef.dut_wrapper__DOT__sum_sync_B = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__sum_sync_A) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_A))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 56, vlSelfRef.dut_wrapper__DOT__sum_sync_A, vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_A);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_A 
            = vlSelfRef.dut_wrapper__DOT__sum_sync_A;
    }
    vlSelfRef.sum_sync_A = vlSelfRef.dut_wrapper__DOT__sum_sync_A;
    if (((IData)(vlSelfRef.dut_wrapper__DOT__sum_sync_B) 
         ^ (IData)(vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_B))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSymsp->__Vcoverage + 128, vlSelfRef.dut_wrapper__DOT__sum_sync_B, vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_B);
        vlSelfRef.dut_wrapper__DOT____Vtogcov__sum_sync_B 
            = vlSelfRef.dut_wrapper__DOT__sum_sync_B;
    }
    vlSelfRef.sum_sync_B = vlSelfRef.dut_wrapper__DOT__sum_sync_B;
}
