interface adder_if (input logic clk);
    logic        rst;
    logic        valid_in;
    logic [7:0]  a;
    logic [7:0]  b;
    logic [8:0]  sum_async;
    logic [8:0]  sum_sync;
endinterface