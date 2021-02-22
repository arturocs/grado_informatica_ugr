
class R2D2 extends THREE.Object3D {

	constructor(parameters) {
		super();

		//this.material = (parameters.material === undefined ? new THREE.MeshPhongMaterial({ color: 0xd4af37, specular: 0xfbf804, shininess: 70 }) : parameters.material);
		var loader = new THREE.TextureLoader();
		this.textura = loader.load("imgs/bueno.png")
		//this.spotLight 
		this.fps=0

		this.robot = new THREE.Mesh()

		this.camera=this.createCamera()

		this.pie = this.crearPie()
		this.femur = this.crearFemur()
		this.hombro = this.crearHombro()

		this.pie2 = this.crearPie()
		this.femur2 = this.crearFemur()
		this.hombro2 = this.crearHombro()

		this.cuerpo = this.crearCuerpo()

		this.ojo = this.crearOjo()
		this.ojo.translateZ(4).translateY(0.5)
		this.ojo.rotation.x = Math.PI / 2;

		this.cabeza = this.crearCabeza()
		this.cabeza.add(this.ojo)
		this.cabeza.add(this.camera)
		//this.cabeza.translateX(25)
		this.cuerpo.add(this.cabeza.translateY(3.75))
		this.cuerpo.translateZ(-4).translateY(-2)

		this.hombro.add(this.cuerpo)

		this.pie.add(this.femur)
		this.pie.add(this.hombro)

		this.pie2.add(this.femur2)
		this.pie2.add(this.hombro2)

		this.robot.add(this.pie.translateZ(4))
		this.robot.add(this.pie2.translateZ(-4))

		this.add(this.robot)

		this.vida = 100
		this.puntos = 0

		//console.log("hola")
	}

	// Private methods

	crearPie() {
		var loader = new THREE.TextureLoader();
		var textura = loader.load("imgs/madera.png")

		var pie = new THREE.Mesh(new THREE.CylinderGeometry(1, 2, 1, 16), new THREE.MeshPhongMaterial({ map: textura } ));
		pie.translateY(0.5)//poner sobre el origen
		return pie
	}

	crearFemur() {
		var loader = new THREE.TextureLoader();
		var textura = loader.load("imgs/madera.png")
		var femur = new THREE.Mesh(new THREE.CylinderGeometry(1, 1, 1, 16), new THREE.MeshPhongMaterial({ map: textura }));
		return femur
	}

	crearHombro() {
		var loader = new THREE.TextureLoader();
		var textura = loader.load("imgs/madera.png")
		var hombro = new THREE.Mesh(new THREE.CylinderGeometry(1, 1, 1, 16), new THREE.MeshPhongMaterial({ map: textura }));
		return hombro
	}

	crearCabeza() {
		var loader = new THREE.TextureLoader();
		var textura = loader.load("imgs/madera.png")
		var cabeza = new THREE.Mesh(new THREE.SphereGeometry(4, 32, 32), new THREE.MeshPhongMaterial({ map: textura }));
		this.luces(cabeza)
		return cabeza
	}
	crearOjo() {
		var loader = new THREE.TextureLoader();
		var textura = loader.load("imgs/ojo.png")
		var ojo = new THREE.Mesh(new THREE.CylinderGeometry(1, 1, 1, 16), new THREE.MeshPhongMaterial({ map: textura }));
		return ojo
	}
	crearCuerpo() {
		var loader = new THREE.TextureLoader();
		var textura = loader.load("imgs/madera.png")
		var cuerpo = new THREE.Mesh(new THREE.CylinderGeometry(4.1, 4.1, 7.5, 16), new THREE.MeshPhongMaterial({ map: textura }));
		return cuerpo
	}

	extendPata(tam) {

		this.femur.scale.set(0.8, 7.5 * (tam + 100) / 100, 0.8);
		this.femur.position.y = (7.5 * (tam + 100) / 100) / 2
		this.hombro.position.y = (7.5 * (tam + 100) / 100)

		this.femur2.scale.set(0.8, 7.5 * (tam + 100) / 100, 0.8);
		this.femur2.position.y = (7.5 * (tam + 100) / 100) / 2
		this.hombro2.position.y = (7.5 * (tam + 100) / 100)
	}

	rotarCabeza(r) {
		this.cabeza.rotation.y = r * Math.PI / 180
	}

	rotarCuerpo(r) { 
		this.cuerpo.rotation.z = r * Math.PI / 180
	}

	createCamera() {
		var camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 1000);
		camera.position.set(0, 0, 5);
		var look = new THREE.Vector3(0, 0, 30);
		camera.lookAt(look);
		return camera
	}

	luces(obj) {
		var objetivo = new THREE.Object3D()
		objetivo.position.set(0, -0.5, 1)

		this.spotLight = new THREE.SpotLight(0xd442f4);
		this.spotLight.position.set(0, 0, 0)
		this.spotLight.angle = 30 * Math.PI / 180
		this.spotLight.target = objetivo
		//this.spotLight.castShadow = true
		this.spotLight.add(objetivo)

		obj.add(this.spotLight);
	}

}

// class variables
R2D2.WORLD = 0;
R2D2.LOCAL = 1;
