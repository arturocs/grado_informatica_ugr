
/// Several functions, including the main

/// The scene graph
scene = null;

/// The mesh
mesh = null;

/// The GUI information
GUIcontrols = null;

/// The object for the statistics
stats = null;

/// It creates the GUI and, optionally, adds statistic information
/**
 * @param withStats - A boolean to show the statictics or not
 */
function createGUI (withStats) {
  GUIcontrols = new function() {
    this.gouraud   = function () {
      setMessage ("Gouraud");
      scene.setGouraud();
    };
    this.phong   = function () {
      setMessage ("Phong");
      scene.setPhong();
    };
    this.texture   = function () {
      setMessage ("Textura");
      scene.setTexture();
    };
    this.desplazamiento = function () {
      setMessage ("Desplazamiento");
      scene.setDesplazamiento();
    };
  }
  
  var gui = new dat.GUI();
  gui.add (GUIcontrols,'gouraud');
  gui.add (GUIcontrols,'phong');
  gui.add (GUIcontrols,'texture');
  gui.add (GUIcontrols,'desplazamiento');
  
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
  
  $("#Stats-output").append( stats.domElement );
  
  return stats;
}

/// It shows a feed-back message for the user
/**
 * @param str - The message
 */
function setMessage (str) {
  document.getElementById ("Messages").innerHTML = "<h2>"+str+"</h2>";
}


/// It processes the window size changes
function onWindowResize () {
  scene.setCameraAspect (window.innerWidth / window.innerHeight);
  renderer.setSize (window.innerWidth, window.innerHeight);
}

/// It creates and configures the WebGL renderer
/**
 * @return The renderer
 */
function createRenderer () {
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
  scene.getCameraControls().update ();
  
  renderer.render(scene, scene.getCamera());
  
  scene.animate();
}

/// The main function
$(function () {
  // create a render and set the size
  renderer = createRenderer();
  // add the output of the renderer to the html element
  $("#WebGL-output").append(renderer.domElement);
  window.addEventListener ("resize", onWindowResize);
  
  // create a scene, that will hold all our elements such as objects, cameras and lights.
  scene = new TheScene (renderer.domElement);
  setMessage("Gouraud");
 
  createGUI(true);

  render();
});
 
 
 
 