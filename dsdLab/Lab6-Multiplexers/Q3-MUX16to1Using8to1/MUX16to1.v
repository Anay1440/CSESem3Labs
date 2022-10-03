module MUX16to1(w,s,f);
    input [15:0] w;
    input [3:0] s;
    output f;

    wire [1:0] ft;

    MUX8to1 stage0(w[7:0],s[2:0],ft[0]);
    MUX8to1 stage1(w[15:8],s[2:0],ft[1]);
    MUX2to1 stage2(ft,s[3],f);

endmodule

module MUX8to1(w,s,f);
    input [7:0] w;
    input [2:0] s;
    output f;
    reg f;

    always @(w or s)
    case (s)
        0: f = w[0];
        1: f = w[1];
        2: f = w[2];
        3: f = w[3];
        4: f = w[4];
        5: f = w[5];
        6: f = w[6];
        7: f = w[7];         
    endcase

endmodule

module MUX2to1(w,s,f);
    input [1:0] w;
    input s;
    output f;
    reg f;

    always @(w or s)
    begin 
        f = w[1];
        if(s == 0)
            f = w[0];
    end
endmodule