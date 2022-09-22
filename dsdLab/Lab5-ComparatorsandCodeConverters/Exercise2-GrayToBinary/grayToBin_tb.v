`timescale 1ns/1ns
`include "grayToBin.v"

module grayToBin_tb();
reg [(3):0] g;
wire [(3):0] b;

grayToBin gtb(g,b);
initial 
begin
    $dumpfile("grayToBin_tb.vcd");
    $dumpvars(0,grayToBin_tb);

    g = 4'b0011; #20; //desired output is 0010
    g = 4'b0110; #20; //desired output is 0100

    $display("Test Complete");    
end
endmodule