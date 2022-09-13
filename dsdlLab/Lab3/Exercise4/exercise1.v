module exercise1(a,b,c,d,f);
	input a,b,c,d;
	output f;
	
	/*
	nor (dCompli,d,d);
	nor (left,a,dCompli);
	nor (right,c,dCompli);
	nor (temp,left,right);
	nor (f,temp,temp); */
	
	//left = (a ~| (d ~| d))
	//right = (c ~| (d ~| d))
	//left nor right = ((a ~| (d ~| d)) ~| (c ~| (d ~| d)))
	
	assign f = (((a ~| (d ~| d)) ~| (c ~| (d ~| d))) ~| ((a ~| (d ~| d)) ~| (c ~| (d ~| d))));
	
	//Correct answer 
	//assign f = ((~a & d) | (~c & d));
	
endmodule
