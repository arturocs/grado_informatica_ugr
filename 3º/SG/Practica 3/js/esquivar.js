AFRAME.registerComponent("avanzar", {
	schema: {
		avance: {
			type: "number",
			default: 0.05
		},
		activo: {
			type: "boolean",
			default: false
		},
		cam: {
			type: "selector",
			default: '#camera'
		}
	},
	tick: function () {
		if (this.data.activo) {
			var new_x = 0;
			var new_z = 0;
			var y = this.el.getAttribute('position').y;
			var radian = -(this.data.cam.getAttribute("rotation").y) * (Math.PI / 180);
			new_z = -(new_z + (this.data.avance * Math.cos(radian)));
			new_x = new_x + (this.data.avance * Math.sin(radian));
			new_pos = new_x + " " + y + " " + (-new_z);
			var total_pos = this.el.getAttribute('position')
			var def_pos = (total_pos.x + new_x) + " " + y + " " + (total_pos.z + new_z)
			this.el.setAttribute('position', def_pos)

			if (this.el.object3D.position.z < -30 && this.el.object3D.position.distanceTo(new THREE.Vector3(0, 2.5, -30)) <
				3) {
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
				}, 500)
				var t2 = setInterval(function () {
					window.location.href = "lanzamiento.html"
					clearInterval(t2)
				}, 3000);
			}
		}
	}
});
AFRAME.registerComponent("matar", {
	schema: {
		radio: {
			type: "number"
		},
		cuerpo: {
			type: "selector",
			default: '#cuerpo'
		}
	},
	tick: function () {
		if (this.el.object3D.position.distanceTo(this.data.cuerpo.object3D.position) < this.data.radio) {
			var skybox = document.querySelector("#skybox")
			var skybox2 = document.querySelector("#skybox2")
			var txt = document.querySelector("#txt")
			var cuerpo = document.querySelector("#cuerpo")
			var modelos = document.querySelector("#modelos")
			modelos.setAttribute("visible", "false")
			skybox.setAttribute("visible", "true")
			skybox2.setAttribute("visible", "false")
			cuerpo.setAttribute("avanzar", "activo: false")
			txt.setAttribute("value", " Has perdido")
			txt.setAttribute("visible", "true")

			var t2 = setInterval(function () {
				window.location.href = "lanzamiento.html"
				clearInterval(t2)
			}, 1500);
		}
	}
})