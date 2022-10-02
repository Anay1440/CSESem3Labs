`timescale 1ns/1ns
`include "bcdConvert.v"

module bcdConvert_tb();
reg [3:0] x;
wire [3:0] y;

bcdConvert bcdConv(x,y);
initial 
begin 
    $dumpfile("bcdConvert_tb.vcd");
    $dumpvars(0,bcdConvert_tb);

    x = 4'b1010;#20;
    x = 4'b0110;#20;
    $display("Test Complete");
end
endmodule
