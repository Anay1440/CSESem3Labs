`timescale 1ns/1ns
`include "halfadder.v"

module halfadder_tb();
reg a,b;
wire s,c;

halfadder ha(a,b,s,c);
initial 
begin 
	$dumpfile("halfadder_tb.vcd");
	$dumpvars(0,halfadder_tb);
	
	a=0;b=0;#20;
	a=0;b=1;#20;
	a=1;b=0;#20;
	a=1;b=1;#20;
	
	$display("Test Complete");
	
end 
endmodule
