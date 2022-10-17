`timescale 1ns/1ns
`include "fourTo16Decoder.v"

module fourTo16Decoder_tb();
reg [3:0] w;
reg En;
wire [0:15] y;

fourTo16Decoder q(w,En,y);
initial
begin
    $dumpfile("fourTo16Decoder_tb.vcd");
    $dumpvars(0,fourTo16Decoder_tb);

    w = 4'b0000; En = 1; #20;
    w = 4'b0001; En = 1; #20;
    w = 4'b1101; En = 1; #20;
    w = 4'b1111; En = 1; #20;

    $display("Test Complete");

end
endmodule