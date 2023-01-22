`timescale 1ns/1ns
`include "binToGray.v"

module binToGray_tb();
reg [3:0] b;
wire [3:0] g;

binToGray gtb(b,g);
initial 
begin
    $dumpfile("binToGray_tb.vcd");
    $dumpvars(0,binToGray_tb);

    b = 4'b0101; #20; //desired output is 0111
    b = 4'b0110; #20; //desired output is 0101
    b = 4'b1011; #20; //desired output is 1110

    $display("Test Complete");    
end
endmodule
