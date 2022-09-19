module fiveBComp(a,b,gt,eq,lt);
    input [4:0] a,b;
    output gt,eq,lt;

    //Conditions for A>B

    //A[4] = 1 and B[4] = 0
    and(t1,a[4],~b[4]);

endmodule