var http = require("http");
var url = require("url");
var fs = require("fs");
var path = require("path");
var socketio = require("socket.io");
var mimeTypes = {
	"html": "text/html",
	"jpeg": "image/jpeg",
	"jpg": "image/jpeg",
	"png": "image/png",
	"js": "text/javascript",
	"css": "text/css",
	"swf": "application/x-shockwave-flash"
};

var httpServer = http.createServer(
	function (request, response) {
		var uri = url.parse(request.url).pathname;
		if (uri == "/") uri = "/Cliente.html";
		var fname = path.join(process.cwd(), uri);
		fs.exists(fname, function (exists) {
			if (exists) {
				fs.readFile(fname, function (err, data) {
					if (!err) {
						var extension = path.extname(fname).split(".")[1];
						var mimeType = mimeTypes[extension];
						response.writeHead(200, mimeType);
						response.write(data);
						response.end();
					} else {
						response.writeHead(200, {
							"Content-Type": "text/plain"
						});
						response.write('Error de lectura en el fichero: ' + uri);
						response.end();
					}
				});
			} else {
				console.log("Peticion invalida: " + uri);
				response.writeHead(200, {
					"Content-Type": "text/plain"
				});
				response.write('404 Not Found\n');
				response.end();
			}
		});
	}
);

var estado_persiana = 'abierta'
var estado_aire = 'encendido'
var estado_luz = 'encendida'

var temperatura = 20
var luminosidad = 10

httpServer.listen(8080);
var io = socketio.listen(httpServer);
io.sockets.on('connection', function (client) {
	console.log("recibida conexion de: " + client.request.connection.remoteAddress)

	client.on('temperatura', function (data) {
		io.sockets.emit('modificar_temp', data)
		temperatura = data
	})

	client.on('luminosidad', function (data) {
		io.sockets.emit('modificar_lum', data)
		luminosidad = data
	})

	client.emit('modificar_temp', temperatura);

	client.emit('modificar_lum', luminosidad);

	client.on('cinta_persiana', function () {
		console.log("persiana" + estado_persiana)
		if (estado_persiana === 'abierta')
			estado_persiana = 'cerrada'
		else
			estado_persiana = 'abierta'

		io.sockets.emit('set_estado_persiana', estado_persiana);
		console.log("servidor: " + estado_persiana);
	});

	client.on('boton_aire', function () {
		if (estado_aire === 'encendido')
			estado_aire = 'apagado';
		else
			estado_aire = 'encendido';
		io.sockets.emit('get_estado_aire', estado_aire);
		console.log("servidor: " + estado_aire);
	});

	client.on('boton_luz', function () {
		if (estado_luz == 'encendida')
			estado_luz = 'apagada';
		else
			estado_luz = 'encendida';

		io.sockets.emit('get_estado_luz', estado_luz);
		console.log("servidor: " + estado_luz);
	});

	client.emit('set_estado_persiana', estado_persiana);

	client.emit('get_estado_luz', estado_luz);

	client.emit('get_estado_aire', estado_aire);

	client.on('cerrar_persiana', function () {
		console.log("cerrar_persiana")
		estado_persiana='cerrada'
		io.sockets.emit('set_estado_persiana', 'cerrada');
	});

	client.on('alerta_lum', function (data) {
		console.log("alerta lum")
		io.sockets.emit('advertencia_lum', data);
	});

	client.on('alerta_temp', function (data) {
		io.sockets.emit('advertencia_temp', data);
	});

});

console.log("Servidor iniciado");
