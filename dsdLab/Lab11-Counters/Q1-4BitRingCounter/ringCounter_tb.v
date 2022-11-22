`timescale 1ns/1ns
`include "ringCounter.v"

module ringCounter_tb();
reg clk,reset;
wire [0:3] Q;

ringCounter ringCounterq(clk,reset,Q);
always #10 clk = ~clk;
initial
begin
    $dumpfile("ringCounter_tb.vcd");
    $dumpvars(0,ringCounter_tb);
    clk = 0;
    #100 $finish;
end
initial
begin
    reset = 1; #20;
    reset = 0; #80;
    $display("Test complete");
end
endmodule