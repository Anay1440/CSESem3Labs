`timescale 1ns/1ns
`include "q1a.v"

module q1a_tb();
reg [2:0] w;
wire f;

q1a q(w,f);
initial
begin 

    $dumpfile("q1a_tb.vcd");
    $dumpvars(0,q1a_tb);

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