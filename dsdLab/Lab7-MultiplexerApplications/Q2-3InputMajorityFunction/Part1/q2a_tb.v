`timescale 1ns/1ns
`include "q2a.v"

module q2a_tb();
reg [2:0] w;
wire f;

q2a q(w,f);
initial
begin 

    $dumpfile("q2a_tb.vcd");
    $dumpvars(0,q2a_tb);

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