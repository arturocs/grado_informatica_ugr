function shuffle(array) {
	var currentIndex = array.length,
		temporaryValue, randomIndex;
	while (0 !== currentIndex) {
		randomIndex = Math.floor(Math.random() * currentIndex);
		currentIndex -= 1;
		temporaryValue = array[currentIndex];
		array[currentIndex] = array[randomIndex];
		array[randomIndex] = temporaryValue;
	}
	return array;
}

function mal() {
	var t1 = setInterval(function () {
		var skybox = document.querySelector("#skybox")
		var skybox2 = document.querySelector("#skybox2")
		var modelos = document.querySelector("#modelos")
		var txt = document.querySelector("#txt")
		modelos.setAttribute("visible", "false")
		skybox.setAttribute("visible", "true")
		skybox2.setAttribute("visible", "false")
		txt.setAttribute("value", " Has perdido")
		txt.setAttribute("visible", "true")
		clearInterval(t1)
	}, 1500)
	var t2 = setInterval(function () {
		window.location.href = "esquivar.html"
		clearInterval(t2)
	}, 3000);
}

var arr = ["0 -0.5 -6", "0 3 -6", "-3 -0.5 -6", "-3 3 -6", "3 3 -6", "3 -0.5 -6"]
arr = shuffle(arr)
var num_obj = []
num_obj[0] = document.querySelector("#n1")
for (i = 5; i >= 0; i--) {
	num_obj[i] = document.querySelector("#n" + i)
	num_obj[i].setAttribute("position", arr[i])
}

var skybox = document.querySelector("#skybox")
var skybox2 = document.querySelector("#skybox2")
var txt = document.querySelector("#txt")
var ordenados = []
var texto = setInterval(function () {

	txt.setAttribute("visible", "false")
	skybox.setAttribute("visible", "false")
	skybox2.setAttribute("visible", "true")
	var modelos = document.querySelector("#modelos")
	modelos.setAttribute("visible", "true")
	clearInterval(texto)
}, 2500);

num_obj[0].addEventListener('click', function (evt) {
	ordenados.push(0)
	if (ordenados.length == 1) {
		console.log("bien")
	} else {
		mal()
	}
});
num_obj[1].addEventListener('click', function (evt) {
	ordenados.push(1)
	if (ordenados.length > 1) {
		if (ordenados[ordenados.length - 2] == ordenados[ordenados.length - 1] - 1) {
			console.log("bien")
		} else {
			console.log(ordenados[ordenados.length - 2] + " " + ordenados[ordenados.length - 1])
			mal()
		}
	} else {
		mal()
	}

});
num_obj[2].addEventListener('click', function (evt) {
	ordenados.push(2)
	if (ordenados.length > 1) {
		if (ordenados[ordenados.length - 2] == ordenados[ordenados.length - 1] - 1) {
			console.log("bien")
		} else {
			mal()
		}
	} else {
		mal()
	}

});
num_obj[3].addEventListener('click', function (evt) {
	ordenados.push(3)
	if (ordenados.length > 1) {
		if (ordenados[ordenados.length - 2] == ordenados[ordenados.length - 1] - 1) {
			console.log("bien")
		} else {
			mal()
		}
	} else {
		mal()
	}

});
num_obj[4].addEventListener('click', function (evt) {
	ordenados.push(4)
	if (ordenados.length > 1) {
		if (ordenados[ordenados.length - 2] == ordenados[ordenados.length - 1] - 1) {
			console.log("bien")
		} else {
			mal()
		}
	} else {
		mal()
	}

});
num_obj[5].addEventListener('click', function (evt) {
	ordenados.push(5)
	if (ordenados.length > 1) {
		if (ordenados[ordenados.length - 2] == ordenados[ordenados.length - 1] - 1) {
			var t1 = setInterval(function () {
				var skybox = document.querySelector("#skybox")
				var skybox2 = document.querySelector("#skybox2")
				var txt = document.querySelector("#txt")
				var modelos = document.querySelector("#modelos")
				modelos.setAttribute("visible", "false")
				skybox.setAttribute("visible", "true")
				skybox2.setAttribute("visible", "false")
				txt.setAttribute("value", " Has ganado")
				txt.setAttribute("visible", "true")
				clearInterval(t1)
			}, 1500)
			var t2 = setInterval(function () {
				window.location.href = "esquivar.html"
				clearInterval(t2)
			}, 3000);
		} else {
			mal()
		}
	} else {
		mal()
	}
});