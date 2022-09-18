`timescale 1ns/1ns
`include "bcd.v"

module bcd_tb();
reg [3:0] x,y;
reg cin;
wire [3:0] s;

bcd fbas(x,y,cin,s);
initial 
begin 
	$dumpfile("bcd_tb.vcd");
	$dumpvars(0,bcd_tb);
	
	//cin=0;x0=1;x1=1;x2=1;x3=0;y0=0;y1=0;y2=1;y3=0;#20;
	//cin=0;x0=1;x1=1;x2=1;x3=0;y0=1;y1=1;y2=1;y3=0;#20;
	x = 4'b0111; y = 4'b0100; cin = 0; #20;
	x = 4'b0110; y = 4'b0111; cin = 0; #20;
	
	
	$display("Test Complete");
	
end 
endmodule
