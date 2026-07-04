// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__clk__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__a_A__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_A;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__a_B__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__a_B;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__b_A__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_A;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__b_B__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__b_B;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__rst_A__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_A;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__rst_B__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__rst_B;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__sum_async_A__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_A;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__sum_async_B__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_async_B;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__sum_sync_A__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__sum_sync_B__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__valid_in_A__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_A;
    vlSelfRef.__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__valid_in_B__0 
        = vlSelfRef.dut_wrapper__DOT__u_top_level__DOT__valid_in_B;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/dut_wrapper.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge dut_wrapper.u_top_level.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @( dut_wrapper.u_top_level.a_A)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @( dut_wrapper.u_top_level.a_B)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @( dut_wrapper.u_top_level.b_A)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @( dut_wrapper.u_top_level.b_B)\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @( dut_wrapper.u_top_level.rst_A)\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @( dut_wrapper.u_top_level.rst_B)\n");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @( dut_wrapper.u_top_level.sum_async_A)\n");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @( dut_wrapper.u_top_level.sum_async_B)\n");
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @( dut_wrapper.u_top_level.sum_sync_A)\n");
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 10 is active: @( dut_wrapper.u_top_level.sum_sync_B)\n");
    }
    if ((0x800ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 11 is active: @( dut_wrapper.u_top_level.valid_in_A)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 12 is active: @( dut_wrapper.u_top_level.valid_in_B)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge dut_wrapper.u_top_level.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @( dut_wrapper.u_top_level.a_A)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @( dut_wrapper.u_top_level.a_B)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @( dut_wrapper.u_top_level.b_A)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @( dut_wrapper.u_top_level.b_B)\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @( dut_wrapper.u_top_level.rst_A)\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @( dut_wrapper.u_top_level.rst_B)\n");
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @( dut_wrapper.u_top_level.sum_async_A)\n");
    }
    if ((0x100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @( dut_wrapper.u_top_level.sum_async_B)\n");
    }
    if ((0x200ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @( dut_wrapper.u_top_level.sum_sync_A)\n");
    }
    if ((0x400ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 10 is active: @( dut_wrapper.u_top_level.sum_sync_B)\n");
    }
    if ((0x800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 11 is active: @( dut_wrapper.u_top_level.valid_in_A)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 12 is active: @( dut_wrapper.u_top_level.valid_in_B)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10752639957497588997ull);
    vlSelf->valid_in_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2673855842884607347ull);
    vlSelf->a_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14851257766545631230ull);
    vlSelf->b_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13238858314415394868ull);
    vlSelf->sum_async_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 14066892429191022224ull);
    vlSelf->sum_sync_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15107655126070582854ull);
    vlSelf->rst_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4038555007050280975ull);
    vlSelf->valid_in_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5388565095939058094ull);
    vlSelf->a_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 727034285805395899ull);
    vlSelf->b_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7252588311901177018ull);
    vlSelf->sum_async_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9008072548944398274ull);
    vlSelf->sum_sync_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 14868572438578125462ull);
    vlSelf->dut_wrapper__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3536402401954711812ull);
    vlSelf->dut_wrapper__DOT__rst_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8925775880582843353ull);
    vlSelf->dut_wrapper__DOT__valid_in_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10656070322674663782ull);
    vlSelf->dut_wrapper__DOT__a_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2967103509417321593ull);
    vlSelf->dut_wrapper__DOT__b_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7187813777313336687ull);
    vlSelf->dut_wrapper__DOT__sum_async_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4447816995574414906ull);
    vlSelf->dut_wrapper__DOT__sum_sync_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16858984133756452635ull);
    vlSelf->dut_wrapper__DOT__rst_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6685737235310069050ull);
    vlSelf->dut_wrapper__DOT__valid_in_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2122228504036994880ull);
    vlSelf->dut_wrapper__DOT__a_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7745525863563957270ull);
    vlSelf->dut_wrapper__DOT__b_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 968077228628810967ull);
    vlSelf->dut_wrapper__DOT__sum_async_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1589462305852732070ull);
    vlSelf->dut_wrapper__DOT__sum_sync_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15932329327683875596ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1252145904740478752ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__rst_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8532304155207412199ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__valid_in_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8880288997654542188ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__a_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 334404132534786542ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__b_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17813273614150613355ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__sum_async_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1168120071650014427ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__sum_sync_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5896564471526834919ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__rst_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3991722611205078675ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__valid_in_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12449620037963432061ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__a_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3811316754873862312ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__b_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16689288968817856516ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__sum_async_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2654144357836965723ull);
    vlSelf->dut_wrapper__DOT____Vtogcov__sum_sync_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1628884511679174852ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15055336145887087802ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__rst_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17399367152418605979ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__valid_in_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10043745046940641794ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__a_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13799493019984524778ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__b_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14063967389293049644ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__sum_async_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 8962765416475740693ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__sum_sync_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 7319791233713328905ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__rst_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18142850103557063823ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__valid_in_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6524255923267766359ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__a_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14756334780984242894ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__b_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4648230668488965712ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__sum_async_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11017299782061107232ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT__sum_sync_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 272829303270534202ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11897599002834846149ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1534700726628292736ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_A = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11764640743485166964ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6227375084017498735ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_A = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11759301410120043400ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 14699948790290034301ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4198951329138267373ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__rst_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10147059956897416735ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__valid_in_B = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13359340555443256763ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__a_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2782244531259668572ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__b_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4741626158586139203ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_async_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1538641705372044893ull);
    vlSelf->dut_wrapper__DOT__u_top_level__DOT____Vtogcov__sum_sync_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16245065681423078009ull);
    vlSelf->__Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_A = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6162818210136074203ull);
    vlSelf->__Vdly__dut_wrapper__DOT__u_top_level__DOT__sum_sync_B = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 14118210931385957819ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11755816861650229701ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__a_A__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 851296444277988107ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__a_B__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1593755487383325626ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__b_A__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6498999267290321023ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__b_B__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6488824822216426173ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__rst_A__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15006373960758952472ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__rst_B__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4048659846719568706ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__sum_async_A__0 = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2045601589774165884ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__sum_async_B__0 = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15957954308461100965ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__sum_sync_A__0 = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 931621043972357500ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__sum_sync_B__0 = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 3212220694414948354ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__valid_in_A__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13345067550421072074ull);
    vlSelf->__Vtrigprevexpr___TOP__dut_wrapper__DOT__u_top_level__DOT__valid_in_B__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16369785440165580793ull);
    vlSelf->__VactDidInit = 0;
}
