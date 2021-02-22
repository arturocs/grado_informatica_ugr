var scene = document.querySelector('a-scene')
var mensaje = "Encuentra"
var objetivo = document.createElement('a-box');
objetivo.setAttribute("visible", "false")
switch (Math.floor((Math.random() * 4) + 1)) {
	case 1:
		mensaje += " a Superman"
		objetivo.setAttribute("position", "8.3 4.6 -1.8")
		break
	case 2:
		mensaje += " a un monstruo"
		objetivo.setAttribute("position", "4.6 2.53 7.6")
		break
	case 3:
		mensaje += " a Homer Simpson"
		objetivo.setAttribute("position", "7.35 0.024 4.93")
		objetivo.setAttribute("height", "2")

		break
	case 4:
		mensaje += " a Wally"
		objetivo.setAttribute("position", "6.25 1.07 6.45")
		objetivo.setAttribute("scale", "0.5 0.5 0.5")

		break

}
scene.appendChild(objetivo);
var skybox = document.querySelector("#skybox")
var skybox2 = document.querySelector("#skybox2")
var txt = document.querySelector("#txt")
txt.setAttribute("value", mensaje)
var texto = setInterval(function () {
	txt.setAttribute("visible", "false")
	skybox.setAttribute("visible", "false")
	skybox2.setAttribute("visible", "true")
	clearInterval(texto)
}, 2500);
objetivo.addEventListener('click', function (evt) {
	var t1 = setInterval(function () {

		var skybox = document.querySelector("#skybox")
		var skybox2 = document.querySelector("#skybox2")
		var txt = document.querySelector("#txt")

		skybox.setAttribute("visible", "true")
		skybox2.setAttribute("visible", "false")
		txt.setAttribute("value", " Has ganado")
		txt.setAttribute("visible", "true")
		clearInterval(t1)
	}, 300)
	var t2 = setInterval(function () {
		window.location.href = "ordenar.html"
		clearInterval(t2)
	}, 2000);
});