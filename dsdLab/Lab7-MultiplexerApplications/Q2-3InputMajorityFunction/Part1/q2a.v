module q2a(w,f);
    input [2:0] w;
    output f;

    MUX2to1 stage0(w[1:0],w[2],f);

endmodule

module MUX2to1(w,s,f);
    input [1:0] w;
    input s;
    output reg f;

    always @(w or s)
    begin 
        f = w[0] | w[1];
        if(s == 0)
            f = w[0] & w[1];
    end
endmodule