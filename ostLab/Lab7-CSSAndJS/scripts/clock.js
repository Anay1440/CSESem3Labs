function curTime() {
    const date = new Date();
    var hrs = date.getHours();
    var mins = date.getMinutes();
    var sec = date.getSeconds();

    const time = hrs + " : " + mins + " : " + sec;

    document.getElementById("clock").innerText = time;

    const t = setTimeout(function() {
        curTime()
    },500);
}

curTime()







