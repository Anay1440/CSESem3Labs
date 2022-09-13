module exercise1(a,b,c,d,e,f);
	input a,b,c,d,e;
	output f;
	
	
	or (h,~a,b);
	and (g,e,h);
	not (gCompli,g);
	and (t1,~c,~d,g);
	and (t2,c,d,g);
	and (t3,~c,d,gCompli);
	or (f,t1,t2,t3); 
	
	//assign f = ((~c & ~d & (e & (~a | b))) | (c & d & (e & (~a | b))) | (~c & d & (~e | (a & ~b))));
	
endmodule
