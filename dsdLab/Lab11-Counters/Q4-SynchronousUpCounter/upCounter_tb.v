`timescale 1ns/1ns
`include "upCounter.v"

module upCounter_tb();
reg clk,reset;
wire [0:3] Q;

upCounter upCounterq(clk,reset,Q);
always #10 clk = ~clk;
initial
begin
    $dumpfile("upCounter_tb.vcd");
    $dumpvars(0,upCounter_tb);
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