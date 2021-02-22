
/// The Model Facade class. The root node of the graph.
/**
 * @param renderer - The renderer to visualize the scene
 */
class TheScene extends THREE.Scene {

	constructor(renderer) {
		super();

		// Attributes
		this.tiempo = 0
		this.ambientLight = null;
		this.spotLight = null;
		this.camera = null;
		//this.trackballControls = null;
		this.r2d2 = null;
		this.ground = null;
		this.balas = []
		this.lifebar
		this.lifebarfp
		this.background = new THREE.Mesh(new THREE.BoxGeometry(10, 0.5, 0.01), new THREE.MeshBasicMaterial({ color: 0xedeff2 }));
		this.backgroundborder = new THREE.Mesh(new THREE.BoxGeometry(10.1, 0.6, 0.01), new THREE.MeshBasicMaterial({ color: 0x3b3c3d })).translateZ(-0.001);
		this.background.add(this.backgroundborder)
		this.backgroundfp
		this.fp = false;
		this.lastlife=100
		this.frameskip=false
		this.visualLife=100

		var loader = new THREE.TextureLoader();
		var cielotex = loader.load("imgs/cielo.png");
		this.cielo = new THREE.Mesh(new THREE.SphereGeometry(300, 8, 8), new THREE.MeshBasicMaterial({ map: cielotex }));
		this.cielo.scale.set(-1,-1,-1)

		this.fps=0
		this.bucle2 = new Date

		this.createLights();
		this.createCamera(renderer);
		this.axis = new THREE.AxisHelper(25);
		this.add(this.axis);
		this.model = this.createModel();
		this.add(this.model);
		this.add(this.cielo)
/*
		for (let i = 0; i < 10; i++) {
			this.balas.push(new Bullet((Math.random() * 3) + 1, this.r2d2, Math.floor((Math.random() * 9) + 2), Math.floor((Math.random() * 300) - 150)));
			this.add(this.balas[i])
		}
*/
		setMessage("Vida: " + this.r2d2.vida + " Puntos: " + this.r2d2.puntos);

		this.lifebar = this.lifeBar(this.r2d2.vida)
		this.lifebar.position.z = -10
		this.lifebar.position.y = 3
		this.background.position.y = 3
		this.background.position.z = -10
		this.lifebarfp = this.lifebar.clone()
		this.backgroundfp = this.background.clone()
		this.lifebarfp.visible=false
		this.backgroundfp.visible=false
		this.camera.add(this.lifebar)
		this.camera.add(this.background)
		this.r2d2.camera.add(this.lifebarfp)
		this.r2d2.camera.add(this.backgroundfp)
		this.r2d2.castShadow = true

	}

	sombras(checkbox){
		this.r2d2.pie.castShadow = checkbox
		this.r2d2.pie2.castShadow = checkbox
		this.r2d2.femur.castShadow = checkbox
		this.r2d2.femur2.castShadow = checkbox
		this.r2d2.hombro.castShadow = checkbox
		this.r2d2.hombro2.castShadow = checkbox
		this.r2d2.cuerpo.castShadow = checkbox
		this.r2d2.cabeza.castShadow = checkbox
		this.r2d2.ojo.castShadow = checkbox
		this.ground.receiveShadow = checkbox
		this.spotLight.castShadow = checkbox
		//this.r2d2.spotLight.castShadow = checkbox
	}


	lifeBar(life) {
		var material = new THREE.MeshBasicMaterial({ color: 0x00ff08 })
		var lifebar = new THREE.Mesh(new THREE.BoxGeometry(1, 1, 1), material);
		return lifebar
	}

	changeLifebar(life, lifebar) {
		var l = life
		if (life > 50) {
			lifebar.material = new THREE.MeshBasicMaterial({ color: 0x00ff08 })
		} else if (life <= 50 && life > 20) {
			lifebar.material = new THREE.MeshBasicMaterial({ color: 0xff7b00 })
		}
		else if (life <= 20 && life > 0) {
			lifebar.material = new THREE.MeshBasicMaterial({ color: 0xa80000 })
		}
		else {
			l = 0
		}
		lifebar.scale.set(l / 10, 0.5, 0.01)
		lifebar.position.x=l/20 - 5
	}

	createCamera(renderer) {
		this.camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 1000);
		this.camera.position.set(-90, 30, 0);
		var look = new THREE.Vector3(1, 20, 0);
		this.camera.lookAt(look)

		this.add(this.camera);
	}

	/// It creates lights and adds them to the graph
	createLights() {
		// add subtle ambient lighting
		this.ambientLight = new THREE.AmbientLight(0xccddee, 0.5);
		this.add(this.ambientLight);

		this.spotLight = new THREE.SpotLight(0xffffff);
		this.spotLight.position.set(0, 60, 0);
		this.spotLight.castShadow = false
		this.add(this.spotLight);
	}

	/// It creates the geometric model: r2d2 and ground
	/**
	 * @return The model
	 */
	createModel() {
		var model = new THREE.Object3D()
		this.r2d2 = new R2D2({});
		model.add(this.r2d2);
		var loader = new THREE.TextureLoader();
		var textura = loader.load("imgs/musgo.jpg");
		this.ground = new THREE.Mesh (new THREE.BoxGeometry (300, 0.2, 300, 1, 1, 1),new THREE.MeshPhongMaterial({ map: textura }))
		this.ground.applyMatrix (new THREE.Matrix4().makeTranslation (0,-0.1,0));
		this.ground.receiveShadow = false;
		model.add(this.ground);
		return model;
	}



	reset() {
		this.bucle2 = new Date;
        keys = { 37:false, 38:false, 39:false, 40:false }
		this.r2d2.position.x = 0
		this.r2d2.position.z = 0
		this.r2d2.rotation.y = 0
		this.r2d2.vida = 100
		this.r2d2.puntos = 0
		this.dificultad=10
		this.r2d2.fp=false
		this.lifebar.visible=true
		this.lifebarfp.visible=false
		this.backgroundfp.visible=false
		onWindowResize()
        this.visualLife=100
        this.balas.forEach(bala => {
			this.remove(bala)
			var index = this.balas.indexOf(bala);
            this.balas.splice(index, 1);
		});
        
		setMessage("Vida: " + this.r2d2.vida + " Puntos: " + this.r2d2.puntos);
	}

    cameraMovement(){
        this.camera.position.x=this.r2d2.position.x-90
        this.camera.position.z=this.r2d2.position.z
    }
	
	smoothLife(){
		if(this.visualLife<this.r2d2.vida){
			this.visualLife++
			setMessage("Vida: " + this.visualLife + " Puntos: " + this.r2d2.puntos);
		}
		else if(this.visualLife>this.r2d2.vida){
			this.visualLife--
			setMessage("Vida: " + this.visualLife + " Puntos: " + this.r2d2.puntos);
		}
	}
	
	animate(controls) {
		if(this.tiempo % 60 == 0 && this.balas.length<=10){
			this.balas.push(new Bullet((Math.random() * 3) + 1, this.r2d2, Math.floor((Math.random() * 9) + 2), Math.floor((Math.random() * 300) - 150)));
			this.add(this.balas[this.balas.length-1])
		}
		this.tiempo+=1
		this.axis.visible = controls.axis;
		this.frameskip = controls.frameskip;
		this.spotLight.intensity = controls.lightIntensity;
		this.r2d2.extendPata(controls.extension)
		this.r2d2.rotarCabeza(controls.rotationCa)
		this.r2d2.rotarCuerpo(controls.rotationCu)
		this.ajustarDificultad(controls.dificultad)
		this.smoothLife()
		this.changeLifebar(this.visualLife, this.lifebar)
		this.changeLifebar(this.visualLife, this.lifebarfp)
        this.cameraMovement()
		controlarRobot()
		this.r2d2.fps=this.fps
		this.sombras(controls.shadows)
		if (this.r2d2.vida <= 0) {
			alert("HAS PERDIDO\n" + this.r2d2.puntos + " puntos")
			this.reset()
		}


		if(this.frameskip){
			if(this.tiempo%5==0){
				this.bucle1 = new Date;
				this.fps = 5* 1000 / ( this.bucle1 - this.bucle2);
				this.bucle2 =  this.bucle1;
			}
		}
		else{
			this.fps=60
			this.bucle2 = new Date;
		}

		//console.log(this.r2d2.position.distanceTo(new THREE.Vector3(0,0,0)))

		this.balas.forEach(bala => {
			bala.avanzar()
		});
	}

	getCamera(fp) {
		if (fp) {
			return this.r2d2.camera
		} else {
			return this.camera;
		}

	}

	ajustarDificultad(d) {
		var k = Math.floor(d)
		/*
		while (k > this.balas.length) {
			this.balas.push(new Bullet((Math.random() * 3) + 1, this.r2d2, (Math.random() * 9) + 2, (Math.random() * 300) - 150));
			this.add(this.balas[this.balas.length - 1])
		}
		while (k < this.balas.length) {
			this.remove(this.balas[this.balas.length - 1])
			this.balas.pop()
		}
		*/

		if(k > this.balas.length && this.tiempo % 60 ==0){
			this.balas.push(new Bullet((Math.random() * 3) + 1, this.r2d2, (Math.random() * 7) + 2, (Math.random() * 300) - 150));
			this.add(this.balas[this.balas.length - 1])

		}else if(k < this.balas.length){
			this.remove(this.balas[this.balas.length - 1])
			this.balas.pop()
		}

	}

	setCameraAspect(anAspectRatio) {
		this.camera.aspect = anAspectRatio;
		this.camera.updateProjectionMatrix();
	}

}


class Bullet extends THREE.Object3D {

	constructor(velocidad, objetivo, Y, Z, escena) {
		super();

		//this.escena=escena
		this.objetivo = objetivo
		this.velocidad = velocidad
		this.position.y = Y
		this.position.z = Z
		this.position.x = 150
		this.impacto = false
		this.tipo = Math.floor((Math.random() * 5) + 1);

		var loader = new THREE.TextureLoader();
		this.textura = (this.tipo === 1 ? loader.load("imgs/bueno.png") : loader.load("imgs/malo.png"))

		this.ball = new THREE.Mesh(new THREE.SphereGeometry(1, 16, 16), new THREE.MeshPhongMaterial({ map: this.textura }));
		this.ball.rotateY(Math.PI)
		this.ball.castShadow = this.objetivo.cabeza.castShadow
		this.add(this.ball)

	}

	resetBall(){
		
		this.position.x = 150
		this.position.y = (Math.random() * 6) + 2
		this.position.z = (Math.random() * 300) - 150
		this.velocidad = (Math.random() * 3) + 1
		this.impacto=false
	}

	avanzar() {
		//console.log(this.tiempo)
		this.position.x -= this.velocidad * 60/this.objetivo.fps
		//console.log(this.objetivo.fps)
		this.ball.castShadow=this.objetivo.cabeza.castShadow
		if (this.position.x <= -150) {
			this.resetBall()
		}
		if (this.objetivo.position.distanceTo(this.position) < 8 && this.impacto == false) {
			//if(this.objetivo.isIntersectionBox(this)){
			console.log("impacto")
			this.impacto=true
				if (this.tipo == 1) {
					let p = Math.floor((Math.random() * 6))
					this.objetivo.vida += (5 - p)
					if (this.objetivo.vida>100){
						this.objetivo.vida=100
					}
					this.objetivo.puntos += p
					//this.resetBall()
					setMessage("Vida: " + this.objetivo.vida + " Puntos: " + this.objetivo.puntos);
				} else {
					this.objetivo.vida -= 10
					//this.resetBall()
					setMessage("Vida: " + this.objetivo.vida + " Puntos: " + this.objetivo.puntos);
				}
			//}	
		}
	}

}	
