
/// The Model Facade class. The root node of the graph.
/**
 * @param renderer - The renderer to visualize the scene
 */
TheScene = function (renderer) {
  THREE.Scene.call (this);
  
  // class variables
  
  // Private attributes
  
  var ambientLight = null;
  var directionalLight = null;
  var camera = null;
  var trackballControls = null;
  var model = null;
  
  var gouraudShaderMat = null;
  var phongShaderMat = null;
  var textureShaderMat = null;
  var shaderTextura = null;
  var displacementShaderMat = null;
  
  var lambertMat = null;
  
  // Initializer
  var init = function (self, renderer) {
    createLights (self);
    createCamera (self, renderer);
    var material = goldMat();
    gouraudShaderMat = createGouraudMat(material);
    model = new THREE.Mesh(new THREE.SphereBufferGeometry(10,6,6),gouraudShaderMat);
    displacementShaderMat = createDisplacementMat(material);
    phongShaderMat = createPhongMat(material);
    var deffered = [];
    deffered.push (createTextureMat());
    $.when.apply (this, deffered).done (function () {
        textureShaderMat = shaderTextura;
    });
    self.add (model);
  }
  
  // Private methods
  
  var goldMat = function () {
    var uniforms = {
       ambient   : {type: "c", value: new THREE.Color ("rgb(20%, 20%, 20%)")},
       diffuse   : {type: "c", value: new THREE.Color ("rgb(49%, 34%,  0%)")},
       specular  : {type: "c", value: new THREE.Color ("rgb(89%, 79%,  0%)")},
       shininess : {type: "f", value: 17.0}
    };
    return uniforms;    
  }
  
  var createGouraudMat = function (aMat) {
    var shaderMat = new THREE.ShaderMaterial ({
      uniforms : THREE.UniformsUtils.merge ([
            THREE.UniformsLib['ambient'], THREE.UniformsLib['lights'], aMat
        ]),
      vertexShader: document.getElementById ('vertexS-gouraud').textContent,
      fragmentShader: document.getElementById ('fragmentS-gouraud').textContent,
      lights : true
    });
    return shaderMat;
  }
  
  var createPhongMat = function (aMat) {
    var shaderMat = new THREE.ShaderMaterial ({
      uniforms : THREE.UniformsUtils.merge ([
            THREE.UniformsLib['ambient'], THREE.UniformsLib['lights'], aMat
        ]),
      vertexShader: document.getElementById ('vertexS-phong').textContent,
      fragmentShader: document.getElementById ('fragmentS-phong').textContent,
      lights : true
    });
    return shaderMat;
  }
  
  var createTextureMat = function () {
    var d = $.Deferred();
    var loader = new THREE.TextureLoader();
    loader.load ('imgs/ladrillo.jpg',
        function (imagen) {
          shaderTextura = new THREE.ShaderMaterial ({
            uniforms : {u_texture : {type: "t", value: imagen}},
            vertexShader: document.getElementById ('vertexS-texture').textContent,
            fragmentShader: document.getElementById ('fragmentS-texture').textContent
          });
          d.resolve();
        }
    );
    return d.promise();
  }
  
  var createDisplacementMat = function (aMat) {
    var nVertices = model.geometry.attributes.position.count;
    var displacement = new Float32Array (nVertices);
    for (var v = 0; v < nVertices; v++) {
        displacement[v] = Math.random();
    }
    model.geometry.addAttribute('displacement', new THREE.BufferAttribute (displacement,1));
    var shaderMat = new THREE.ShaderMaterial ({
      uniforms : THREE.UniformsUtils.merge ([
            THREE.UniformsLib['ambient'], THREE.UniformsLib['lights'], 
            aMat,
            {
                amplitude : {type : 'f', value : 5.0 }
            }
        ]),
      vertexShader: document.getElementById ('vertexS-phongDisplacement').textContent,
      fragmentShader: document.getElementById ('fragmentS-phong').textContent,
      wireframe : true,
      lights : true
    });
    return shaderMat;
  }
  
  /// It creates the camera and adds it to the graph
  /**
   * @param self - Root node of the graph
   * @param renderer - The renderer associated with the camera
   */
  var createCamera = function (self, renderer) {
    camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 1000);
    camera.position.set (20, 8, 20);
    var look = new THREE.Vector3 (0,0,0);
    camera.lookAt(look);

    trackballControls = new THREE.TrackballControls (camera, renderer);
    trackballControls.rotateSpeed = 5;
    trackballControls.zoomSpeed = -2;
    trackballControls.panSpeed = 0.5;
    trackballControls.target = look;
    
    self.add(camera);
  }
  
  /// It creates lights and adds them to the graph
  /**
   * @param self - Root node of the graph
   */
  var createLights = function (self) {
    // add subtle ambient lighting
    ambientLight = new THREE.AmbientLight(0xffffff, 1.0);
    self.add (ambientLight);
    
    // add spotlight for the shadows
    directionalLight = new THREE.DirectionalLight( 0xffffff );
    directionalLight.position.set( 60, 60, 40 );
    self.add (directionalLight);
  }
  
  // Public methods

  /// It sets the crane position according to the GUI
  /**
   * @controls - The GUI information
   */
  this.animate = function () {
    model.rotation.y += 0.02;
  }
  
  this.setGouraud = function () {
    model.material = gouraudShaderMat;
  }
  
  this.setPhong = function () {
    model.material = phongShaderMat;
  }
  
  this.setTexture = function() {
    model.material = textureShaderMat;    
  }
  
  this.setDesplazamiento = function() {
    model.material = displacementShaderMat;   
//         model.material = gouraudShaderMat;

  }
  
  /// It returns the camera
  /**
   * @return The camera
   */
  this.getCamera = function () {
    return camera;
  }
  
  /// It returns the camera controls
  /**
   * @return The camera controls
   */
  this.getCameraControls = function () {
    return trackballControls;
  }
  
  /// It updates the aspect ratio of the camera
  /**
   * @param anAspectRatio - The new aspect ratio for the camera
   */
  this.setCameraAspect = function (anAspectRatio) {
    camera.aspect = anAspectRatio;
    camera.updateProjectionMatrix();
  }
  
  // constructor
  init (this, renderer);
}

TheScene.prototype = Object.create (THREE.Scene.prototype);
TheScene.prototype.constructor = TheScene;

