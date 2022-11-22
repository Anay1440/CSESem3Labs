`timescale 1ns/1ns
`include "upDownCounter.v"

module upDownCounter_tb();
reg up,down,clk,reset;
wire [0:3] Q;

upDownCounter upDownCounterq(up,down,clk,reset,Q);
always #10 clk = ~clk;
initial
begin
    $dumpfile("upDownCounter_tb.vcd");
    $dumpvars(0,upDownCounter_tb);
    clk = 0;
    #100 $finish;
end
initial
begin
    up = 0; down = 0; reset = 1; #20;
    up = 1; down = 0; reset = 0; #20;
    up = 1; down = 0; reset = 0; #20;
    up = 0; down = 1; reset = 0; #20;
    up = 1; down = 0; reset = 0; #20;

    $display("Test complete");
end
endmodule