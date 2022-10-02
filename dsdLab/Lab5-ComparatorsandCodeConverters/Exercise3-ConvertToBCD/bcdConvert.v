module bcdConvert(x,y);
	input [3:0] x;
	output [3:0] y;
	wire [3:0] y;
	assign y[0] = x[0];
	assign y[1] = x[1] ^ x[0];
	assign y[2] = ~x[2]&x[0] | x[1]&~x[2] | ~x[1]&~x[0]&x[2];
	assign y[3] = x[3]&~x[1]&~x[0] | x[3]&x[2];
endmodule
