module MUX8To1(w,s,f);
    input [7:0] w;
    input [2:0] s;
    output f;

    wire [0:7] y;

    threeTo8Decoder stage0(s,1'b1,y);

    and(t1,y[7],w[7]);
    and(t2,y[6],w[6]);
    and(t3,y[5],w[5]);
    and(t4,y[4],w[4]);
    and(t5,y[3],w[3]);
    and(t6,y[2],w[2]);
    and(t7,y[1],w[1]);
    and(t8,y[0],w[0]);

    or(f,t1,t2,t3,t4,t5,t6,t7,t8);

endmodule

module threeTo8Decoder(w,En,y);
    input [2:0] w;
    input En;
    output reg [0:7] y;

    integer k;

    always @(w or En)
        for(k = 0; k <= 7; k=k+1)
        if ((w == k) && (En == 1))
            y[k] = 1;
        else 
            y[k] = 0;

endmodule