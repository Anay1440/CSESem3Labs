module exercise2(a,b,c,d,f);
	input a,b,c,d;
	output f;
	
	assign f = ((b & ~c & ~d) | (~b & d) | (c & ~b));
	
endmodule
