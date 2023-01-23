`timescale 1ns/1ns
`include "sixBitShiftReg.v"

module sixBitShiftReg_tb();
reg inp;
reg clk;
wire o;

sixBitShiftReg fbr(inp,clk,o);
always #10 clk = ~clk;
initial
begin
    $dumpfile("sixBitShiftReg_tb.vcd");
    $dumpvars(0,sixBitShiftReg_tb);
    clk = 0;
    #280 $finish;
end
initial
begin
    inp = 1; #15;
    inp = 0; #20;
    inp = 1; #20;
    inp = 1; #20;
    inp = 0; #20;
    inp = 0; #20;

end
endmodule
