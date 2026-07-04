// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop___024unit.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_dut_wrapper);
    __Vhier.remove(&__Vscope_dut_wrapper, &__Vscope_dut_wrapper__u_top_level);

#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void Vtop__Syms::_traceDump() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vtop__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vtop__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
{
        // Check resources
        Verilated::stackCheck(27);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_dut_wrapper.configure(this, name(), "dut_wrapper", "dut_wrapper", "dut_wrapper", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_dut_wrapper__u_top_level.configure(this, name(), "dut_wrapper.u_top_level", "u_top_level", "top_level", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_dut_wrapper);
    __Vhier.add(&__Vscope_dut_wrapper, &__Vscope_dut_wrapper__u_top_level);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"a_A", &(TOP.a_A), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"a_B", &(TOP.a_B), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"b_A", &(TOP.b_A), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"b_B", &(TOP.b_B), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst_A", &(TOP.rst_A), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst_B", &(TOP.rst_B), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"sum_async_A", &(TOP.sum_async_A), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_TOP.varInsert(__Vfinal,"sum_async_B", &(TOP.sum_async_B), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_TOP.varInsert(__Vfinal,"sum_sync_A", &(TOP.sum_sync_A), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_TOP.varInsert(__Vfinal,"sum_sync_B", &(TOP.sum_sync_B), false, VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_TOP.varInsert(__Vfinal,"valid_in_A", &(TOP.valid_in_A), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"valid_in_B", &(TOP.valid_in_B), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"a_A", &(TOP.dut_wrapper__DOT__a_A), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"a_B", &(TOP.dut_wrapper__DOT__a_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"b_A", &(TOP.dut_wrapper__DOT__b_A), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"b_B", &(TOP.dut_wrapper__DOT__b_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"clk", &(TOP.dut_wrapper__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"rst_A", &(TOP.dut_wrapper__DOT__rst_A), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"rst_B", &(TOP.dut_wrapper__DOT__rst_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"sum_async_A", &(TOP.dut_wrapper__DOT__sum_async_A), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"sum_async_B", &(TOP.dut_wrapper__DOT__sum_async_B), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"sum_sync_A", &(TOP.dut_wrapper__DOT__sum_sync_A), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"sum_sync_B", &(TOP.dut_wrapper__DOT__sum_sync_B), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"valid_in_A", &(TOP.dut_wrapper__DOT__valid_in_A), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper.varInsert(__Vfinal,"valid_in_B", &(TOP.dut_wrapper__DOT__valid_in_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"a_A", &(TOP.dut_wrapper__DOT__u_top_level__DOT__a_A), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"a_B", &(TOP.dut_wrapper__DOT__u_top_level__DOT__a_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"b_A", &(TOP.dut_wrapper__DOT__u_top_level__DOT__b_A), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"b_B", &(TOP.dut_wrapper__DOT__u_top_level__DOT__b_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"clk", &(TOP.dut_wrapper__DOT__u_top_level__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"rst_A", &(TOP.dut_wrapper__DOT__u_top_level__DOT__rst_A), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"rst_B", &(TOP.dut_wrapper__DOT__u_top_level__DOT__rst_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"sum_async_A", &(TOP.dut_wrapper__DOT__u_top_level__DOT__sum_async_A), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"sum_async_B", &(TOP.dut_wrapper__DOT__u_top_level__DOT__sum_async_B), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"sum_sync_A", &(TOP.dut_wrapper__DOT__u_top_level__DOT__sum_sync_A), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"sum_sync_B", &(TOP.dut_wrapper__DOT__u_top_level__DOT__sum_sync_B), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,8,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"valid_in_A", &(TOP.dut_wrapper__DOT__u_top_level__DOT__valid_in_A), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_dut_wrapper__u_top_level.varInsert(__Vfinal,"valid_in_B", &(TOP.dut_wrapper__DOT__u_top_level__DOT__valid_in_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
    }
}
