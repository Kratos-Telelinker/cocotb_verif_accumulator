module dut_wrapper (
    input  logic       clk,

    // Channel A – cocotb drives these
    input  logic       rst_A,
    input  logic       valid_in_A,
    input  logic [7:0] a_A,
    input  logic [7:0] b_A,

    // DUT drives these
    output logic [8:0] sum_async_A,
    output logic [8:0] sum_sync_A,

    // Channel B (if needed)
    input  logic       rst_B,
    input  logic       valid_in_B,
    input  logic [7:0] a_B,
    input  logic [7:0] b_B,
    output logic [8:0] sum_async_B,
    output logic [8:0] sum_sync_B
);

    top_level u_top_level (
        .clk(clk),

        // Channel A
        .rst_A(rst_A),
        .valid_in_A(valid_in_A),
        .a_A(a_A),
        .b_A(b_A),
        .sum_async_A(sum_async_A),
        .sum_sync_A(sum_sync_A),

        // Channel B
        .rst_B(rst_B),
        .valid_in_B(valid_in_B),
        .a_B(a_B),
        .b_B(b_B),
        .sum_async_B(sum_async_B),
        .sum_sync_B(sum_sync_B)
    );

endmodule



// module dut_wrapper (
//     input  logic       clk,

//     // Channel A – exposed directly for cocotb
//     output logic       rst_A,
//     output logic       valid_in_A,
//     output logic [7:0] a_A,
//     output logic [7:0] b_A,
//     output logic [8:0] sum_async_A,
//     output logic [8:0] sum_sync_A,

//     // Channel B – exposed directly for cocotb
//     output logic       rst_B,
//     output logic       valid_in_B,
//     output logic [7:0] a_B,
//     output logic [7:0] b_B,
//     output logic [8:0] sum_async_B,
//     output logic [8:0] sum_sync_B
// );

//     // Internal wires driven by cocotb (use these as DUT inputs)
//     logic rst_A_int;
//     logic valid_in_A_int;
//     logic [7:0] a_A_int;
//     logic [7:0] b_A_int;

//     logic rst_B_int;
//     logic valid_in_B_int;
//     logic [7:0] a_B_int;
//     logic [7:0] b_B_int;

//     // Connect exposed ports to internal wires so cocotb can drive them
//     assign rst_A       = rst_A_int;
//     assign valid_in_A  = valid_in_A_int;
//     assign a_A         = a_A_int;
//     assign b_A         = b_A_int;

//     assign rst_B       = rst_B_int;
//     assign valid_in_B  = valid_in_B_int;
//     assign a_B         = a_B_int;
//     assign b_B         = b_B_int;

//     // DUT instance
//     top_level u_top_level (
//         .clk          (clk),

//         // Channel A
//         .rst_A        (rst_A_int),
//         .valid_in_A   (valid_in_A_int),
//         .a_A          (a_A_int),
//         .b_A          (b_A_int),
//         .sum_async_A  (sum_async_A),
//         .sum_sync_A   (sum_sync_A),

//         // Channel B
//         .rst_B        (rst_B_int),
//         .valid_in_B   (valid_in_B_int),
//         .a_B          (a_B_int),
//         .b_B          (b_B_int),
//         .sum_async_B  (sum_async_B),
//         .sum_sync_B   (sum_sync_B)
//     );

// endmodule