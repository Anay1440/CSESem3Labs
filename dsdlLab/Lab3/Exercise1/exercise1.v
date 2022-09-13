module exercise1(a,b,c,d,f);
	input a,b,c,d;
	output f;
	
	//assign f =  ((a ~& (b ~& b)) ~& (c ~& (d ~& d))) ~& ((a ~& (b ~& b)) ~& (c ~& (d ~& d))) ;
	
	nand (bCompli,b,b);
	nand (h,a, bCompli);
	nand (dCompli,d,d);
	nand (i,c,dCompli);
	nand (j,h,i);
	nand (f,j,j);
	
endmodule
