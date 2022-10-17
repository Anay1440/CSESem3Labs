`timescale 1ns/1ns
`include "sixteenTo4PrioEncoder.v"

module sixteenTo4PrioEncoder_tb();
reg [15:0] w;
wire [3:0] y;
wire z;

sixteenTo4PrioEncoder q(w,y,z);
initial
begin
    $dumpfile("sixteenTo4PrioEncoder_tb.vcd");
    $dumpvars(0,sixteenTo4PrioEncoder_tb);

    w = 16'b0000000000000001; #20;
    w = 16'b1000000000000000; #20;
    w = 16'b0000000000000100; #20;
    w = 16'b0010000000000000; #20;

    $display("Test Complete");

end
endmodule