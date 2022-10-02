`timescale 1ns/1ns
`include "fiveBComp.v"

module fiveBComp_tb();
reg [4:0] x,y;
wire gt,eq,lt;

fiveBComp fiveBComp(x,y,gt,eq,lt);
initial 
begin 
    $dumpfile("fiveBComp_tb.vcd");
    $dumpvars(0,fiveBComp_tb);

    x = 5'b10100; y = 5'b01100; #20;
    x = 5'b01000; y = 5'b10010; #20;
    x = 5'b11011; y = 5'b11011; #20;

    $display("Test Complete");
end
endmodule
