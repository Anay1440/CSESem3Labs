module exercise1(a,b,c,d,f);
	input a,b,c,d;
	output f;
	
	assign f = ((c & d) | (b & ~c & ~d) | (~a & b) | (c & ~b));

endmodule
