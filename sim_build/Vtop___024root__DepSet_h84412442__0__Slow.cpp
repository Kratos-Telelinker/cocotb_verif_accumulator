// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"dump.vcd"});
    vlSymsp->_traceDumpOpen();
    ++(vlSymsp->__Vcoverage[300]);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtop___024root___configure_coverage(Vtop___024root* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___configure_coverage\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[0]), first, "rtl/dut_wrapper.sv", 2, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[2]), first, "rtl/dut_wrapper.sv", 5, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "rst_A");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[4]), first, "rtl/dut_wrapper.sv", 6, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "valid_in_A");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[6]), first, "rtl/dut_wrapper.sv", 7, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "a_A");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[22]), first, "rtl/dut_wrapper.sv", 8, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "b_A");
    vlSelf->__vlCoverToggleInsert(0, 8, 1, &(vlSymsp->__Vcoverage[38]), first, "rtl/dut_wrapper.sv", 11, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "sum_async_A");
    vlSelf->__vlCoverToggleInsert(0, 8, 1, &(vlSymsp->__Vcoverage[56]), first, "rtl/dut_wrapper.sv", 12, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "sum_sync_A");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[74]), first, "rtl/dut_wrapper.sv", 15, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "rst_B");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[76]), first, "rtl/dut_wrapper.sv", 16, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "valid_in_B");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[78]), first, "rtl/dut_wrapper.sv", 17, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "a_B");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[94]), first, "rtl/dut_wrapper.sv", 18, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "b_B");
    vlSelf->__vlCoverToggleInsert(0, 8, 1, &(vlSymsp->__Vcoverage[110]), first, "rtl/dut_wrapper.sv", 19, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "sum_async_B");
    vlSelf->__vlCoverToggleInsert(0, 8, 1, &(vlSymsp->__Vcoverage[128]), first, "rtl/dut_wrapper.sv", 20, 24, ".dut_wrapper", "v_toggle/dut_wrapper", "sum_sync_B");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[146]), first, "rtl/top_level.sv", 4, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[148]), first, "rtl/top_level.sv", 7, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "rst_A");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[150]), first, "rtl/top_level.sv", 8, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "valid_in_A");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[152]), first, "rtl/top_level.sv", 9, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "a_A");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[168]), first, "rtl/top_level.sv", 10, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "b_A");
    vlSelf->__vlCoverToggleInsert(0, 8, 1, &(vlSymsp->__Vcoverage[184]), first, "rtl/top_level.sv", 11, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "sum_async_A");
    vlSelf->__vlCoverToggleInsert(0, 8, 1, &(vlSymsp->__Vcoverage[202]), first, "rtl/top_level.sv", 12, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "sum_sync_A");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[220]), first, "rtl/top_level.sv", 15, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "rst_B");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[222]), first, "rtl/top_level.sv", 16, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "valid_in_B");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[224]), first, "rtl/top_level.sv", 17, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "a_B");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[240]), first, "rtl/top_level.sv", 18, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "b_B");
    vlSelf->__vlCoverToggleInsert(0, 8, 1, &(vlSymsp->__Vcoverage[256]), first, "rtl/top_level.sv", 19, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "sum_async_B");
    vlSelf->__vlCoverToggleInsert(0, 8, 1, &(vlSymsp->__Vcoverage[274]), first, "rtl/top_level.sv", 20, 24, ".dut_wrapper.u_top_level", "v_toggle/top_level", "sum_sync_B");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[292]), first, "rtl/top_level.sv", 27, 14, ".dut_wrapper.u_top_level", "v_branch/top_level", "if", "27-28");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[293]), first, "rtl/top_level.sv", 27, 15, ".dut_wrapper.u_top_level", "v_branch/top_level", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[294]), first, "rtl/top_level.sv", 25, 9, ".dut_wrapper.u_top_level", "v_line/top_level", "elsif", "25-26");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[295]), first, "rtl/top_level.sv", 24, 5, ".dut_wrapper.u_top_level", "v_line/top_level", "block", "24");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[296]), first, "rtl/top_level.sv", 37, 14, ".dut_wrapper.u_top_level", "v_branch/top_level", "if", "37-38");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[297]), first, "rtl/top_level.sv", 37, 15, ".dut_wrapper.u_top_level", "v_branch/top_level", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[298]), first, "rtl/top_level.sv", 35, 9, ".dut_wrapper.u_top_level", "v_line/top_level", "elsif", "35-36");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[299]), first, "rtl/top_level.sv", 34, 5, ".dut_wrapper.u_top_level", "v_line/top_level", "block", "34");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[300]), first, "rtl/top_level.sv", 49, 5, ".dut_wrapper.u_top_level", "v_line/top_level", "block", "49-51");
}
