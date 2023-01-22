const heading = document.getElementById("heading");
const rect = heading.getBoundingClientRect();
const outputPara = document.getElementById("out");
outputPara.innerHTML = "Left: " + rect.left + " Top: " + rect.top;