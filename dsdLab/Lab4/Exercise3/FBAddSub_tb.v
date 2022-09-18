`timescale 1ns/1ns
`include "FBAddSub.v"

module FBAddSub_tb();
reg [3:0] x , y;
reg k;
wire [3:0] s;
wire cout;

FBAddSub fbas(x,y,k,s,cout);
initial 
begin 
	$dumpfile("FBAddSub_tb.vcd");
	$dumpvars(0,FBAddSub_tb);
	
	//Addition tests: 
	
	x = 4'b1010; y = 4'b0010; k = 1'b0; #20;
	x = 4'b1001; y = 4'b0110; k = 1'b0; #20;
	
	//Subtraction tests: 
	
	x = 4'b1010; y = 4'b0010; k = 1'b1; #20;
	x = 4'b1111; y = 4'b0110; k = 1'b1; #20;
	
	$display("Test Complete");
	
end 
endmodule
