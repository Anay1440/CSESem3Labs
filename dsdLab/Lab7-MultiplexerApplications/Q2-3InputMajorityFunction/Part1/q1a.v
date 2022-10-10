module q1a(w,f);
    input [2:0] w;
    output f;

    MUX2to1 stage0(w[1:0],w[2],f);

endmodule

module MUX2to1(w,s,f);
    input [1:0] w;
    input s;
    output f;
    reg f;
    wire t1,t2;
    assign t1 = w[0] & w[1];
    assign t2 = w[0] & ~w[1];

    always @(w or s)
    begin 
        f = t2;
        if(s == 0)
            f = t1;
    end
endmodule