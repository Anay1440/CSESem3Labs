module exercise1(a,b,c,d,f);
	input a,b,c,d;
	output f;
	
	//assign f = ((~c | ~a | b) & (~a | c | ~d) & (~b | c | d) & (d | a | ~b));
	assign f = ((~a | b | ~d) & (~a | b | ~c) & (a | ~c | d) & (~b | c | d));
	
endmodule
