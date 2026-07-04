// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024unit.h"

VL_ATTR_COLD void Vtop___024unit___ctor_var_reset(Vtop___024unit* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vtop___024unit___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__VmonitorNum = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9173067072191078724ull);
    vlSelf->__VmonitorOff = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9011783253012809090ull);
}

VL_ATTR_COLD void Vtop___024unit___configure_coverage(Vtop___024unit* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vtop___024unit___configure_coverage\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
}
