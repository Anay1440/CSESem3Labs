`timescale 1ns/1ns
`include "threeInpMajority.v"

module threeInpMajority_tb();
reg [2:0] w;
wire f;

threeInpMajority q(w,f);
initial
begin 

    $dumpfile("threeInpMajority_tb.vcd");
    $dumpvars(0,threeInpMajority_tb);

    w = 3'b000; #20;
    w = 3'b001; #20;
    w = 3'b010; #20;
    w = 3'b011; #20;
    w = 3'b100; #20;
    w = 3'b101; #20;
    w = 3'b110; #20;
    w = 3'b111; #20;

    $display("Test Complete");

end
endmodule