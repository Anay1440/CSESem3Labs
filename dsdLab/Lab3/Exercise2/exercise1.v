module exercise1(a,b,c,d,f);
	input a,b,c,d;
	output f;
	
	//left = (((b ~| d) ~| (b ~| c)) ~| ((b ~| d) ~| (b ~| c)))
	//right = (((a ~| c) ~| (a ~| c)) ~| (d ~| d))
	
	//left nor right = ((((b ~| d) ~| (b ~| c)) ~| ((b ~| d) ~| (b ~| c))) ~| (((a ~| c) ~| (a ~| c)) ~| (d ~| d)))
	
	assign f = (((((b ~| d) ~| (b ~| c)) ~| ((b ~| d) ~| (b ~| c))) ~| (((a ~| c) ~| (a ~| c)) ~| (d ~| d))) ~| ((((b ~| d) ~| (b ~| c)) ~| ((b ~| d) ~| (b ~| c))) ~| (((a ~| c) ~| (a ~| c)) ~| (d ~| d)))) ;
	
	/*
	nor (h,b,d);
	nor (i,b,c);
	nor (j,a,c);
	nor (jCompli,j,j);
	nor (k,h,i);
	nor (kCompli,k,k);
	nor (dCompli,d,d);
	nor (l,jCompli,dCompli);
	nor (m,kCompli,l);
	nor (f,m,m); */
	
	//Correct answer:
	//assign f = ((~b & ~d) | (~b & ~c) | (~a & ~c & ~d));

endmodule
