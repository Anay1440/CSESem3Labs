module fbComp(x,y,gt,eq,lt);
    input [3:0] x,y;
    output gt,eq,lt;

    tbComp stage0(x[1:0],y[1:0],gt1,eq1,lt1);
    tbComp stage1(x[3:2],y[3:2],gt2,eq2,lt2);
    and (eq,eq1,eq2);
    assign gt = (gt1 & eq2) | (lt1 & gt2) | (eq1 & gt2);
    assign lt = (lt1 & eq2) | (eq1 & lt2) | (gt1 & lt2);

endmodule

module tbComp(x,y,gt,eq,lt);
    input [1:0] x,y;
    output gt,eq,lt;

    assign gt = (x[1] & ~y[1]) | (x[1] & x[0] & ~y[0]) | (x[0] & ~y[1] & ~y[0]);
    assign eq = (~x[1] & ~x[0] & ~y[1] & ~y[0]) | (~x[1] & x[0] & ~y[1] & y[0]) | (x[1] & x[0] & y[1] & y[0]) | (x[1] & ~x[0] & y[1] & ~y[0]);
    assign lt = (~x[1] & y[1]) | (~x[0] & y[1] & y[0]) | (~x[1] & ~x[0] & y[0]);
endmodule