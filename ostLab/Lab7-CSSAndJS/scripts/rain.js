const canvas = document.getElementById("canvas1");
const context = canvas.getContext('2d');
const canvasHeight = canvas.height;
const canvasWidth = canvas.width;

function render() {
    context.fillStyle = "black";
    context.fillRect(0,0,canvasWidth,canvasHeight);
    context.fillStyle="rgb(121, 250, 250)";
    for(var i = 1; i < 50; i++) {
        var x = Math.round(Math.random()*canvasWidth);
        var y = Math.round(Math.random() * canvasHeight)% canvasHeight;
        context.fillRect(x,y,2,10);
    }

    const t = setTimeout(function() {
        requestAnimationFrame(render);
    },35);

    // requestAnimationFrame(render);
}

requestAnimationFrame(render);