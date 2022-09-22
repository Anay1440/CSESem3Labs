`timescale 1ns/1ns
`include "twoBMult.v"

module twoBMult_tb();
reg [1:0] x,y;
wire [3:0] m;

twoBMult fbas(x,y,m);
initial 
begin 
	$dumpfile("twoBMult_tb.vcd");
	$dumpvars(0,twoBMult_tb);
	
	//x0=0;x1=1;y0=0;y1=1;#20;
	x = 2'b11; y = 2'b10;#20;
	//x0=1;x1=1;y0=1;y1=0;#20;
	x = 2'b10; y = 2'b10; #20;
	
	$display("Test Complete");
	
end 
endmodule
