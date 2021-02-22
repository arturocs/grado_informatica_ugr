AFRAME.registerComponent("movimiento", {
	schema: {
		velocidad: {
			type: "number",
			default: 0.01
		}
	},
	tick: function () {
		var z = this.el.getAttribute("position").z
		z += this.data.velocidad
		var nuevapos = new THREE.Vector3(this.el.getAttribute("position").x, this.el.getAttribute("position").y, z)
		this.el.setAttribute("position", nuevapos)
	}

})

AFRAME.registerComponent("proyectil", {
	schema: {
		t: {
			type: "number"
		},
		t_incremento: {
			type: "number",
			default: 0.0001
		},
		rozamiento: {
			type: "number",
			default: 0.001
		},
		masa: {
			type: "number",
			default: 3
		},
		v0: {
			type: "number",
			default: 15
		},
		activo: {
			type: "boolean",
			default: false
		},
		camara: {
			type: "selector",
			default: '#camera'
		},
		cuerpo: {
			type: "selector",
			default: '#cuerpo'
		},
		bola: {
			type: "selector",
			default: '#bola'
		},
		direccion: {
			type: "vec3"
		},
		posicion: {
			type: "vec3"
		},
		velocidad: {
			type: "vec3"
		},
		aceleracion: {
			type: "vec3",
			default: {
				x: 0,
				y: -9.81,
				z: 0
			}
		},


	},
	init: function () {
		var posicionGlobal = new THREE.Vector3()
		this.el.setAttribute("visible", true)
		this.data.direccion = new THREE.Vector3(
			Math.sin((Math.PI / 180) * this.data.camara.getAttribute('rotation').y) * Math.cos((Math.PI / 180) * this.data
				.camara.getAttribute('rotation').x),
			Math.sin((Math.PI / 180) * this.data.camara.getAttribute('rotation').x),
			Math.cos((Math.PI / 180) * this.data.camara.getAttribute('rotation').y) * Math.cos((Math.PI / 180) * this.data
				.camara.getAttribute('rotation').x)
		)
		this.data.posicion = posicionGlobal.setFromMatrixPosition(this.data.bola.object3D.matrixWorld);

		this.data.velocidad.x = -this.data.direccion.x * this.data.v0
		this.data.velocidad.y = Math.abs(this.data.direccion.y) * this.data.v0
		this.data.velocidad.z = -this.data.direccion.z * this.data.v0

	},
	tick: function () {
		if (this.data.activo) {
			this.data.t += this.data.t_incremento;
			this.data.velocidad.x += this.data.aceleracion.x * this.data.t
			this.data.velocidad.y += this.data.aceleracion.y * this.data.t
			this.data.velocidad.z += this.data.aceleracion.z * this.data.t

			var mod_v = Math.sqrt(Math.pow(this.data.velocidad.x, 2) + Math.pow(this.data.velocidad.y, 2) + Math.pow(this.data
				.velocidad.z, 2))

			this.data.velocidad.x -= this.data.velocidad.x * this.data.rozamiento * mod_v / this.data.masa
			this.data.velocidad.y -= this.data.velocidad.y * this.data.rozamiento * mod_v / this.data.masa
			this.data.velocidad.z -= this.data.velocidad.z * this.data.rozamiento * mod_v / this.data.masa

			this.data.posicion.x += this.data.velocidad.x * this.data.t
			this.data.posicion.y += this.data.velocidad.y * this.data.t
			this.data.posicion.z += this.data.velocidad.z * this.data.t

			if (this.data.posicion.y < 0) {
				this.data.posicion.y = 0
				this.data.aceleracion.y = 0
				this.data.rozamiento = 0.02
			}
			this.el.setAttribute('position', this.data.posicion)
		}
	}
});
AFRAME.registerComponent("canasta", {
	schema: {
		toca_canasta: {
			type: "boolean",
			default: false
		},
		bola2: {
			type: "selector",
			default: '#bola2'
		},
		area: {
			type: "vec3",
			default: {
				x: 0,
				y: 5,
				z: 20
			}
		}
	},
	init: function () {
		this.data.area = new THREE.Vector3(this.data.area.x, this.data.area.y, this.data.area.z)
	},
	tick: function () {

		if (this.data.bola2.object3D.position.distanceTo(this.data.area) > 8 && !this.data.toca_canasta) {
			if (this.data.bola2.object3D.position.z > 10) {
				if (this.data.bola2.object3D.position.distanceTo(this.el.object3D.position) <= 2.5) {
					this.el.setAttribute("color", "green")
					this.data.toca_canasta = true
					var t1 = setInterval(function () {
						var skybox = document.querySelector("#skybox")
						var skybox2 = document.querySelector("#skybox2")
						var bola2 = document.querySelector("#bola2")
						var txt = document.querySelector("#txt")
						var modelos = document.querySelector("#modelos")
						modelos.setAttribute("visible", "false")
						skybox.setAttribute("visible", "true")
						skybox2.setAttribute("visible", "false")
						txt.setAttribute("value", " Has ganado")
						txt.setAttribute("visible", "true")
						bola2.setAttribute("visible", "false")
						clearInterval(t1)
					}, 3000)
					var t2 = setInterval(function () {
						window.location.href = "buscar.html"
						clearInterval(t2)
					}, 6000);

				} else {
					this.el.setAttribute("color", "red")
					this.data.toca_canasta = true
					var t1 = setInterval(function () {
						var skybox = document.querySelector("#skybox")
						var skybox2 = document.querySelector("#skybox2")
						var bola2 = document.querySelector("#bola2")
						var txt = document.querySelector("#txt")
						var modelos = document.querySelector("#modelos")
						modelos.setAttribute("visible", "false")
						skybox.setAttribute("visible", "true")
						skybox2.setAttribute("visible", "false")
						txt.setAttribute("value", " Has perdido")
						txt.setAttribute("visible", "true")
						bola2.setAttribute("visible", "false")
						clearInterval(t1)
					}, 3000)
					var t2 = setInterval(function () {
						window.location.href = "buscar.html"
						clearInterval(t2)
					}, 6000);



				}
			}
		}
	}
})