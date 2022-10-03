`timescale 1ns/1ns
`include "MUX4to1.v"

module MUX4to1_tb();
reg [3:0] w;
reg [1:0] s;
wire f;

MUX4to1 MUX(w,s,f);
initial 
begin 
    $dumpfile("MUX4to1_tb.vcd");
    $dumpvars(0,MUX4to1_tb);

    w = 4'b0001; s = 2'b00; #20;
    w = 4'b0010; s = 2'b01; #20;
    w = 4'b0100; s = 2'b10; #20;
    w = 4'b0110; s = 2'b01; #20;

    $display("Test Complete");

end
endmodule