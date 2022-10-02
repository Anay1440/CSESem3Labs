module fiveBComp(a,b,gt,eq,lt);
    input [4:0] a,b;
    output gt,eq,lt;

    xnor(t1,a[4],b[4]);
    xnor(t2,a[3],b[3]);
    xnor(t3,a[2],b[2]);
    xnor(t4,a[1],b[1]);
    xnor(t5,a[0],b[0]);
    
    and(eq,t1,t2,t3,t4,t5);
    
    and(t6,a[4],~b[4]);
    and(t7,a[3],~b[3],t1);
    and(t8,a[2],~b[2],t1,t2);
    and(t9,a[1],~b[1],t1,t2,t3);
    and(t10,a[0],~b[0],t1,t2,t3,t4);
    
    or(gt,t6,t7,t8,t9,t10);
    
    nor(lt,eq,gt);

endmodule
