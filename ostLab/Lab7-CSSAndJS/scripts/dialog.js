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