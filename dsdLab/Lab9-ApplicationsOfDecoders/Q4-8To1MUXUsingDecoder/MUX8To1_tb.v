`timescale 1ns/1ns
`include "MUX8To1.v"

module MUX8To1_tb();
reg [7:0] w;
reg [2:0] s;
wire f;

MUX8To1 MUX(w,s,f);
initial 
begin 
    $dumpfile("MUX8To1_tb.vcd");
    $dumpvars(0,MUX8To1_tb);
    w = 8'b10000011; 
    s = 3'b000;#20;
    s = 3'b111;#20;
    s = 3'b001;#20;
    s = 3'b011;#20;

    $display("Test Complete");

end
endmodule