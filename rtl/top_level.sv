

module top_level (
    input  logic       clk,

    // Channel A
    input  logic       rst_A,
    input  logic       valid_in_A,
    input  logic [7:0] a_A,
    input  logic [7:0] b_A,
    output logic [8:0] sum_async_A,
    output logic [8:0] sum_sync_A,

    // Channel B
    input  logic       rst_B,
    input  logic       valid_in_B,
    input  logic [7:0] a_B,
    input  logic [7:0] b_B,
    output logic [8:0] sum_async_B,
    output logic [8:0] sum_sync_B
);

    // Channel A synchronous accumulator
    always_ff @(posedge clk) begin
        if (rst_A)
            sum_sync_A <= '0;
        else if (valid_in_A)
            sum_sync_A <= sum_sync_A + b_A;
    end

    assign sum_async_A = a_A + b_A;

    // Channel B synchronous accumulator
    always_ff @(posedge clk) begin
        if (rst_B)
            sum_sync_B <= '0;
        else if (valid_in_B)
            sum_sync_B <= sum_sync_B + b_B;
    end

    assign sum_async_B = a_B + b_B;

    // initial begin
    //     $display("Time | rst_A| valid_in_A | a_A | b_A |sum_async_A | sum_sync_A |rst_B | valid_in_B| a_B | b_B  | sum_async_B | sum_sync_B   ");
    //     $monitor("%9t  |  %b  |  %b        | %3d | %3d |    %3d     |   %3d      | %b   |    %b     | %3d | %3d  |    %3d      |   %3d ",
    //              $time, rst_A, valid_in_A, a_A, b_A, sum_async_A,sum_sync_A, rst_B, valid_in_B, a_B, b_B, sum_async_B, sum_sync_B);
    // end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(1, top_level.sv);
    end

endmodule


