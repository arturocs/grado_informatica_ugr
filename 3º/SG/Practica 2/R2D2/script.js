
/// Several functions, including the main


keys = { 37:false, 38:false, 39:false, 40:false }

/// The scene graph
scene = null;

/// The GUI information
GUIcontrols = null;

/// The object for the statistics
stats = null;

/// A boolean to know if the left button of the mouse is down
mouseDown = false;

/// The current mode of the application
applicationMode = TheScene.NO_ACTION;

/// It creates the GUI and, optionally, adds statistic information
/**
 * @param withStats - A boolean to show the statictics or not
 */
function createGUI(withStats) {
	GUIcontrols = new function () {
		this.axis = true;
		this.lightIntensity = 0.5;
		this.rotation = 6;
		this.distance = 10;
		this.height = 10;
		this.extension = 0;
		this.rotationCa = 80
		this.rotationCu = 0
		this.dificultad = 10
		this.shadows=false
		this.frameskip=false

		this.addBox = function () {
			setMessage("Añadir cajas clicando en el suelo");
			applicationMode = TheScene.ADDING_BOXES;
		};
		this.moveBox = function () {
			setMessage("Mover y rotar cajas clicando en ellas");
			applicationMode = TheScene.MOVING_BOXES;
		};
		this.takeBox = false;
	}

	var gui = new dat.GUI();

	var robot = gui.addFolder('Robot');

	robot.add(GUIcontrols, 'extension', 0, 20).name('Extension');
	robot.add(GUIcontrols, 'rotationCa', 0, 160).name('Rotar Cabeza');
	robot.add(GUIcontrols, 'rotationCu', -45, 30).name('Rotar Cuerpo');
	robot.add(GUIcontrols, 'dificultad', 1, 2000).name('dificultad');

	var axisLights = gui.addFolder('Renderizado');
	axisLights.add(GUIcontrols, 'axis').name('Axis on/off :');
	  axisLights.add(GUIcontrols, 'shadows').name('Sombras :');
	  axisLights.add(GUIcontrols, 'frameskip').name('Frameskip :');
	axisLights.add(GUIcontrols, 'lightIntensity', 0, 1.0).name('Light intensity :');

	if (withStats)
		stats = initStats();
}

/// It adds statistics information to a previously created Div
/**
 * @return The statistics object
 */
function initStats() {

	var stats = new Stats();

	stats.setMode(0); // 0: fps, 1: ms

	// Align top-left
	stats.domElement.style.position = 'absolute';
	stats.domElement.style.left = '0px';
	stats.domElement.style.top = '0px';

	$("#Stats-output").append(stats.domElement);

	return stats;
}

/// It shows a feed-back message for the user
/**
 * @param str - The message
 */
function setMessage(str) {
	document.getElementById("Messages").innerHTML = "<h2>" + str + "</h2>";
}


function fuera(pos) {
	//console.log(pos)
	return (pos.x > 150 || pos.x < -150 || pos.z > 150 || pos.z < -150)
}

function teclasDown(event){
    var keyCode = event.keyCode;

    switch(keyCode) {
        case 37:
            keys[37]=true
            break;
        case 38:
            keys[38]=true
            break;
        case 39:
            keys[39]=true
            break;
        case 40:
            keys[40]=true
            break;    
        default:
            break;
    } 
    
    //console.log(keys)    
}

function teclasUp(event){
    var keyCode = event.which;
    switch(keyCode) {
        case 37:
            keys[37]=false
            break;
        case 38:
            keys[38]=false
            break;
        case 39:
            keys[39]=false
            break;
        case 40:
            keys[40]=false
            break;    
        default:
            break;
    } 
   // console.log(keys)   
}

function controlarRobot() {
    
	if (keys[37]) {
		scene.r2d2.rotateY(5 * 60/scene.fps * Math.PI / 180)
	}
	if (keys[38]) {
		scene.r2d2.translateX(60/scene.fps)
		scene.r2d2.vida -= 1
		setMessage("Vida: " + scene.r2d2.vida + " Puntos: " + scene.r2d2.puntos);
		if (fuera(scene.r2d2.position)) {
			alert("HAS PERDIDO\n" + scene.r2d2.puntos + " puntos")
			scene.reset()
		}
	} 
	if (keys[39]) {
		scene.r2d2.rotateY(-5 * 60/scene.fps * Math.PI / 180)
	} 
	if (keys[40]) {
		scene.r2d2.translateX(-60/scene.fps)
		scene.r2d2.vida -= 1
		setMessage("Vida: " + scene.r2d2.vida + " Puntos: " + scene.r2d2.puntos);
		if (fuera(scene.r2d2.position)) {
			alert("HAS PERDIDO\n" + this.r2d2.puntos + " puntos")
			scene.reset()
		}
	}
}


function pausaYvista(event) {
	var keyCode = event.which;
	if (keyCode == 32) {
		alert("PAUSA")
	}
	else if (keyCode == 86) {
		scene.r2d2.fp = !scene.r2d2.fp
		onWindowResize()
		if(scene.r2d2.fp){
      scene.background.visible=false
			scene.lifebar.visible=false
			scene.lifebarfp.visible=true
      scene.backgroundfp.visible=true
		}
		else{
			scene.lifebar.visible=true
			scene.lifebarfp.visible=false
      scene.backgroundfp.visible=false
      scene.background.visible=true
		}
	}
}

/// It processes the window size changes

function onWindowResize() {
	scene.setCameraAspect(window.innerWidth / window.innerHeight);
	renderer.setSize(window.innerWidth, window.innerHeight);
}

/// It creates and configures the WebGL renderer
/**
 * @return The renderer
 */
function createRenderer() {
	var renderer = new THREE.WebGLRenderer();
	renderer.setClearColor(new THREE.Color(0xEEEEEE), 1.0);
	renderer.setSize(window.innerWidth, window.innerHeight);
	renderer.shadowMap.enabled = true;
	return renderer;
}

/// It renders every frame
function render() {
	requestAnimationFrame(render);

	stats.update();
	//scene.getCameraControls().update();
	scene.animate(GUIcontrols);

	renderer.render(scene, scene.getCamera(scene.r2d2.fp));
}

/// The main function
window.onload = function () {
	// create a render and set the size
	renderer = createRenderer();
	// add the output of the renderer to the html element
	$("#WebGL-output").append(renderer.domElement);
	// liseners
	window.addEventListener("resize", onWindowResize);
	window.addEventListener("keydown", pausaYvista, false);
    window.addEventListener("keypress", teclasDown, false);
    window.addEventListener("keyup", teclasUp, false);
	// create a scene, that will hold all our elements such as objects, cameras and lights.
	scene = new TheScene(renderer.domElement);

	createGUI(true);

	render();
}

