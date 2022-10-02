`timescale 1ns/1ns
`include "fbComp.v"

module fbComp_tb();
reg [3:0] x,y;
wire gt,eq,lt;

fbComp fbComp(x,y,gt,eq,lt);
initial 
begin 
    $dumpfile("fbComp_tb.vcd");
    $dumpvars(0,fbComp_tb);

    x = 4'b1010; y = 4'b0110; #20;
    x = 4'b0111; y = 4'b0111; #20;
    x = 4'b0001; y = 4'b0010; #20;

    $display("Test Complete");
end
endmodule
