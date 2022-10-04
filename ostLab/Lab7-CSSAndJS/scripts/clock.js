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







