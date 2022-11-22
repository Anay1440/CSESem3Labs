`timescale 1ns/1ns
`include "johnsonCounter.v"

module johnsonCounter_tb();
reg clk,reset;
wire [4:0] Q;

johnsonCounter johnsonCounterq(clk,reset,Q);
always #10 clk = ~clk;
initial
begin
    $dumpfile("johnsonCounter_tb.vcd");
    $dumpvars(0,johnsonCounter_tb);
    clk = 0;
    #220 $finish;
end
initial
begin
    reset = 1; #20;
    reset = 0; #200;
    $display("Test complete");
end
endmodule