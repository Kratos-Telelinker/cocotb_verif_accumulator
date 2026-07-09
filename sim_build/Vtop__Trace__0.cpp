// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_A));
    bufp->chgBit(oldp+2,(vlSelfRef.valid_in_A));
    bufp->chgCData(oldp+3,(vlSelfRef.a_A),8);
    bufp->chgCData(oldp+4,(vlSelfRef.b_A),8);
    bufp->chgSData(oldp+5,(vlSelfRef.sum_async_A),9);
    bufp->chgSData(oldp+6,(vlSelfRef.sum_sync_A),9);
    bufp->chgBit(oldp+7,(vlSelfRef.rst_B));
    bufp->chgBit(oldp+8,(vlSelfRef.valid_in_B));
    bufp->chgCData(oldp+9,(vlSelfRef.a_B),8);
    bufp->chgCData(oldp+10,(vlSelfRef.b_B),8);
    bufp->chgSData(oldp+11,(vlSelfRef.sum_async_B),9);
    bufp->chgSData(oldp+12,(vlSelfRef.sum_sync_B),9);
    bufp->chgBit(oldp+13,(vlSelfRef.dut_wrapper__DOT__clk));
    bufp->chgBit(oldp+14,(vlSelfRef.dut_wrapper__DOT__rst_A));
    bufp->chgBit(oldp+15,(vlSelfRef.dut_wrapper__DOT__valid_in_A));
    bufp->chgCData(oldp+16,(vlSelfRef.dut_wrapper__DOT__a_A),8);
    bufp->chgCData(oldp+17,(vlSelfRef.dut_wrapper__DOT__b_A),8);
    bufp->chgSData(oldp+18,(vlSelfRef.dut_wrapper__DOT__sum_async_A),9);
    bufp->chgSData(oldp+19,(vlSelfRef.dut_wrapper__DOT__sum_sync_A),9);
    bufp->chgBit(oldp+20,(vlSelfRef.dut_wrapper__DOT__rst_B));
    bufp->chgBit(oldp+21,(vlSelfRef.dut_wrapper__DOT__valid_in_B));
    bufp->chgCData(oldp+22,(vlSelfRef.dut_wrapper__DOT__a_B),8);
    bufp->chgCData(oldp+23,(vlSelfRef.dut_wrapper__DOT__b_B),8);
    bufp->chgSData(oldp+24,(vlSelfRef.dut_wrapper__DOT__sum_async_B),9);
    bufp->chgSData(oldp+25,(vlSelfRef.dut_wrapper__DOT__sum_sync_B),9);
    bufp->chgBit(oldp+26,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__clk));
    bufp->chgBit(oldp+27,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_A));
    bufp->chgBit(oldp+28,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_A));
    bufp->chgCData(oldp+29,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_A),8);
    bufp->chgCData(oldp+30,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_A),8);
    bufp->chgSData(oldp+31,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_A),9);
    bufp->chgSData(oldp+32,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A),9);
    bufp->chgBit(oldp+33,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_B));
    bufp->chgBit(oldp+34,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_B));
    bufp->chgCData(oldp+35,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_B),8);
    bufp->chgCData(oldp+36,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_B),8);
    bufp->chgSData(oldp+37,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_B),9);
    bufp->chgSData(oldp+38,(vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B),9);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
