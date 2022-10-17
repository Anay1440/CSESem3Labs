`timescale 1ns/1ns
`include "fourTo2PrioEncoder.v"

module fourTo2PrioEncoder_tb();
reg [3:0] w;
wire [1:0] y;
wire z;

fourTo2PrioEncoder q(w,y,z);
initial
begin
    $dumpfile("fourTo2PrioEncoder_tb.vcd");
    $dumpvars(0,fourTo2PrioEncoder_tb);

    w = 4'b0000; #20;
    w = 4'b0001; #20;
    w = 4'b0010; #20;
    w = 4'b0100; #20;
    w = 4'b1000; #20;

    $display("Test Complete");

end
endmodule