module exercise1(b,c,d,f);
	input b,c,d;
	output f;
	
	assign f = ((b | c) & (d | ~b));

endmodule
