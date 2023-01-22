function curTime() {
    const date = new Date();
    var hrs = date.getHours();
    var mins = date.getMinutes();
    var sec = date.getSeconds();

    const time = hrs + " : " + mins + " : " + sec;

    var inText = "CLOCK\n\n" 

    document.getElementById("clock").innerText = inText+time;

    const t = setTimeout(function() {
        curTime()
    },500);
}

curTime()

function dialog1() {
    const date = new Date();
    var mins = date.getMinutes();
    var secs = date.getSeconds();

    var dialog = document.getElementById("dialog1");
    if ((mins == 30 || mins == 00) && (secs == 00)) {
        dialog.show();
    }
    
    document.getElementById("dialog1hide").onclick = function() {
        dialog.close();
    };

    const t = setTimeout(function() {
        dialog1()
    },500);
}

dialog1();







