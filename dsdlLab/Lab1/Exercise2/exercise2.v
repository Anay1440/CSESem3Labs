module exercise2(a,b,c,d,f,g);
	input a,b,c,d;
	output f,g;
	
	assign f = ((~(a & b))^d^c);
	assign g = ~(b | c | d);
	
	/* and (e,a,b);
	not (h,e);
	or (k,c,b,d);
	not (g,k);
	xor (f,d,h,c); */
	
endmodule
