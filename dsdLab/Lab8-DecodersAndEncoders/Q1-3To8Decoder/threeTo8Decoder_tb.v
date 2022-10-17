`timescale 1ns/1ns
`include "threeTo8Decoder.v"

module threeTo8Decoder_tb();
reg [2:0] w;
reg En;
wire [0:7] y;

threeTo8Decoder q(w,En,y);
initial
begin
    $dumpfile("threeTo8Decoder_tb.vcd");
    $dumpvars(0,threeTo8Decoder_tb);
    En = 1;
    w = 3'b000;#20;
    w = 3'b001;#20;
    w = 3'b010;#20;
    w = 3'b011;#20;
    w = 3'b100;#20;
    w = 3'b101;#20;
    w = 3'b110;#20;
    w = 3'b111;#20;

    $display("Test Complete");

end
endmodule